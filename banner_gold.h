//バナーお金処理 [banner_gold.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
}BANNER_GOLD;

typedef struct
{
	int texture;
	int a, b, c, d;	//goldの1000の位、100の位、10の位、1の位
}BANNER_GOLDNUM;

//-----プロトタイプ宣言
HRESULT InitBannerGold(void);
void UninitBannerGold(void);
void UpdateBannerGold(void);
void DrawBannerGold(void);