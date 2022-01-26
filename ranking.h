//ランキング処理 [ranking.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----プロトタイプ宣言
HRESULT InitRanking(void);
void UninitRanking(void);
void UpdateRanking(void);
void DrawRanking(void);