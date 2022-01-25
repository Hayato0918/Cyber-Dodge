//名前決め_選択処理 [name_select.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int LRcount;
	int UDcount;
	int sound;
}NAME_SELECT;


//-----プロトタイプ宣言
HRESULT InitNameSelect(void);
void UninitNameSelect(void);
void UpdateNameSelect(void);
void DrawNameSelect(void);

NAME_SELECT* GetNameSelect();