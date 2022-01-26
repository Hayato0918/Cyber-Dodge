//ランキングフロア処理 [ranking_floor.cpp]
#include "ranking_floor.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include "save.h"

//-----マクロ定義

//-----プロトタイプ宣言
RANKING_FLOOR ranking_floor[4][2];
RANKING_FLOORNUM ranking_floornum[4];

//-----グローバル変数
int ranking_floortexture;

//-----初期化処理
HRESULT InitRankingFloor(void)
{
	for (int y = 0; y < 4; y++)
	{
		for (int i = 0; i < 2; i++)
		{
			ranking_floor[y][i].pos = D3DXVECTOR2(675.f + i * 50.f, 180.f + 160.f * y);
			ranking_floor[y][i].size = D3DXVECTOR2(65.f, 65.f);
			ranking_floor[y][i].drawflag = false;
		}
	}

	if (ranking_floornum[3].saveflag == true)
		ranking_floornum[3].saveflag = false;

	ranking_floortexture = LoadTexture("data/TEXTURE/number.png");

	FloorLoad();

	return S_OK;
}

//-----終了処理
void UninitRankingFloor(void)
{

}

//-----更新処理
void UpdateRankingFloor(void)
{
	for (int i = 0; i < 4; i++)
	{

		if (ranking_floornum[i].floornum < 10)
		{
			ranking_floor[i][0].drawflag = false;
			ranking_floor[i][1].drawflag = true;
		}
		if (ranking_floornum[i].floornum >= 10)
		{
			ranking_floor[i][0].drawflag = true;
			ranking_floor[i][1].drawflag = true;
		}

		for (int i = 1; i < 5; i++)
		{
			if (ranking_floornum[i].floornum == i)
			{
				ranking_floor[i][1].u = 0.2f * i;
				ranking_floor[i][1].v = 0.f;
			}
		}
		for (int i = 5; i < 10; i++)
		{
			if (ranking_floornum[i].floornum == i)
			{
				ranking_floor[i][1].u = 0.2f * i;
				ranking_floor[i][1].v = 0.5f;
			}
		}
		for (int i = 10; i < 20; i++)
		{
			if (ranking_floornum[i].floornum == i)
			{
				ranking_floor[i][0].u = 0.2f;
				ranking_floor[i][0].v = 0.f;
			}
		}
		for (int i = 10; i < 15; i++)
		{
			if (ranking_floornum[i].floornum == i)
			{
				ranking_floor[i][1].u = 0.2f * i;
				ranking_floor[i][1].v = 0.f;
			}
		}
		for (int i = 15; i < 20; i++)
		{
			if (ranking_floornum[i].floornum == i)
			{
				ranking_floor[i][1].u = 0.2f * i;
				ranking_floor[i][1].v = 0.5f;
			}
		}
		for (int i = 20; i < 30; i++)
		{
			if (ranking_floornum[i].floornum == i)
			{
				ranking_floor[i][0].u = 0.4f;
				ranking_floor[i][0].v = 0.f;
			}
		}
		for (int i = 20; i < 25; i++)
		{
			if (ranking_floornum[i].floornum == i)
			{
				ranking_floor[i][1].u = 0.2f * i;
				ranking_floor[i][1].v = 0.f;
			}
		}
		for (int i = 25; i < 30; i++)
		{
			if (ranking_floornum[i].floornum == i)
			{
				ranking_floor[i][1].u = 0.2f * i;
				ranking_floor[i][1].v = 0.5f;
			}
		}
	}
}

//-----描画処理
void DrawRankingFloor(void)
{
	for (int i = 0; i < 2; i++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (ranking_floor[y][i].drawflag == true)
				DrawSpriteLeftTop(ranking_floortexture, ranking_floor[y][i].pos.x, ranking_floor[y][i].pos.y, ranking_floor[y][i].size.x, ranking_floor[y][i].size.y,
					ranking_floor[y][i].u, ranking_floor[y][i].v, 0.2f, 0.5f);
		}
	}
}

RANKING_FLOORNUM* GetRankingFloorNum()
{
	return &ranking_floornum[0];
}