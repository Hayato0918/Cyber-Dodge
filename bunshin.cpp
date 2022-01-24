//スキル_分身処理[bunshin.cpp]
#include "bunshin.h"
//システム.h
#include "texture.h"
#include "sprite.h"
//エネミー.h
#include "slime.h"
#include "deleter.h"
#include "firewall.h"

#include "ball.h"
#include "catch.h"

#include "bugincrease.h"
#include "bugrandom.h"
#include "map_player.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
static ENEMYCLONE g_EnemyClone[ENEMYCLONE_MAX];
SLIME* slime = GetSlime();
DELETER* deleter = GetDeleter();
FIREWALL* firewall = GetFireWall();

//-----初期化処理
HRESULT InitEnemyClone(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	for (int i = 0; i < ENEMYCLONE_MAX; i++)
	{
		if (map_player->encount == 1)
		{
			g_EnemyClone[i].pos = D3DXVECTOR2(slime->pos.x + SCREEN_WIDTH * 0.06875f, slime->pos.y + SCREEN_HEIGHT * 0.26666f);
			g_EnemyClone[i].size = D3DXVECTOR2(slime->size.x, slime->size.y);
			g_EnemyClone[i].move = D3DXVECTOR2(slime->move.x, slime->move.y);
			g_EnemyClone[i].rotate = slime->rotate;
		}
		if (map_player->encount == 2)
		{
			g_EnemyClone[i].pos = D3DXVECTOR2(deleter->pos.x + SCREEN_WIDTH * 0.06875f, deleter->pos.y + SCREEN_HEIGHT * 0.26666f);
			g_EnemyClone[i].size = D3DXVECTOR2(deleter->size.x, deleter->size.y);
			g_EnemyClone[i].move = D3DXVECTOR2(deleter->move.x, deleter->move.y);
			g_EnemyClone[i].rotate = deleter->rotate;
		}
		if (map_player->encount == 3)
		{
			g_EnemyClone[i].pos = D3DXVECTOR2(firewall->pos.x + SCREEN_WIDTH * 0.06875f, firewall->pos.y + SCREEN_HEIGHT * 0.26666f);
			g_EnemyClone[i].size = D3DXVECTOR2(firewall->size.x, firewall->size.y);
			g_EnemyClone[i].move = D3DXVECTOR2(firewall->move.x, firewall->move.y);
			g_EnemyClone[i].rotate = firewall->rotate;
		}

		g_EnemyClone[i].drawflag = false;
	}
	return S_OK;
}

//-----更新処理
void _EnemyClone(void)
{
	BALL* ball = GetBall();
	BUG* bug = GetBugIncrease();
	BUGRANDOM* bugrandom = GetBugRandom();
	MAP_PLAYER* map_player = GetMapPlayer();
	
	if (bugrandom->code == 3 && bug->breakflag == true && g_EnemyClone[0].drawflag == false)
	{
		for (int i = 0; i < ENEMYCLONE_MAX; i++)
		{
			if (map_player->encount == 1)
				g_EnemyClone[i].drawflag = slime->drawflag;
			if (map_player->encount == 2)
				g_EnemyClone[i].drawflag = deleter->drawflag;
			if(map_player->encount == 3)
			g_EnemyClone[i].drawflag = firewall->drawflag;

			//-----コート外に出ない処理
			if (g_EnemyClone[i].pos.y <= 180 - g_EnemyClone[i].size.y * 0.5f)			//上
				g_EnemyClone[i].pos.y = 180 - g_EnemyClone[i].size.y * 0.5f;
			if (g_EnemyClone[i].pos.y >= SCREEN_HEIGHT - g_EnemyClone[i].size.y - 15)	//下
				g_EnemyClone[i].pos.y = SCREEN_HEIGHT - g_EnemyClone[i].size.y - 15;
			if (g_EnemyClone[i].pos.x <= SCREEN_WIDTH * 0.5f)								//左
				g_EnemyClone[i].pos.x = SCREEN_WIDTH * 0.5f;
			if (g_EnemyClone[i].pos.x >= SCREEN_WIDTH - g_EnemyClone[i].size.x - 5)								//右
				g_EnemyClone[i].pos.x = SCREEN_WIDTH - g_EnemyClone[i].size.x - 5;


			//-----プレイヤーが投げたボールが、地面,壁に当たらず敵に当たったら敵の描画をやめる(アウト判定)
			//if (ball->enemyhitflag == true)
			//{
			//	if (enemy.pos.x < ball->pos.x + ball->size.x && enemy.pos.x + enemy.size.x > ball->pos.x)
			//	{
			//		if (enemy.pos.y < ball->pos.y + ball->size.y && enemy.pos.y + enemy.size.y > ball->pos.y)
			//			enemy.drawflag = false;	
			//	}
			//}
		}
	}
}

//-----描画処理
void DrawEnemyClone(void)
{
	for (int i = 0; i < ENEMYCLONE_MAX; i++)
	{
		if (g_EnemyClone[i].drawflag == true)
		{
			if (g_EnemyClone[i].rotate == 0)
				DrawSpriteLeftTop(g_EnemyClone[i].Wtexture, g_EnemyClone[i].pos.x, g_EnemyClone[i].pos.y, g_EnemyClone[i].size.x, g_EnemyClone[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
			if (g_EnemyClone[i].rotate == 1)
				DrawSpriteLeftTop(g_EnemyClone[i].Stexture, g_EnemyClone[i].pos.x, g_EnemyClone[i].pos.y, g_EnemyClone[i].size.x, g_EnemyClone[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
			if (g_EnemyClone[i].rotate == 2)
				DrawSpriteLeftTop(g_EnemyClone[i].Atexture, g_EnemyClone[i].pos.x, g_EnemyClone[i].pos.y, g_EnemyClone[i].size.x, g_EnemyClone[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
			if (g_EnemyClone[i].rotate == 3)
				DrawSpriteLeftTop(g_EnemyClone[i].Dtexture, g_EnemyClone[i].pos.x, g_EnemyClone[i].pos.y, g_EnemyClone[i].size.x, g_EnemyClone[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		}
	}
}

//-----構造体ポインタ取得処理
ENEMYCLONE* GetEnemyClone(void)
{
	return &g_EnemyClone[0];
}