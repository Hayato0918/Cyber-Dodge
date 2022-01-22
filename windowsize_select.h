//ウィンドウサイズ選択処理 [windowsize_select.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int count;

	int x;
	int y;
}WINDOWSIZE_SELECT;

//-----プロトタイプ宣言
HRESULT InitWindowSizeSelect(void);
void UninitWindowSizeSelect(void);
void UpdateWindowSizeSelect(void);
void DrawWindowSizeSelect(void);

WINDOWSIZE_SELECT* GetWindowSizeSelect();