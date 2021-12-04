//マップ移動処理 [map_hack.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;			//メニューの枠
	D3DXVECTOR2 frame_pos;
	D3DXVECTOR2 frame_size;
	int frametexture;				//選択する際の枠

	int UDcount;		//SetMapに入れる数字が入る変数
	bool isUse;

}MAP_HACK;

//-----プロトタイプ宣言
HRESULT InitMapHack(void);
void UninitMapHack(void);
void UpdateMapHack(void);
void DrawMapHack(void);

MAP_HACK* GetMapHack();