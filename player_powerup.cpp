//スキル_パワーアップ処理 [player_powerup.cpp]
#include "player_powerup.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----マクロ定義
#define poweruptime 600		//10s間

//-----プロトタイプ宣言
POWERUP powerup;
POWERUP_ANIME powerup_anime;

//-----グローバル変数

//-----初期化処理
HRESULT InitPowerUp(void)
{
	powerup.use = false;
	powerup.timeflag = false;
	powerup.time = 0.0f;
	powerup.usegauge = 20;

	powerup.bugincrease = false;
	powerup.bugdrawnum = 0;

	powerup_anime.time = 0.f;
	powerup_anime.texture = LoadTexture("data/TEXTURE/skill/effect/Powerup.png");

	return S_OK;
}

//-----巨大化処理
void _PowerUp(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	RANDOM* random = GetRandom();
	SKILL* skill = GetSkill();

	//ランダムで4が出たら、10s間キャラのパワーが+50になる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 22 && random[i].active == true && powerup.use == false)
		{
			player->atk += 50;
			powerup.timeflag = true;
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && powerup.bugincrease == false)
				{
					for (int j = i; powerup.bugdrawnum < 4; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						powerup.bugdrawnum = powerup.bugdrawnum + 1;
					}
					powerup.bugincrease = true;
				}
			}
			powerup.use = true;
		}
	}

	//-----アニメーション
	if (powerup.timeflag == true)
	{
		powerup_anime.pos = D3DXVECTOR2(player->pos.x, player->pos.y - 50);
		powerup_anime.size = D3DXVECTOR2(player->size.x, player->size.y + 50);
		powerup_anime.time = powerup_anime.time + 1.f;

		for (int i = 0; i < 22; i++)
		{
			if (powerup_anime.time > 2.727f * i && powerup_anime.time <= 2.727f + 2.727f * i)
				powerup_anime.u = 0.045454545f * i;
		}
	}


	//スキル使用10s後にもとの強さに戻る
	if (powerup.timeflag == true)
		powerup.time = powerup.time + 1.0f;
	if (powerup.time > poweruptime)
	{
		powerup.timeflag = false;
		player->atk -= 50;
		powerup.time = 0.0f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && powerup.use == true)
		{
			if (powerup.time < poweruptime)
				player->atk -= 50;
			powerup.timeflag = false;
			powerup.bugdrawnum = 0;
			powerup.bugincrease = false;
			powerup.time = 0.0f;
			powerup.use = false;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && powerup.use == true)
		{
			if (powerup.time < poweruptime)
				player->atk -= 50;
			powerup.timeflag = false;
			powerup.bugdrawnum = 0;
			powerup.bugincrease = false;
			powerup.time = 0.0f;
			powerup.use = false;
		}
	}
}

void DrawPowerup()
{
	if (powerup.timeflag == true)
		DrawSpriteLeftTop(powerup_anime.texture, powerup_anime.pos.x, powerup_anime.pos.y, powerup_anime.size.x, powerup_anime.size.y, powerup_anime.u, 0.f, 0.045454545f, 1.f);
}