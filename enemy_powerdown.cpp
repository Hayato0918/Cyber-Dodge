//�X�L��_�p���[�_�E������ [enemy_powerdown.cpp]
#include "enemy_powerdown.h"
//�G�l�~�[.h
#include "firewall.h"
#include "slime.h"
#include "input.h"

#include "bugincrease.h"

#include "skillrandom.h"

#include "map_point.h"
#include "map_player.h"

//-----�}�N����`
#define powerdowntime 600		//10s��

//-----�v���g�^�C�v�錾
POWERDOWN powerdown;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitPowerDown(void)
{
	powerdown.use = false;
	powerdown.timeflag = false;
	powerdown.time = 0.0f;
	powerdown.usegauge = 30;

	powerdown.bugincrease = false;
	powerdown.bugdrawnum = 0;

	return S_OK;
}

//-----���剻����
void _PowerDown(void)
{
	FIREWALL* firewall = GetFireWall();
	SLIME* slime = GetSlime();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	RANDOM* random = GetRandom();
	MAP_PLAYER* map_player = GetMapPlayer();
	SKILL* skill = GetSkill();

	//�����_����4���o����A10s�ԓG�̃p���[��-50�ɂȂ�
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 18 && random[i].active == true && powerdown.use == false)
		{
			if (map_player->encount == 1)
				slime->atk = slime->atk - 50;
			if(map_player->encount == 2)
			firewall->atk = firewall->atk - 50;
			powerdown.timeflag = true;
			//-----�o�O�Q�[�W�̏㏸
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && powerdown.bugincrease == false)
				{
					for (int j = i; powerdown.bugdrawnum < 6; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						powerdown.bugdrawnum = powerdown.bugdrawnum + 1;
					}
					powerdown.bugincrease = true;
				}
			}
			powerdown.use = true;
		}
	}
	//�X�L���g�p10s��ɂ��Ƃ̋����ɖ߂�
	if (powerdown.timeflag == true)
		powerdown.time = powerdown.time + 1.0f;
	if (powerdown.time > powerdowntime)
	{
		powerdown.timeflag = false;
		firewall->atk = firewall->atk + 50;
		powerdown.time = 0.0f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && powerdown.use == true)
		{
			if (powerdown.timeflag == true)
				firewall->atk = firewall->atk + 50;
			powerdown.use = false;
			powerdown.timeflag = false;
			powerdown.time = 0.0f;
			powerdown.usegauge = 30;

			powerdown.bugincrease = false;
			powerdown.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && powerdown.use == true)
		{
			if (powerdown.timeflag == true)
				firewall->atk = firewall->atk + 50;
			powerdown.use = false;
			powerdown.timeflag = false;
			powerdown.time = 0.0f;
			powerdown.usegauge = 30;

			powerdown.bugincrease = false;
			powerdown.bugdrawnum = 0;
		}
	}
}