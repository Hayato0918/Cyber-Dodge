/*---------------------------------------------
[ プレイヤーの無敵処理　[invincible.cpp]  ]
----------------------------------------------*/
#include "invincible.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "ball.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----マクロ定義
#define invincibletime 300		//5s間

//-----プロトタイプ宣言
INVINCIBLE invincible;

//-----グローバル変数

//-----初期化処理
HRESULT InitInvincible(void)
{
	PLAYER* player = GetPlayer();
	invincible.pos = D3DXVECTOR2(player->pos.x, player->pos.y);
	invincible.size = D3DXVECTOR2(player->size.y, player->size.y);
	invincible.use = false;
	invincible.timeflag = false;
	invincible.time = 0.0f;
	invincible.usegauge = 40;

	invincible.bugincrease = false;
	invincible.bugdrawnum = 0;

	invincible.texture = LoadTexture("data/TEXTURE/player_muteki.png");

	return S_OK;
}

//-----インビジブル処理
void _Invincible(void)
{
	PLAYER* player = GetPlayer();
	BALL* ball = GetBall();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	RANDOM* random = GetRandom();

	invincible.pos = D3DXVECTOR2(player->pos.x, player->pos.y);

	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 10 && random[i].active == true && invincible.use == false)
		{
			ball->playerhitflag = false;
			invincible.timeflag = true;
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && invincible.bugincrease == false)
				{
					for (int j = i; invincible.bugdrawnum < 8; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						invincible.bugdrawnum = invincible.bugdrawnum + 1;
					}
					invincible.bugincrease = true;
				}
			}
			invincible.use = true;
		}
	}
	//スキル使用5s後に無敵が解除される
	if (invincible.timeflag == true)
		invincible.time = invincible.time + 1.0f;
	if (invincible.time > invincibletime)
	{
		invincible.timeflag = false;
		invincible.use = false;
		invincible.time = 0.0f;
	}
}

//-----描画処理
void DrawInvincible(void)
{
	if (invincible.timeflag == true)
		DrawSpriteLeftTop(invincible.texture, invincible.pos.x, invincible.pos.y, invincible.size.x, invincible.size.y, 1.0f, 1.0f, 1.0f, 1.0f);
}

//-----構造体ポインタ取得処理
INVINCIBLE* GetInvincible(void)
{
	return &invincible;
}