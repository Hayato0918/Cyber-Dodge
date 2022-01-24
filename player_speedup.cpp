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

	speedup.bugincrease = false;
	speedup.bugdrawnum = 0;

	return S_OK;
}

//-----���剻����
void _SpeedUp(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	RANDOM* random = GetRandom();
	SKILL* skill = GetSkill();

	//�����_����4���o����A10s�ԃL�����̃X�s�[�h��2�{�ɂȂ�
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 24 && random[i].active == true && speedup.use == false)
		{
			player->move *= 2;
			speedup.timeflag = true;
			//-----�o�O�Q�[�W�̏㏸
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && speedup.bugincrease == false)
				{
					for (int j = i; speedup.bugdrawnum < 4; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						speedup.bugdrawnum = speedup.bugdrawnum + 1;
					}
					speedup.bugincrease = true;
				}
			}
			speedup.use = true;
		}
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

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && speedup.use == true)
		{
			if (speedup.time < speeduptime)
				player->move /= 2;
			speedup.timeflag = false;
			speedup.bugdrawnum = 0;
			speedup.bugincrease = false;
			speedup.time = 0.0f;
			speedup.use = false;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && speedup.use == true)
		{
			if (speedup.time < speeduptime)
				player->move /= 2;
			speedup.timeflag = false;
			speedup.bugdrawnum = 0;
			speedup.bugincrease = false;
			speedup.time = 0.0f;
			speedup.use = false;
		}
	}
}