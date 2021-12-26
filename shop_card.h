//商人マススキルカード処理 [shop_card.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int code;
	bool drawflag;
}SHOP_CARD;

HRESULT InitShopCard(void);
void UninitShopCard(void);
void UpdateShopCard(void);
void DrawShopCard(void);

SHOP_CARD* GetShopCard(void);