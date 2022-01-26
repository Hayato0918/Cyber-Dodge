//ランキング_背景処理 [ranking_bg.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}RANKING_BG;

//-----プロトタイプ宣言
HRESULT InitRankingBG(void);
void UninitRankingBG(void);
void UpdateRankingBG(void);
void DrawRankingBG(void);