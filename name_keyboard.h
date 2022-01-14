//名前決め_キーボード処理 [name_keyboard.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int wardnum;
}NAME_KEYBOARD;

//-----プロトタイプ宣言
HRESULT InitNameKeyboard(void);
void UninitNameKeyboard(void);
void UpdateNameKeyboard(void);
void DrawNameKeyboard(void);

NAME_KEYBOARD* GetNameKeyboard(void);