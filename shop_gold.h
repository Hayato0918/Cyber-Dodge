//商人マスゴールド消費処理 [shop_gold.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}SHOP_GOLD;

HRESULT InitShopGold(void);
void UninitShopGold(void);
void UpdateShopGold(void);
void DrawShopGold(void);