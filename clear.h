//クリア処理 [clear.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}CLEAR;

//-----プロトタイプ宣言
HRESULT InitClear(void);
void UninitClear(void);
void UpdateClear(void);
void DrawClear(void);