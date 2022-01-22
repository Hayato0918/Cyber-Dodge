//���l�}�X���� [shop.cpp]
#include "shop.h"
//���l�}�X���e.h
#include "shop_bg.h"
#include "shop_card.h"
#include "shop_gold.h"
#include "shop_reload.h"
#include "shop_exit.h"
#include "shop_select.h"

HRESULT InitShop(void)
{
	InitShopBg();
	InitShopCard();
	InitShopGold();
	InitShopReload();
	InitShopExit();
	InitShopSelect();

	return S_OK;
}

void UninitShop(void)
{
	UninitShopBg();
	UninitShopCard();
	UninitShopGold();
	UninitShopReload();
	UninitShopExit();
	UninitShopSelect();
}

void UpdateShop(void)
{
	UpdateShopBg();
	UpdateShopCard();
	UpdateShopGold();
	UpdateShopReload();
	UpdateShopExit();
	UpdateShopSelect();
}

void DrawShop(void)
{
	DrawShopBg();
	DrawShopCard();
	DrawShopGold();
	DrawShopReload();
	DrawShopExit();
	DrawShopSelect();
}