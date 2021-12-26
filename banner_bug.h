//バナーバグゲージ処理 [banner_bug.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}BANNER_BUGFRAME;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}BANNER_BUGGAUGE;

//-----プロトタイプ宣言
HRESULT InitBannerBug(void);
void UninitBannerBug(void);
void UpdateBannerBug(void);
void DrawBannerBug(void);