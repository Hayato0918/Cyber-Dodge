//同業者の失敗処理 [dougyousya.h]

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
}DOUGYOUSYA;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
}DOUGYOUSYAPOINT;

//-----プロトタイプ宣言
void InitDougyousya(void);
void UninitDougyousya(void);
void UpdateDougyousya(void);
void DrawDougyousya(void);

DOUGYOUSYA* GetDougyousya();
DOUGYOUSYAPOINT* GetDougyousyaPoint();