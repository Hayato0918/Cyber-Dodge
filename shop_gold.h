//���l�}�X�S�[���h����� [shop_gold.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
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