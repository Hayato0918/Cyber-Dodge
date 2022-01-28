//名前決め_入力場所処理 [name_input.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int wardtexture;
}NAME_INPUTFRAME;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u;
	float v;
	float uw;
	float vh;
	int texture;
	bool drawflag;
}NAME_INPUTWARD;

//-----プロトタイプ宣言
HRESULT InitNameInput(void);
void UninitNameInput(void);
void UpdateNameInput(void);
void DrawNameInput(void);

NAME_INPUTWARD* GetNameInputWard();
NAME_INPUTFRAME* GetNameInput();