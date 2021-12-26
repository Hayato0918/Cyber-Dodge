//バナーアイコン処理 [banner_icon.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}BANNER_ICON;

//-----プロトタイプ宣言
HRESULT InitBannerIcon(void);
void UninitBannerIcon(void);
void UpdateBannerIcon(void);
void DrawBannerIcon(void);