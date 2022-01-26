//ランキング_名前処理 [ranking_name.cpp]
#include "ranking_name.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "Texture.h"
#include "sprite.h"
#include "sound.h"
#include "save.h"
#include "ranking_score.h"
#include "ranking_floor.h"

//-----定数定義

//-----構造体宣言

//-----プロトタイプ宣言
RANKING_NAME ranking_name[4][8];
RANKING_NAMENUM ranking_namenum[8];
RANKING_NAMECOUNT ranking_namecount;

//-----グローバル変数の定義
int rankingnametexture;

//-----初期化関数
HRESULT InitRankingName(void)
{
	for (int i = 0; i < 8; i++)
	{
		for (int y = 0; y < 4; y++)
		{
			ranking_name[y][i].pos = D3DXVECTOR2(350.f + 30.f * i, 180.f + 160.f * y);
			ranking_name[y][i].size = D3DXVECTOR2(40.f, 60.f);
		}
	}

	NameLoad();

	for (int i = 0; i < 8; i++)
	{
		if (ranking_namecount.count == 1)
		{
			ranking_name[0][i].u = ranking_namenum[i].u;
			ranking_name[0][i].drawflag = ranking_namenum[i].drawflag;
		}
		if (ranking_namecount.count == 2)
		{
			ranking_name[1][i].u = ranking_namenum[i].u;
			ranking_name[1][i].drawflag = ranking_namenum[i].drawflag;
		}
		if (ranking_namecount.count == 3)
		{
			ranking_name[2][i].u = ranking_namenum[i].u;
			ranking_name[2][i].drawflag = ranking_namenum[i].drawflag;
		}
		if (ranking_namecount.count == 4)
		{
			ranking_name[3][i].u = ranking_namenum[i].u;
			ranking_name[3][i].drawflag = ranking_namenum[i].drawflag;
		}
	}



	rankingnametexture = LoadTexture("data/TEXTURE/name/ward.png");

	return S_OK;
}

//-----終了処理関数
void UninitRankingName(void)
{

}

//-----更新処理をする関数
void UpdateRankingName(void)
{
	RANKING_SCORENUM* ranking_scorenum = GetRankingScoreNum();
	RANKING_FLOORNUM* ranking_floor = GetRankingFloorNum();

	for (int i = 0; i < 4; i++)
	{
		if (ranking_scorenum[i + 1].saveflag == true)
		{
			if (ranking_scorenum[i].gold < ranking_scorenum[i + 1].gold)
			{
				int scoreswap;
				scoreswap = ranking_scorenum[i + 1].gold;
				ranking_scorenum[i + 1].gold = ranking_scorenum[i].gold;
				ranking_scorenum[i].gold = scoreswap;

				int floorswap;
				floorswap = ranking_floor[i + 1].floornum;
				ranking_floor[i + 1].floornum = ranking_floor[i].floornum;
				ranking_floor[i].floornum = floorswap;

				int nameswap;
				bool namedrawflag;
				for (int j = 0; j < 8; j++)
				{
					namedrawflag = ranking_name[i + 1][j].drawflag;
					ranking_name[i + 1][j].drawflag = ranking_name[i][j].drawflag;
					ranking_name[i][j].drawflag = namedrawflag;

					nameswap = ranking_name[i + 1][j].u;
					ranking_name[i + 1][j].u = ranking_name[i][j].u;
					ranking_name[i][j].u = nameswap;
				}
			}
		}
	}
}

//-----描画処理関数
void DrawRankingName(void)
{
	for(int i = 0; i < 8; i++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (ranking_name[y][i].drawflag == true)
				DrawSpriteLeftTop(rankingnametexture, ranking_name[y][i].pos.x, ranking_name[y][i].pos.y, ranking_name[y][i].size.x, ranking_name[y][i].size.y, ranking_name[y][i].u, 0.f, 0.037037037f, 1.0f);
		}
	}
}

RANKING_NAMENUM* GetRankingNameNum()
{
	return &ranking_namenum[0];
}

RANKING_NAMECOUNT* GetRankingCount()
{
	return &ranking_namecount;
}