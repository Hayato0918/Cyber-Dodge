//ランキング_スコア処理 [ranking_score.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v;
	bool drawflag;
}RANKING_SCORE;

typedef struct
{
	int gold;
	int texture;
	int a, b, c, d;	//goldの1000の位、100の位、10の位、1の位
	bool saveflag;
}RANKING_SCORENUM;

//-----プロトタイプ宣言
HRESULT InitRankingScore(void);
void UninitRankingScore(void);
void UpdateRankingScore(void);
void DrawRankingScore(void);

RANKING_SCORENUM* GetRankingScoreNum();