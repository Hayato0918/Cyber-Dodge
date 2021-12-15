//バグ_リジェネ処理 [regen.cpp]
#include "regen.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player_hp.h"
#include "bugincrease.h"
#include "bugrandom.h"

//-----マクロ定義
#define regentime 600		//10s間

//-----プロトタイプ宣言
REGEN regen;

//-----グローバル変数

//-----初期化処理
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
	BUG* bug = GetBugIncrease();
	BUGRANDOM* bugrandom = GetBugRandom();

	if (bugrandom->code == 4 && bug->gaugesize.x >= 10 && regen.use == true)
	{
		hp->gaugesize.x = hp->gaugesize.x + regen.heal;
		hp->pos.x = hp->pos.x - regen.heal;
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