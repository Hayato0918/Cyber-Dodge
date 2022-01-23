//マップフロア処理 [map_floor.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;

	int floornum;
}MAP_FLOORBG;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	float u, v;
	bool drawflag;
}MAP_FLOOR;

//-----プロトタイプ宣言
HRESULT InitMapFloor(void);
void UninitMapFloor(void);
void UpdateMapFloor(void);
void DrawMapFloor(void);