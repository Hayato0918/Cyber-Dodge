//�X�L��_�p���[�_�E������ [enemy_powerdown.cpp]
#include "enemy_powerdown.h"
//�G�l�~�[.h
#include "firewall.h"
#include "slime.h"

#include "bugincrease.h"

#include "skillrandom.h"

#include "map_point.h"

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

	return S_OK;
}

//-----���剻����
void _PowerDown(void)
{
	FIREWALL* firewall = GetFireWall();
	SLIME* slime = GetSlime();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	MAP_PLAYER* map_player = GetMapPlayer();

	//�����_����4���o����A10s�ԓG�̃p���[��-50�ɂȂ�
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 4 && random[i].active == true && powerdown.use == false)
		{
			if (map_player->encount == 1)
				slime->atk = slime->atk - 50;
			if(map_player->encount == 2)
			firewall->atk = firewall->atk - 50;
			powerdown.timeflag = true;
			bug->gaugesize.x = bug->gaugesize.x + powerdown.usegauge * bug->gaugeonce;
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
}