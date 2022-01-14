//設定_背景処理 [option_bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}OPTION_BG;


//-----プロトタイプ宣言
HRESULT InitOptionBG(void);
void UninitOptionBG(void);
void UpdateOptionBG(void);
void DrawOptionBG(void);