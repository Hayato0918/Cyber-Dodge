//休憩マス処理 [rest.h]

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
}REST;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
	int count;
}RESTPOINT;


//-----プロトタイプ宣言
void InitRest(void);
void UninitRest(void);
void UpdateRest(void);
void DrawRest(void);