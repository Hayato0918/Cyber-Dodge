//スキル_リジェネ処理 [player_regen.cpp]
#include "player_regen.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"
#include "player_hp.h"

#include "skillrandom.h"

//-----マクロ定義
#define regentime 60		//1s間

//-----プロトタイプ宣言
PLAYERREGEN regen;

//-----グローバル変数

//-----初期化処理
HRESULT InitPlayerRegen(void)
{
	regen.use = false;
	regen.timeflag = false;
	regen.time = 0.0f;
	regen.number = 0;
	regen.usegauge = 30;

	regen.bugincrease = false;
	regen.bugdrawnum = 0;

	return S_OK;
}

//-----巨大化処理
void _PlayerRegen(void)
{
	PLAYERHP* hp = GetPlayerHp();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	RANDOM* random = GetRandom();

	//ランダムで4が出たら、10s間キャラの体力が1sずつに10回復する
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 23 && random[i].active == true && regen.use == false)
		{
			regen.timeflag = true;
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && regen.bugincrease == false)
				{
					for (int j = i; regen.bugdrawnum < 4; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						regen.bugdrawnum = regen.bugdrawnum + 1;
					}
					regen.bugincrease = true;
				}
			}
			regen.use = true;
		}
	}
	//スキル発動後秒数をカウント
	if (regen.timeflag == true)
		regen.time = regen.time + 1.0f;
	//1sごとに体力を1回復
	if (regen.time > regentime)
	{
		if (hp->gaugesize.x < 640)
		{
			hp->gaugesize.x += 10 * 3.2f;
			hp->pos.x -= 10 * 3.2f;
		}
		regen.time = 0.0f;
		regen.number += 1;
	}

	if (hp->gaugesize.x > 640)
	{
		hp->gaugesize.x = 640;
		hp->pos.x = 100.0f;
	}

	//合計100回復後秒数カウントを止める
	if (regen.number > 10)
	{
		regen.timeflag = false;
		regen.time = 0.0f;
		regen.use = false;
		regen.bugincrease = false;
		regen.bugdrawnum = 0;
		regen.number = 0;
	}
}