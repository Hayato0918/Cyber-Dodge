//休憩マスステータス表示処理 [rest_status.h]
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
}REST_STATUS;

//-----プロトタイプ宣言
HRESULT InitRestStatus(void);
void UninitRestStatus(void);
void UpdateRestStatus(void);
void DrawRestStatus(void);