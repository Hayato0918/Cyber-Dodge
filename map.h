//マップ処理 [map.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
}MAP;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int scene;
}MAPSEN;

//-----プロトタイプ宣言
HRESULT InitMap(void);
void UninitMap(void);
void UpdateMap(void);
void DrawMap(void);
MAP* GetMap(void);