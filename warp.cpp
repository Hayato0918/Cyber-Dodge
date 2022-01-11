//スキル_ワープ処理 [warp.cpp]
#include "warp.h"
//システム.h
#include "input.h"
#include "texture.h"
#include "sprite.h"
//プレイヤー.h
#include "player.h"
#include "bugincrease.h"
//エネミー.h
#include "slime.h"
#include "firewall.h"
#include "map_point.h"

#include "ball.h"
//スキル.h
#include "skillrandom.h"

//-----マクロ定義
#define warptime 600		//10s間

//-----プロトタイプ宣言
WARP warp;

//-----グローバル変数

//-----初期化処理
HRESULT InitWarp(void)
{
	warp.player_pos = D3DXVECTOR2(SCREEN_WIDTH, 320.0f);
	warp.player_size = D3DXVECTOR2(100.0f, 100.0f);

	warp.enemy_pos = D3DXVECTOR2(SCREEN_WIDTH, 320.0f);
	warp.enemy_size = D3DXVECTOR2(100.0f, 100.0f);

	warp.warp_flag = false;
	warp.texture = LoadTexture("data/TEXTURE/warp.png");
	warp.use = false;
	warp.timeflag = false;
	warp.time = 0.0f;
	warp.usegauge = 30;

	warp.bugincrease = false;
	warp.bugdrawnum = 0;

	return S_OK;
}

//-----ワープ処理
void _Warp(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	RANDOM* random = GetRandom();
	SLIME* slime = GetSlime();
	FIREWALL* firewall = GetFireWall();
	MAP_PLAYER* map_player = GetMapPlayer();
	BALL* ball = GetBall();

	//ランダムで4が出たら、10s間ワープホールが出現
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 26 && random[i].active == true && warp.use == false)
		{
			//プレイヤーの前と敵の後ろにワープホールを出現させる
			warp.player_pos.x = player->pos.x + (player->size.x * 1);
			warp.player_pos.y = player->pos.y + ((player->size.y - warp.enemy_size.y) / 2);
			if (warp.player_pos.x > SCREEN_WIDTH / 2 - warp.player_size.x)
			{
				warp.player_pos.x = SCREEN_WIDTH / 2 - warp.player_size.x;
			}
			if (map_player->encount == 1)
			{
				warp.enemy_pos.x = slime->pos.x + (slime->size.x * 1);
				warp.enemy_pos.y = slime->pos.y + ((slime->size.y - warp.enemy_size.y) / 2);
			}
			if (map_player->encount == 21)
			{
				warp.enemy_pos.x = firewall->pos.x + (firewall->size.x * 1);
				warp.enemy_pos.y = firewall->pos.y + ((firewall->size.y - warp.enemy_size.y) / 2);
			}
			if (warp.enemy_pos.x > SCREEN_WIDTH - warp.enemy_size.x)
			{
				warp.enemy_pos.x = SCREEN_WIDTH - warp.enemy_size.x;
			}
			warp.use = true;

			warp.timeflag = true;

			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && warp.bugincrease == false)
				{
					for (int j = i; warp.bugdrawnum < 6; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						warp.bugdrawnum = warp.bugdrawnum + 1;
					}
					warp.bugincrease = true;
				}
			}
		}
	}

	if (warp.use == true && ball->enemyhitflag == true)
	{
		if (warp.player_pos.x + warp.player_size.x > ball->pos.x && warp.player_pos.x < ball->pos.x + ball->size.x)
		{
			if (warp.player_pos.y + warp.player_size.y > ball->pos.y && warp.player_pos.y < ball->pos.y + ball->size.y)
			{
				ball->pos.x = warp.enemy_pos.x - ((warp.enemy_size.x - ball->size.x) / 2);
				ball->pos.y = warp.enemy_pos.y + ((warp.enemy_size.y - ball->size.y) / 2);
				ball->move = D3DXVECTOR2(-12.0f, 0.0f);
			}
		}
	}

	//スキル使用10s後にもとの状態に戻る
	if (warp.timeflag == true)
		warp.time = warp.time + 1.0f;
	if (warp.time > warptime)
	{
		warp.timeflag = false;
		warp.time = 0.0f;
		warp.use = false;
	}
}

void DrawWarp(void)
{
	if (warp.use == true)
	{
		DrawSpriteLeftTop(warp.texture, warp.player_pos.x, warp.player_pos.y, warp.player_size.x, warp.player_size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		DrawSpriteLeftTop(warp.texture, warp.enemy_pos.x, warp.enemy_pos.y, warp.enemy_size.x, warp.enemy_size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
}