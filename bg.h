//背景処理 [bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}BG;

//-----プロトタイプ宣言
HRESULT InitBG(void);
void UninitBG(void);
void UpdateBG(void);
void DrawBG(void);