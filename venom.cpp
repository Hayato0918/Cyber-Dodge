//バグ_リジェネ処理 [venom.cpp]
#include "venom.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
//プレイヤー.h
#include "player_hp.h"
//エネミー.h
#include "slime_hp.h"
#include "firewall_hp.h"

#include "bugincrease.h"
#include "bugrandom.h"

#include "map_point.h"

//-----マクロ定義
#define venomtime 3600		//10s間

//-----プロトタイプ宣言
VENOM venom;

//-----グローバル変数

//-----初期化処理
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
		//playerの回復
		hp->gaugesize.x = hp->gaugesize.x + venom.heal;
		hp->pos.x = hp->pos.x - venom.heal;
		//slimeの回復
		if (map_player->encount == 1)
			slimehp->gaugesize.x = slimehp->gaugesize.x - venom.heal;
		//firewallの回復
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