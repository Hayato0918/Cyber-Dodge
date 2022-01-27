//タイトルランキングボタン処理 [title_ranking.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int sound;
}TITLE_RANKING;

//-----プロトタイプ宣言
HRESULT InitTitleRanking(void);
void UninitTitleRanking(void);
void UpdateTitleRanking(void);
void DrawTitleRanking(void);

TITLE_RANKING* GetTitleRanking(void);