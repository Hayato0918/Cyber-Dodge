//休憩マス背景処理 [rest_bg.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
}REST_BG;

//-----プロトタイプ宣言
HRESULT InitRestBG(void);
void UninitRestBG(void);
void UpdateRestBG(void);
void DrawRestBG(void);