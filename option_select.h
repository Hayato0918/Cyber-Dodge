//設定選択処理 [option_select.h]
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
	int sound;
}OPTION_SELECT;

//-----プロトタイプ宣言
HRESULT InitOptionSelect(void);
void UninitOptionSelect(void);
void UpdateOptionSelect(void);
void DrawOptionSelect(void);

OPTION_SELECT* GetOptionSelect();