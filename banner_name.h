//バナー名前処理 [banner_name.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}BANNER_NAME;

//-----プロトタイプ宣言
HRESULT InitBannerName(void);
void UninitBannerName(void);
void UpdateBannerName(void);
void DrawBannerName(void);