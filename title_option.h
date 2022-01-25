//タイトル設定ボタン処理 [title_option.h]
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
}TITLE_OPTION;

//-----プロトタイプ宣言
HRESULT InitTitleOption(void);
void UninitTitleOption(void);
void UpdateTitleOption(void);
void DrawTitleOption(void);

TITLE_OPTION* GetTitleOption();