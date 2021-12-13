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

	invincible.texture = LoadTexture("data/TEXTURE/player_muteki.png");

	return S_OK;
}

//-----インビジブル処理
void _Invincible(void)
{
	PLAYER* player = GetPlayer();
	BALL* ball = GetBall();
	BUG* bug = GetBugIncrease();;
	RANDOM* random = GetRandom();

	invincible.pos = D3DXVECTOR2(player->pos.x, player->pos.y);

	//9キーを押したら、5s間キャラが無敵になる
	for (int i = 0; i <36; i++)
	{
		if (random[i].code == 10 && random[i].active == true && invincible.use == false)
		{
			ball->playerhitflag = false;
			invincible.timeflag = true;
			bug->gaugesize.x = bug->gaugesize.x + invincible.usegauge * bug->gaugeonce;
			invincible.use = true;
		}
	}
	//スキル使用5s後に無敵が解除される
	if (invincible.timeflag == true)
		invincible.time = invincible.time + 1.0f;
	if (invincible.time > invincibletime)
	{
		invincible.timeflag = false;
		invincible.time = 0.0f;
		invincible.use = false;
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