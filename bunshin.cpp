#include "bunshin.h"
#include "enemy.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "ball.h"
#include "catch.h"

#include "bug.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
static ENEMYCLONE g_EnemyClone[ENEMYCLONE_MAX];

ENEMY* enemy = GetEnemy();
//-----初期化処理
HRESULT InitEnemyClone(void)
{

	for (int i = 0; i < ENEMYCLONE_MAX; i++)
	{
		g_EnemyClone[i].pos = D3DXVECTOR2(enemy->pos.x + 110.0f, enemy->pos.y + 240.0f);
		g_EnemyClone[i].size = D3DXVECTOR2(enemy->size.x, enemy->size.y);
		g_EnemyClone[i].move = D3DXVECTOR2(enemy->move.x, enemy->move.y);
		g_EnemyClone[i].rotate = enemy->rotate;

		g_EnemyClone[i].drawflag = false;
	}
	return S_OK;
}

//-----終了処理
void UninitEnemyClone(void)
{

}

//-----更新処理
void UpdateEnemyClone(void)
{
	BALL* ball = GetBall();
	BUG* bug = GetBug();

	for (int i = 0; i < ENEMYCLONE_MAX; i++)
	{
		if (bug->gaugesize.x >= 10)
		{
			g_EnemyClone[i].drawflag = enemy->drawflag;
		}

		//-----コート外に出ない処理
		if (g_EnemyClone[i].pos.y <= 180 - g_EnemyClone[i].size.y * 0.5)			//上
			g_EnemyClone[i].pos.y = 180 - g_EnemyClone[i].size.y * 0.5;
		if (g_EnemyClone[i].pos.y >= SCREEN_HEIGHT - g_EnemyClone[i].size.y - 15)	//下
			g_EnemyClone[i].pos.y = SCREEN_HEIGHT - g_EnemyClone[i].size.y - 15;
		if (g_EnemyClone[i].pos.x <= SCREEN_WIDTH * 0.5)								//左
			g_EnemyClone[i].pos.x = SCREEN_WIDTH * 0.5;
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

		////-----投げる処理
		//_Throw();

		////-----キャッチ処理
		//M_Catch();
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