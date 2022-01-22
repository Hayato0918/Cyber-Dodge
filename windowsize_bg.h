//ウィンドウサイズ_背景処理 [windowsize_bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}WINDOWSIZE_BG;


//-----プロトタイプ宣言
HRESULT InitWindowSizeBG(void);
void UninitWindowSizeBG(void);
void UpdateWindowSizeBG(void);
void DrawWindowSizeBG(void);