//セーブ選択処理 [map_save_select.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int count;
	bool drawflag;
	int sound;
}MAPSAVE_SELECT;


//-----プロトタイプ宣言
HRESULT InitMapSaveSelect(void);
void UninitMapSaveSelect(void);
void UpdateMapSaveSelect(void);
void DrawMapSaveSelect(void);

MAPSAVE_SELECT* GetMapSaveSelect(void);