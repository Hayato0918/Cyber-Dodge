//休憩マス退出処理 [rest_exit.h]
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
}REST_EXIT;

//-----プロトタイプ宣言
HRESULT InitRestExit(void);
void UninitRestExit(void);
void UpdateRestExit(void);
void DrawRestExit(void);

REST_EXIT* GetRestExit();