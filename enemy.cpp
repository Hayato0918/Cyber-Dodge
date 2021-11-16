//エネミー処理 [enemy.cpp]
#include "enemy.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "ball.h"
#include "catch.h"
#include "enemyAI.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
ENEMY enemy;

//-----初期化処理
HRESULT InitEnemy(void)
{
	enemy.pos = D3DXVECTOR2(800.0f, 320.0f);
	enemy.size = D3DXVECTOR2(60.0f, 120.0f);
	enemy.move = D3DXVECTOR2(2.0f, 2.0f);
	enemy.Wtexture = LoadTexture("data/TEXTURE/player_w.png");
	enemy.Stexture = LoadTexture("data/TEXTURE/player_s.png");
	enemy.Atexture = LoadTexture("data/TEXTURE/player_a.png");
	enemy.Dtexture = LoadTexture("data/TEXTURE/player_d.png");
	enemy.rotate = 2;

	enemy.drawflag = true;

	return S_OK;
}

//-----終了処理
void UninitEnemy(void)
{

}

//-----更新処理
void UpdateEnemy(void)
{
	BALL* ball = GetBall();

	//-----移動処理(コートの左右端を3sで移動)
	if (GetKeyboardPress(DIK_UPARROW))	//上
	{
		enemy.pos.y -= enemy.move.y;
		enemy.rotate = 0;
	}
	if (GetKeyboardPress(DIK_DOWNARROW))	//下
	{
		enemy.pos.y += enemy.move.y;
		enemy.rotate = 1;
	}
	if (GetKeyboardPress(DIK_LEFTARROW))	//左
	{
		enemy.pos.x -= enemy.move.x;
		enemy.rotate = 2;
	}
	if (GetKeyboardPress(DIK_RIGHTARROW))	//右
	{
		enemy.pos.x += enemy.move.x;
		enemy.rotate = 3;
	}

	//-----コート外に出ない処理
	if (enemy.pos.y <= 180 - enemy.size.y * 0.5)			//上
		enemy.pos.y = 180 - enemy.size.y * 0.5;
	if (enemy.pos.y >= SCREEN_HEIGHT - enemy.size.y - 15)	//下
		enemy.pos.y = SCREEN_HEIGHT - enemy.size.y - 15;
	if (enemy.pos.x <= SCREEN_WIDTH * 0.5)								//左
		enemy.pos.x = SCREEN_WIDTH * 0.5;
	if (enemy.pos.x >= SCREEN_WIDTH - enemy.size.x - 5)								//右
		enemy.pos.x = SCREEN_WIDTH - enemy.size.x - 5;


	//-----プレイヤーが投げたボールが、地面,壁に当たらず敵に当たったら敵の描画をやめる(アウト判定)
	//if (ball->enemyhitflag == true)
	//{
	//	if (enemy.pos.x < ball->pos.x + ball->size.x && enemy.pos.x + enemy.size.x > ball->pos.x)
	//	{
	//		if (enemy.pos.y < ball->pos.y + ball->size.y && enemy.pos.y + enemy.size.y > ball->pos.y)
	//			enemy.drawflag = false;	
	//	}
	//}

	enemyAI();
}

//-----描画処理
void DrawEnemy(void)
{
	if (enemy.drawflag == true)
	{
		if (enemy.rotate == 0)
			DrawSpriteLeftTop(enemy.Wtexture, enemy.pos.x, enemy.pos.y, enemy.size.x, enemy.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		if (enemy.rotate == 1)
			DrawSpriteLeftTop(enemy.Stexture, enemy.pos.x, enemy.pos.y, enemy.size.x, enemy.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		if (enemy.rotate == 2)
			DrawSpriteLeftTop(enemy.Atexture, enemy.pos.x, enemy.pos.y, enemy.size.x, enemy.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		if (enemy.rotate == 3)
			DrawSpriteLeftTop(enemy.Dtexture, enemy.pos.x, enemy.pos.y, enemy.size.x, enemy.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
}

//-----構造体ポインタ取得処理
ENEMY* GetEnemy(void)
{
	return &enemy;
}