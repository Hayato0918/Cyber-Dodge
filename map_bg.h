//マップbg処理 [map_bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int sound;
}MAP_BG;

//-----プロトタイプ宣言
HRESULT InitMapBG(void);
void UninitMapBG(void);
void UpdateMapBG(void);
void DrawMapBG(void);
MAP_BG* GetMapBG();