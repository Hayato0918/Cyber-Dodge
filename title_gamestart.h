//タイトルスタートボタン処理 [title_gamestart.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}TITLE_START;

//-----プロトタイプ宣言
HRESULT InitTitleStart(void);
void UninitTitleStart(void);
void UpdateTitleStart(void);
void DrawTitleStart(void);

TITLE_START* GetTitleStart();