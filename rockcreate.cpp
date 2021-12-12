//スキル_岩石生成 [rockcreate.cpp]
#include "rockcreate.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "player.h"
#include "bug.h"
#include "ball.h"
#include "skillrandom.h"
#include "enemy.h"
#include "penetration.h"

//-----マクロ定義
#define gansekitime 1800		//30s間

//-----プロトタイプ宣言
GANSEKI ganseki;

//-----グローバル変数

//-----初期化処理
HRESULT InitGanseki(void)
{
	ganseki.use = false;
	ganseki.timeflag = false;
	ganseki.time = 0.0f;
	ganseki.usegauge = 10;
	ganseki.pos = D3DXVECTOR2(0.0f, 0.0f);
	ganseki.size = D3DXVECTOR2(200.0f, 300.0f);
	ganseki.texture = LoadTexture("data/TEXTURE/Rock.png");

	return S_OK;
}

//-----不法侵入処理
void _Ganseki(void)
{
	PLAYER* player = GetPlayer();
	RANDOM* random = GetRandom();
	BUG* bug = GetBug();
	BALL* ball = GetBall();
	ENEMY* enemy = GetEnemy();
	KANTSUU* kantsuu = GetKantsuu();

	//-----発動から30秒間、フィールドに残る障害物として岩石を生成する
	for (int i = 0; i < 36; i++)
	{
		if (random[i].code == 12 && random[i].active == true && ganseki.use == false)
		{
			bug->gaugesize.x = bug->gaugesize.x + ganseki.usegauge * bug->gaugeonce;
			ganseki.pos.y = player->pos.y;
			if (player->rotate == 3)
				ganseki.pos.x = player->pos.x + 540.0f;
			if (player->rotate == 2)
				ganseki.pos.x = player->pos.x - 540.0f;

			ganseki.timeflag = true;
			ganseki.use = true;
		}
	}

	//-----
	if (ganseki.timeflag == true && kantsuu->use == false)
	{
		ganseki.time = ganseki.time + 1.0f;

		//ボールコリジョン
		if (ganseki.pos.x < ball->pos.x + ball->size.x && ganseki.pos.x + ganseki.size.x * 0.8f > ball->pos.x)
		{
			if (ganseki.pos.y + ganseki.size.y * 0.2f < ball->pos.y + ball->size.y && ganseki.pos.y + ganseki.size.y * 0.8f > ball->pos.y)
			{
				if (ball->move.x > 0)
					ball->move.x -= 5.0f;
				if (ball->move.x < 0)
					ball->move.x += 5.0f;
				ball->move.x *= -1.3f;
			}
		}

		//プレイヤーコリジョン
		if (ganseki.pos.x < player->pos.x + player->size.x && ganseki.pos.x + ganseki.size.x * 0.8f > player->pos.x)
		{
			if (ganseki.pos.y + ganseki.size.y * 0.2f < player->pos.y + player->size.y && ganseki.pos.y + ganseki.size.y * 0.8f > player->pos.y)
			{
				if (player->move.x > 0)
					player->pos.x -= 4.0f;
				if (player->move.x < 0)
					player->pos.x += 4.0f;
			}
		}

		//エネミーコリジョン
		if (ganseki.pos.x < enemy->pos.x + enemy->size.x && ganseki.pos.x + ganseki.size.x * 0.8f > enemy->pos.x)
		{
			if (ganseki.pos.y + ganseki.size.y * 0.2f < enemy->pos.y + enemy->size.y && ganseki.pos.y + ganseki.size.y * 0.8f > enemy->pos.y)
			{
				if (enemy->move.x < 0)
					enemy->pos.x -= 2.0f;
				if (enemy->move.x > 0)
					enemy->pos.x += 2.0f;
			}
		}
	}

	if (ganseki.time > gansekitime)
	{
		ganseki.timeflag = false;
		ganseki.time = 0.0f;
	}
}

void DrawGanseki(void)
{
	if (ganseki.timeflag == true)
	{
		DrawSpriteLeftTop(ganseki.texture, ganseki.pos.x, ganseki.pos.y, ganseki.size.x, ganseki.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
}

//-----構造体ポインタ取得処理
GANSEKI* GetGanseki(void)
{
	return &ganseki;
}