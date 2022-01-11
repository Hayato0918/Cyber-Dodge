//バグゲージ処理 [bug.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	int gaugeonce;		//ゲージの拡大(x8)

	D3DXVECTOR2 framepos;
	D3DXVECTOR2 framesize;
	int frametexture;
	int breaktexture;
	bool breakflag;

	D3DXVECTOR2 gaugepos;
	D3DXVECTOR2 gaugesize;
	int drawnum;
	int gaugetexture;
	float decreasetime;

	int numbertexture;
}BUG;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	bool drawflag;
}BUGGAUGE;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u;
	float v;
	float uw;
	float vh;
	bool drawflag;
}BUGNUMBER;

//-----プロトタイプ宣言
HRESULT InitBugIncrease(void);
void UninitBugIncrease(void);
void UpdateBugIncrease(void);
void DrawBugIncrease(void);

BUG* GetBugIncrease();
BUGGAUGE* GetBugGauge();