//ゲームオーバースコア処理 [gameover_スコア.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	int scorenum;
	int scoreu;
	float scorev;
	int a, b, c, d;
	int gold;
}GAMEOVER_SCORE;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	float u, v;
	bool drawflag;
}GAMEOVER_SCORENUM;

//-----プロトタイプ宣言
HRESULT InitGameOverScore(void);
void UninitGameOverScore(void);
void UpdateGameOverScore(void);
void DrawGameOverScore(void);