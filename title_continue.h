//タイトルコンテニューボタン処理 [title_continue.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}TITLE_CONTINUE;

//-----プロトタイプ宣言
HRESULT InitTitleContinue(void);
void UninitTitleContinue(void);
void UpdateTitleContinue(void);
void DrawTitleContinue(void);

TITLE_CONTINUE* GetTitleContinue();