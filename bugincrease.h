//バグゲージ処理 [bug.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	int gaugeonce;		//ゲージの拡大(x8)

	D3DXVECTOR2 pos;
	D3DXVECTOR2 framesize;
	int frametexture;

	D3DXVECTOR2 gaugesize;
	int gaugetexture;
}BUG;

//-----プロトタイプ宣言
HRESULT InitBugIncrease(void);
void UninitBugIncrease(void);
void UpdateBugIncrease(void);
void DrawBugIncrease(void);

BUG* GetBugIncrease();