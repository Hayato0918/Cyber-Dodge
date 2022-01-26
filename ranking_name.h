//ランキング_なまえ処理 [ranking_name.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u;
	bool drawflag;
}RANKING_NAME;

typedef struct
{
	float u;
	bool drawflag;
	bool saveflag;
}RANKING_NAMENUM;

typedef struct
{
	int count;
}RANKING_NAMECOUNT;

//-----プロトタイプ宣言
HRESULT InitRankingName(void);
void UninitRankingName(void);
void UpdateRankingName(void);
void DrawRankingName(void);

RANKING_NAMENUM* GetRankingNameNum();
RANKING_NAMECOUNT* GetRankingCount();