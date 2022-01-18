/*------------------------------------------
[ クリエイト [ pit.cpp ] ]
-------------------------------------------*/
#include "pit.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"
#include "ball.h"
#include "player.h"
#include "penetration.h"

#include "bugincrease.h"
#include "bugrandom.h"

//エネミー.h
#include "firewall.h"
#include "slime.h"
#include "map_point.h"

//-----マクロ定義
#define pittime 3600		//キャッチ判定を出す時間
#define pitnumber 4		//岩の個数

//-----プロトタイプ宣言
PIT pit[pitnumber];

//-----グローバル変数

HRESULT InitPit(void)
{
	for (int i = 0; i < pitnumber; i++)
	{
		pit[i].pos = D3DXVECTOR2(0.0f, 0.0f);
		pit[i].size = D3DXVECTOR2(120.0f, 160.0f);
		pit[i].texture = LoadTexture("data/TEXTURE/Rock.png");
		pit[i].use = false;
		pit[i].time = 0.0f;
		pit[i].timeflag = false;
		pit[i].drawflag = false;
	}

	return S_OK;
}

void _Pit(void)
{
	BUG* bug = GetBugIncrease();
	BUGRANDOM* bugrandom = GetBugRandom();
	PLAYER* player = GetPlayer();
	BALL* ball = GetBall();
	FIREWALL* firewall = GetFireWall();
	SLIME* slime = GetSlime();
	MAP_PLAYER* map_player = GetMapPlayer();
	KANTSUU* kantsuu = GetKantsuu();

	for (int i = 0; i < pitnumber; i++)
	{
		//バグゲージが100以上になって、スキルを使うかボールが当たると落とし穴が出る
		if (bugrandom->code == 7 && bug->breakflag == true && pit[i].use == false)
		{
			pit[i].use = true;
			pit[i].drawflag = true;

			pit[i].time = 0.0f;
			if (pit[i].use == false)
			{
				pit[i].timeflag = true;
				pit[i].use = true;

				//座標ランダムに入れる処理
				int a = pit[i].size.x * 2;
				pit[i].pos.x = rand() % (SCREEN_WIDTH - 15 - a) + 15 + pit[i].size.x;
				pit[i].pos.y = rand() % (SCREEN_HEIGHT - 420 - 120) - pit[i].size.y / 2 + 420;
			}
		}

		if (pit[i].timeflag == true)
		{
			pit[i].time = pit[i].time + 1.0f;
		}



		//-----
		if (pit[i].timeflag == true && kantsuu->use == false)
		{
			pit[i].time = pit[i].time + 1.0f;

			//ボールコリジョン
			if (pit[i].pos.x < ball->pos.x + ball->size.x && pit[i].pos.x + pit[i].size.x * 0.8f > ball->pos.x)
			{
				if (pit[i].pos.y + pit[i].size.y * 0.2f < ball->pos.y + ball->size.y && pit[i].pos.y + pit[i].size.y * 0.8f > ball->pos.y)
				{
					if (ball->move.x > 0)
						ball->move.x -= 5.0f;
					if (ball->move.x < 0)
						ball->move.x += 5.0f;
					ball->move.x *= -1.3f;
				}
			}

			//プレイヤーコリジョン
			if (pit[i].pos.x < player->pos.x + player->size.x && pit[i].pos.x + pit[i].size.x * 0.8f > player->pos.x)
			{
				if (pit[i].pos.y + pit[i].size.y * 0.2f < player->pos.y + player->size.y && pit[i].pos.y + pit[i].size.y * 0.8f > player->pos.y)
				{
					if (player->move.x > 0)
						player->pos.x -= 4.0f;
					if (player->move.x < 0)
						player->pos.x += 4.0f;
				}
			}

			//エネミーコリジョン
			if (map_player->encount == 1)
			{
				if (pit[i].pos.x < slime->pos.x + slime->size.x && pit[i].pos.x + pit[i].size.x * 0.8f > slime->pos.x)
				{
					if (pit[i].pos.y + pit[i].size.y * 0.2f < slime->pos.y + slime->size.y && pit[i].pos.y + pit[i].size.y * 0.8f > slime->pos.y)
					{
						if (slime->move.x < 0)
							slime->pos.x -= 2.0f;
						if (slime->move.x > 0)
							slime->pos.x += 2.0f;
					}
				}
			}
			if (map_player->encount == 2)
			{
				if (pit[i].pos.x < firewall->pos.x + firewall->size.x && pit[i].pos.x + pit[i].size.x * 0.8f > firewall->pos.x)
				{
					if (pit[i].pos.y + pit[i].size.y * 0.2f < firewall->pos.y + firewall->size.y && pit[i].pos.y + pit[i].size.y * 0.8f > firewall->pos.y)
					{
						if (firewall->move.x < 0)
							firewall->pos.x -= 2.0f;
						if (firewall->move.x > 0)
							firewall->pos.x += 2.0f;
					}
				}
			}
			//60秒後にもとに戻る
			if (pit[i].time > pittime)
			{
				pit[i].timeflag = false;
				pit[i].time = 0.0f;

				pit[i].use = false;
			}
		}
	}
}

void DrawPit(void)
{
	for (int i = 0; i < pitnumber; i++)
	{
		if (pit[i].use == true)
		{
			DrawSpriteColor(pit[i].texture, pit[i].pos.x, pit[i].pos.y, pit[i].size.x, pit[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f,
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		}
	}
}

PIT* GetPit(int number)
{
	if (number < 0 || pitnumber - 1 < number)
	{
		return &pit[0];
	}

	return &pit[number];
}
