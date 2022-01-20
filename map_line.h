//マップ移線処理 [map_line.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;

	int randomcode;
}MAP_LINE;

//-----プロトタイプ宣言
HRESULT InitMapLine(void);
void UninitMapLine(void);
void UpdateMapLine(void);
void DrawMapLine(void);

MAP_LINE* GetMapLine();