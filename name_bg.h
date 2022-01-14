//名前決め_背景処理 [name_bg.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}NAME_BG;

//-----プロトタイプ宣言
HRESULT InitNameBG(void);
void UninitNameBG(void);
void UpdateNameBG(void);
void DrawNameBG(void);