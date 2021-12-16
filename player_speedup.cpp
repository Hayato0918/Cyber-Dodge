//�X�L��_�X�s�[�h�A�b�v���� [player_speedup.cpp]
#include "player_speedup.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----�}�N����`
#define speeduptime 600		//10s��

//-----�v���g�^�C�v�錾
SPEEDUP speedup;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitSpeedUp(void)
{
	speedup.use = false;
	speedup.timeflag = false;
	speedup.time = 0.0f;
	speedup.usegauge = 20;

	return S_OK;
}

//-----���剻����
void _SpeedUp(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();

	//�����_����4���o����A10s�ԃL�����̃X�s�[�h��2�{�ɂȂ�
	if (random->code == 4 && random->active == true && speedup.use == false)
	{
		player->move *= 2;
		speedup.timeflag = true;
		bug->gaugesize.x = bug->gaugesize.x + speedup.usegauge * bug->gaugeonce;
		speedup.use = true;
	}
	//�X�L���g�p10s��ɂ��Ƃ̃X�s�[�h�ɖ߂�
	if (speedup.timeflag == true)
		speedup.time = speedup.time + 1.0f;
	if (speedup.time > speeduptime)
	{
		speedup.timeflag = false;
		player->move /= 2;
		speedup.time = 0.0f;
	}
}