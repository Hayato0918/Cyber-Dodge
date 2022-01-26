//ランキング_フロア処理 [ranking_floor.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	int floornum;
	int texture;
	bool saveflag;
}RANKING_FLOORNUM;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	float u, v;
	bool drawflag;
}RANKING_FLOOR;

//-----プロトタイプ宣言
HRESULT InitRankingFloor(void);
void UninitRankingFloor(void);
void UpdateRankingFloor(void);
void DrawRankingFloor(void);

RANKING_FLOORNUM* GetRankingFloorNum();
RANKING_FLOOR* GetRankingFloor();