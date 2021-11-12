//バグゲージ処理 [bug.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	int gaugeonce;		//ゲージの拡大(x5)

	D3DXVECTOR2 pos;
	D3DXVECTOR2 framesize;
	int frametexture;

	D3DXVECTOR2 gaugesize;
	int gaugetexture;
}BUG;

//-----プロトタイプ宣言
HRESULT InitBug(void);
void UninitBug(void);
void UpdateBug(void);
void DrawBug(void);

BUG* GetBug();