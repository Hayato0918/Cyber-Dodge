//仮想研究空間 [event_kasoukenkyuukuukan.h]

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
}KASOU;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
	int count;
}KASOUPOINT;


//-----プロトタイプ宣言
void InitKasou(void);
void UninitKasou(void);
void UpdateKasou(void);
void DrawKasou(void);

KASOU* GetKasou();
KASOUPOINT* GetKasouPoint();