//休憩マス選択処理 [rest_select.h]
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
	int count;
}REST_SELECT;


//-----プロトタイプ宣言
HRESULT InitRestSelect(void);
void UninitRestSelect(void);
void UpdateRestSelect(void);
void DrawRestSelect(void);

REST_SELECT* GetRestSelect();