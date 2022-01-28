//バナー背景処理 [banner_bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}BANNER_BG;

//-----プロトタイプ宣言
HRESULT InitBannerBG(void);
void UninitBannerBG(void);
void UpdateBannerBG(void);
void DrawBannerBG(void);

BANNER_BG* GetBannerBG();