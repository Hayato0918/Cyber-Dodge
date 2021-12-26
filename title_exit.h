//タイトル終了ボタン処理 [title_exit.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}TITLE_EXIT;

//-----プロトタイプ宣言
HRESULT InitTitleExit(void);
void UninitTitleExit(void);
void UpdateTitleExit(void);
void DrawTitleExit(void);

TITLE_EXIT* GetTitleExit();