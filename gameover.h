//ゲームオーバー処理 [gameover.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}GAMEOVER;

//-----プロトタイプ宣言
HRESULT InitGameOver(void);
void UninitGameOver(void);
void UpdateGameOver(void);
void DrawGameOver(void);