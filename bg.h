//背景処理 [bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;

	//cl　センターラインの略
	D3DXVECTOR2 clPos;
	D3DXVECTOR2 clSize;
	int clTexture;
}BG;

//-----プロトタイプ宣言
HRESULT InitBG(void);
void UninitBG(void);
void UpdateBG(void);
void DrawBG(void);
BG* GetBG(void);
void SetCenterLine(float x);