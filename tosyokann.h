//電脳図書館処理 [tosyokann.h]

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
}TOSYOKANN;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
	int count;
	int minus;				//選択肢のマス間の距離
}TOSYOKANNPOINT;

//-----プロトタイプ宣言
void InitTosyokann(void);
void UninitTosyokann(void);
void UpdateTosyokann(void);
void DrawTosyokann(void);

TOSYOKANN* GetTosyo();
TOSYOKANNPOINT* GetTosyPoint();