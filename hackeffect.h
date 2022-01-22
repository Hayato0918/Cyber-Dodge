//ハッキングエフェクト処理 [hackeffect.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v;
	int texture;
	bool drawflag;
}HACKEFFECT;

//-----プロトタイプ宣言
HRESULT InitHackEffect(void);
void UninitHackEffect(void);
void UpdateHackEffect(void);
void DrawHackEffect(void);