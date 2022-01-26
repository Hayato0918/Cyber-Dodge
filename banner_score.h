//バナースコア処理 [banner_score.h]

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
}BANNER_SCORE;

typedef struct
{
	int gold;
	int texture;
	int a, b, c, d;	//goldの1000の位、100の位、10の位、1の位
}BANNER_SCORENUM;

//-----プロトタイプ宣言
HRESULT InitBannerScore(void);
void UninitBannerScore(void);
void UpdateBannerScore(void);
void DrawBannerScore(void);