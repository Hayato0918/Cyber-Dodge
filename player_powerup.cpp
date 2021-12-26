//�X�L��_�p���[�A�b�v���� [player_powerup.cpp]
#include "player_powerup.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----�}�N����`
#define poweruptime 600		//10s��

//-----�v���g�^�C�v�錾
POWERUP powerup;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitPowerUp(void)
{
	powerup.use = false;
	powerup.timeflag = false;
	powerup.time = 0.0f;
	powerup.usegauge = 20;

	return S_OK;
}

//-----���剻����
void _PowerUp(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();

	//�����_����4���o����A10s�ԃL�����̃p���[��+50�ɂȂ�
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 4 && random[i].active == true && powerup.use == false)
		{
			player->atk += 50;
			powerup.timeflag = true;
			bug->gaugesize.x = bug->gaugesize.x + powerup.usegauge * bug->gaugeonce;
			powerup.use = true;
		}
	}
	//�X�L���g�p10s��ɂ��Ƃ̋����ɖ߂�
	if (powerup.timeflag == true)
		powerup.time = powerup.time + 1.0f;
	if (powerup.time > poweruptime)
	{
		powerup.timeflag = false;
		player->atk -= 50;
		powerup.time = 0.0f;
	}
}