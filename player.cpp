//プレイヤー処理 [player.cpp]
#include "player.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "escape.h"
#include "ball.h"
#include "catch.h"
#include "skill.h"
#include "invade.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
PLAYER player;

//-----初期化処理
HRESULT InitPlayer(void)
{
	player.pos = D3DXVECTOR2(240.0f, 320.0f);
	player.size = D3DXVECTOR2(90.0f, 180.0f);
	player.move = D3DXVECTOR2(4.0f, 4.0f);
	//player.Wtexture = LoadTexture("data/TEXTURE/player_w.png");
	//player.Stexture = LoadTexture("data/TEXTURE/player_s.png");
	//player.Atexture = LoadTexture("data/TEXTURE/player_a.png");
	//player.Dtexture = LoadTexture("data/TEXTURE/player_d.png");
	player.walk_1texture = LoadTexture("data/TEXTURE/player_walk_1.png");
	player.walk_2texture = LoadTexture("data/TEXTURE/player_walk_2.png");
	player.textureflag = true;
	player.rotate = 3;
	player.drawflag = true;

	InitSkill();

	return S_OK;
}

//-----終了処理
void UninitPlayer(void)
{

}

//-----更新処理
void UpdatePlayer(void)
{
	BALL* ball = GetBall();
	INVADE* invade = GetInvade();

	//-----移動処理(コートの左右端を3sで移動)
	if (GetKeyboardPress(DIK_W))	//上
	{
		player.pos.y -= player.move.y;
		player.rotate = 0;
	}
	if (GetKeyboardPress(DIK_S))	//下
	{
		player.pos.y += player.move.y;
		player.rotate = 1;
	}
	if (GetKeyboardPress(DIK_A))	//左
	{
		player.pos.x -= player.move.x;
		player.textureflag = true;
		player.rotate = 2;
	}
	if (GetKeyboardPress(DIK_D))	//右
	{
		player.pos.x += player.move.x;
		player.textureflag = false;
		player.rotate = 3;
	}

	//-----コート外に出ない処理
	if (player.pos.y <= 180 - player.size.y * 0.5)			//上
		player.pos.y = 180 - player.size.y * 0.5;
	if (player.pos.y >= SCREEN_HEIGHT - player.size.y - 15 -120)	//下
		player.pos.y = SCREEN_HEIGHT - player.size.y - 15 -120;
	if (player.pos.x <= 0 + 15)								//左
		player.pos.x = 0 + 15;
	if (invade->timeflag == false)
	{
		if (player.pos.x >= SCREEN_WIDTH * 0.5 - player.size.x - 5)		//右
			player.pos.x = SCREEN_WIDTH * 0.5 - player.size.x - 5;
	}
	if (invade->timeflag == true)
	{
		if (player.pos.x >= SCREEN_WIDTH - player.size.x - 5)		//右
			player.pos.x = SCREEN_WIDTH - player.size.x - 5;
	}

	//-----エネミーが投げたボールが、地面,壁に当たらずプレイヤーに当たったらプレイヤーの描画をやめる(アウト判定)
	//if (barrier->drawflag == false)
	//{
	//	if (ball->playerhitflag == true)
	//	{
	//		if (player.pos.x < ball->pos.x + ball->size.x && player.pos.x + player.size.x > ball->pos.x)
	//		{
	//			if (player.pos.y < ball->pos.y + ball->size.y && player.pos.y + player.size.y > ball->pos.y)
	//				player.drawflag = false;
	//		}
	//	}
	//}



	//-----回避処理
	_Escape();

	//-----投げる処理
	P_Throw();

	//-----キャッチ処理
	P_Catch();

	//-----スキル処理
	_Skill();
}

//-----描画処理
void DrawPlayer(void)
{
	if (player.drawflag == true)
	{
		if(player.textureflag == true)
		DrawSpriteLeftTop(player.walk_1texture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		if(player.textureflag == false)
			DrawSpriteLeftTop(player.walk_2texture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		//if (player.rotate == 0)
		//	DrawSpriteLeftTop(player.Wtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		//if (player.rotate == 1)
		//	DrawSpriteLeftTop(player.Stexture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		//if (player.rotate == 2)
		//	DrawSpriteLeftTop(player.Atexture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		//if (player.rotate == 3)
			//DrawSpriteLeftTop(player.Dtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}

	//-----スキル描画
	DrawSkill();
}

//-----構造体ポインタ取得処理
PLAYER* GetPlayer(void)
{
	return &player;
}