//�o�O_���W�F�l���� [regen.cpp]
#include "regen.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
//�v���C���[.h
#include "player_hp.h"
//�G�l�~�[.h
#include "slime_hp.h"
#include "firewall_hp.h"

#include "bugincrease.h"
#include "bugrandom.h"

#include "map_player.h"

//-----�}�N����`
#define regentime 600		//10s��

//-----�v���g�^�C�v�錾
REGEN regen;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitRegen(void)
{
		regen.heal = 1.0f;
		regen.timeflag = false;
		regen.time = 0.0f;
		regen.use = true;

	return S_OK;
}

void _Regen(void)
{
	PLAYERHP* hp = GetPlayerHp();
	SLIMEHP* slimehp = GetSlimeHp();
	FIREWALLHP* firewallhp = GetFireWallHp();
	BUG* bug = GetBugIncrease();
	BUGRANDOM* bugrandom = GetBugRandom();
	MAP_PLAYER* map_player = GetMapPlayer();

	if (bugrandom->code == 4 && bug->gaugesize.x >= 10 && regen.use == true)
	{
		//player�̉�
		hp->gaugesize.x = hp->gaugesize.x + regen.heal;
		hp->pos.x = hp->pos.x - regen.heal;
		//slime�̉�
		if (map_player->encount == 1)
			slimehp->gaugesize.x = slimehp->gaugesize.x + regen.heal;
		//firewall�̉�
		if (map_player->encount == 2)
			firewallhp->gaugesize.x = firewallhp->gaugesize.x + regen.heal;


		regen.timeflag = true;
	}

	if (regen.timeflag == true)
	{
		regen.time = regen.time + 1.0f;
	}

	if (regen.time > regentime)
	{
		regen.timeflag = false;
		regen.time = 0.0f;
		regen.use = false;
	}
}

REGEN* GetRegen()
{
	return &regen;
}