//商人マス選択処理 [shop_select.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int xcount;
	int ycount;
}SHOP_SELECT;

void InitShopSelect(void);
void UninitShopSelect(void);
void UpdateShopSelect(void);
void DrawShopSelect(void);

SHOP_SELECT* GetShopSelect();