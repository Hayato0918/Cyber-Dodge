//浮遊情報体処理 [hujyou.h]

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
}HUJYOU;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
}HUJYOUPOINT;

//-----プロトタイプ宣言
void InitHujyou(void);
void UninitHujyou(void);
void UpdateHujyou(void);
void DrawHujyou(void);

HUJYOU* GetHujyou();
HUJYOUPOINT* GetHujyouPoint();