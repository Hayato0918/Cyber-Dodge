//セーブ背景処理 [map_save_bg.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool drawflag;
}MAPSAVE_BG;

//-----プロトタイプ宣言
HRESULT InitMapSaveBG(void);
void UninitMapSaveBG(void);
void UpdateMapSaveBG(void);
void DrawMapSaveBG(void);
MAPSAVE_BG* GetMapSaveBG();