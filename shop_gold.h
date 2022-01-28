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
	float v;
	int gold;
}SHOP_GOLD;

typedef struct
{
	int texture;
}SHOP_GOLDTEXTURE;

HRESULT InitShopGold(void);
void UninitShopGold(void);
void UpdateShopGold(void);
void DrawShopGold(void);
SHOP_GOLD* GetShopGold();

SHOP_GOLDTEXTURE* GetShopGoldTexture();