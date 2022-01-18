//�o�O_���W�F�l���� [venom.cpp]
#include "venom.h"
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

#include "map_point.h"

//-----�}�N����`
#define venomtime 3600		//10s��

//-----�v���g�^�C�v�錾
VENOM venom;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitVenom(void)
{
	venom.heal = 1.0f;
	venom.timeflag = false;
	venom.time = 0.0f;
	venom.use = true;

	return S_OK;
}

void _Venom(void)
{
	PLAYERHP* hp = GetPlayerHp();
	SLIMEHP* slimehp = GetSlimeHp();
	FIREWALLHP* firewallhp = GetFireWallHp();
	BUG* bug = GetBugIncrease();
	BUGRANDOM* bugrandom = GetBugRandom();
	MAP_PLAYER* map_player = GetMapPlayer();

	if (bugrandom->code == 5 && bug->gaugesize.x >= 10 && venom.use == true)
	{
		//player�̉�
		hp->gaugesize.x = hp->gaugesize.x + venom.heal;
		hp->pos.x = hp->pos.x - venom.heal;
		//slime�̉�
		if (map_player->encount == 1)
			slimehp->gaugesize.x = slimehp->gaugesize.x - venom.heal;
		//firewall�̉�
		if (map_player->encount == 2)
			firewallhp->gaugesize.x = firewallhp->gaugesize.x - venom.heal;


		venom.timeflag = true;
	}

	if (venom.timeflag == true)
	{
		venom.time = venom.time + 1.0f;
	}

	if (venom.time > venomtime)
	{
		venom.timeflag = false;
		venom.time = 0.0f;
		venom.use = false;
	}
}

VENOM* Getvenom()
{
	return &venom;
}