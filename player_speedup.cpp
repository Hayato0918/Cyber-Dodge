//スキル_スピードアップ処理 [player_speedup.cpp]
#include "player_speedup.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----マクロ定義
#define speeduptime 600		//10s間

//-----プロトタイプ宣言
SPEEDUP speedup;
SPEEDUP_ANIME sppedup_anime;

//-----グローバル変数

//-----初期化処理
HRESULT InitSpeedUp(void)
{
	speedup.use = false;
	speedup.timeflag = false;
	speedup.time = 0.0f;
	speedup.usegauge = 20;

	speedup.bugincrease = false;
	speedup.bugdrawnum = 0;

	sppedup_anime.time = 0.f;

	return S_OK;
}

//-----巨大化処理
void _SpeedUp(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	RANDOM* random = GetRandom();
	SKILL* skill = GetSkill();

	//ランダムで4が出たら、10s間キャラのスピードが2倍になる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 24 && random[i].active == true && speedup.use == false)
		{
			player->move *= 2;
			speedup.timeflag = true;
			//-----バグゲージの上昇
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

	//-----アニメーション
	if (speedup.timeflag == true)
	{
		sppedup_anime.pos = D3DXVECTOR2(player->pos.x, player->pos.y - 50);
		sppedup_anime.size = D3DXVECTOR2(player->size.x, player->size.y + 50);
		sppedup_anime.time = sppedup_anime.time + 1.f;

		for (int i = 0; i < 22; i++)
		{
			if (sppedup_anime.time > 2.727f * i && sppedup_anime.time <= 2.727f + 2.727f * i)
				sppedup_anime.u = 0.045454545f * i;
		}
	}



	//スキル使用10s後にもとのスピードに戻る
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

void DrawSpeedup()
{
	if (speedup.timeflag == true)
		DrawSpriteLeftTop(sppedup_anime.texture, sppedup_anime.pos.x, sppedup_anime.pos.y, sppedup_anime.size.x, sppedup_anime.size.y, sppedup_anime.u, 0.f, 0.045454545f, 1.f);
}

SPEEDUP_ANIME* GetSpeedup()
{
	return &sppedup_anime;
}