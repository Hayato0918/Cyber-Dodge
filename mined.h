//マインドブルーム処理 [mined.h]

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
}MINED;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
}MINEDPOINT;

//-----プロトタイプ宣言
void InitMined(void);
void UninitMined(void);
void UpdateMined(void);
void DrawMined(void);