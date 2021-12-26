//休憩マス一枚絵処理 [rest_picture.h]
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
}REST_PICTURE;

//-----プロトタイプ宣言
HRESULT InitRestPicture(void);
void UninitRestPicture(void);
void UpdateRestPicture(void);
void DrawRestPicture(void);