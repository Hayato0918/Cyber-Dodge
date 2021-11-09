//プレイヤー処理 [player.cpp]
#include "player.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "escape.h"
#include "ball.h"
#include "catch.h"
#include "skill.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
PLAYER player;

//-----初期化処理
HRESULT InitPlayer(void)
{
	player.pos = D3DXVECTOR2(240.0f, 320.0f);
	player.size = D3DXVECTOR2(60.0f, 120.0f);
	player.move = D3DXVECTOR2(2.0f, 2.0f);
	player.Wtexture = LoadTexture("data/TEXTURE/player_w.png");
	player.Stexture = LoadTexture("data/TEXTURE/player_s.png");
	player.Atexture = LoadTexture("data/TEXTURE/player_a.png");
	player.Dtexture = LoadTexture("data/TEXTURE/player_d.png");
	player.rotate = 3;

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
		player.rotate = 2;
	}
	if (GetKeyboardPress(DIK_D))	//右
	{
		player.pos.x += player.move.x;
		player.rotate = 3;
	}

	//-----コート外に出ない処理
	if (player.pos.y <= 180 - player.size.y * 0.5)			//上
		player.pos.y = 180 - player.size.y * 0.5;
	if (player.pos.y >= SCREEN_HEIGHT - player.size.y - 15)	//下
		player.pos.y = SCREEN_HEIGHT - player.size.y - 15;
	if (player.pos.x <= 0 + 15)								//左
		player.pos.x = 0 + 15;								//右
	if (player.pos.x >= SCREEN_WIDTH * 0.5 - player.size.x - 5)
		player.pos.x = SCREEN_WIDTH * 0.5 - player.size.x - 5;

	//-----回避処理
	_Escape();

	//-----投げる処理
	_Throw();

	//-----キャッチ処理
	_Catch();




	//-----スキル処理
	_Skill();
}

//-----描画処理
void DrawPlayer(void)
{
	if(player.rotate == 0)
	DrawSpriteLeftTop(player.Wtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	if(player.rotate == 1)
	DrawSpriteLeftTop(player.Stexture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	if (player.rotate == 2)
		DrawSpriteLeftTop(player.Atexture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	if (player.rotate == 3)
		DrawSpriteLeftTop(player.Dtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----構造体ポインタ取得処理
PLAYER* GetPlayer(void)
{
	return &player;
}