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
#include "map_player.h"

//-----�}�N����`
#define venomtime 45		//10s��

//-----�v���g�^�C�v�錾
VENOM venom;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitVenom(void)
{
	venom.heal = 10.0f;
	venom.timeflag = false;
	venom.time = 0.0f;
	venom.use = false;
	venom.count = 0;

	venom.pos = D3DXVECTOR2(30.f, 310.f);
	venom.size = D3DXVECTOR2(1500.f, 450.f);
	venom.drawflag = false;

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

	if (bugrandom->code == 8 && bug->breakflag == true && venom.use == false)
	{
		venom.use = true;
		venom.drawflag = true;
		venom.timeflag = true;
	}

	if (venom.timeflag == true)
		venom.time = venom.time + 1.0f;

	if (venom.time > venomtime && venom.count < 15)
	{
		//player�̃_���[�W
		hp->gaugesize.x = hp->gaugesize.x - venom.heal;
		hp->pos.x = hp->pos.x + venom.heal;
		//slime�̃_���[�W
		if (map_player->encount == 1)
			slimehp->gaugesize.x = slimehp->gaugesize.x - venom.heal;
		//firewall�̃_���[�W
		if (map_player->encount == 3)
			firewallhp->gaugesize.x = firewallhp->gaugesize.x - venom.heal;

		venom.count = venom.count + 1;
		venom.time = 0.f;
	}

	if (bug->breakflag == false && venom.use == true)
	{
		venom.use = false;
		venom.timeflag = false;
		venom.time = 0.f;
		venom.drawflag = false;
	}
}

void DrawVenom()
{
	if(venom.drawflag == true)
	DrawSpriteLeftTop(venom.texture, venom.pos.x, venom.pos.y, venom.size.x, venom.size.y, 0.f, 0.f, 1.f, 1.f);
}

VENOM* GetVenom()
{
	return &venom;
}