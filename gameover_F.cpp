//ゲームオーバーF処理 [gameover_F.cpp]
#include "gameover_F.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "map_player.h"

//-----マクロ定義

//-----プロトタイプ宣言
GAMEOVER_FNUM gameover_F[2];
GAMEOVER_F gameover_f;

//-----グローバル変数

//-----初期化処理
HRESULT InitGameOverF(void)
{
	for (int i = 0; i < 2; i++)
	{
		gameover_F[i].pos = D3DXVECTOR2(470.f + i * 50.f, 250.f);
		gameover_F[i].size = D3DXVECTOR2(65.f, 65.f);
		gameover_F[i].texture = LoadTexture("data/TEXTURE/number.png");
		gameover_F[i].u = 0.f;
		gameover_F[i].v = 0.f;
		gameover_F[i].drawflag = false;
	}

	return S_OK;
}

//-----終了処理
void UninitGameOverF(void)
{

}

//-----更新処理
void UpdateGameOverF(void)
{

	MAP_PLAYER* map_player = GetMapPlayer();
	gameover_f.floornum = map_player->floor;

	if (gameover_f.floornum < 10)
	{
		gameover_F[0].drawflag = false;
		gameover_F[1].drawflag = true;
	}
	if (gameover_f.floornum >= 10)
	{
		gameover_F[0].drawflag = true;
		gameover_F[1].drawflag = true;
	}

	for (int i = 1; i < 5; i++)
	{
		if (gameover_f.floornum == i)
		{
			gameover_F[1].u = 0.2f * i;
			gameover_F[1].v = 0.f;
		}
	}
	for (int i = 5; i < 10; i++)
	{
		if (gameover_f.floornum == i)
		{
			gameover_F[1].u = 0.2f * i;
			gameover_F[1].v = 0.5f;
		}
	}
	for (int i = 10; i < 20; i++)
	{
		if (gameover_f.floornum == i)
		{
			gameover_F[0].u = 0.2f;
			gameover_F[0].v = 0.f;
		}
	}
	for (int i = 10; i < 15; i++)
	{
		if (gameover_f.floornum == i)
		{
			gameover_F[1].u = 0.2f * i;
			gameover_F[1].v = 0.f;
		}
	}
	for (int i = 15; i < 20; i++)
	{
		if (gameover_f.floornum == i)
		{
			gameover_F[1].u = 0.2f * i;
			gameover_F[1].v = 0.5f;
		}
	}
	for (int i = 20; i < 30; i++)
	{
		if (gameover_f.floornum == i)
		{
			gameover_F[0].u = 0.4f;
			gameover_F[0].v = 0.f;
		}
	}
	for (int i = 20; i < 25; i++)
	{
		if (gameover_f.floornum == i)
		{
			gameover_F[1].u = 0.2f * i;
			gameover_F[1].v = 0.f;
		}
	}
	for (int i = 25; i < 30; i++)
	{
		if (gameover_f.floornum == i)
		{
			gameover_F[1].u = 0.2f * i;
			gameover_F[1].v = 0.5f;
		}
	}
}

//-----描画処理
void DrawGameOverF(void)
{
	for (int i = 0; i < 2; i++)
	{
		if (gameover_F[i].drawflag == true)
			DrawSpriteLeftTop(gameover_F[i].texture, gameover_F[i].pos.x, gameover_F[i].pos.y, gameover_F[i].size.x, gameover_F[i].size.y,
				gameover_F[i].u, gameover_F[i].v, 0.2f, 0.5f);
	}
}