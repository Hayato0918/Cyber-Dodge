//蘇る増幅装置処理 [yomigaeru.h]

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
}YOMIGAERU;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
	int count;
	int minus;				//選択肢のマス間の距離
}YOMIGAERUPOINT;

//-----プロトタイプ宣言
void InitYomigaeru(void);
void UninitYomigaeru(void);
void UpdateYomigaeru(void);
void DrawYomigaeru(void);