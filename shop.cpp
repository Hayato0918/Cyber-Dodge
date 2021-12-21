//商人マス処理 [shop.cpp]
#include "shop.h"
//商人マス内容.h
#include "shop_bg.h"
#include "shop_card.h"
#include "shop_delete.h"
#include "shop_gold.h"
#include "shop_reload.h"
#include "shop_exit.h"
#include "shop_select.h"

void InitShop(void)
{
	InitShopBg();
	InitShopCard();
	InitShopDelete();
	InitShopGold();
	InitShopReload();
	InitShopExit();
	InitShopSelect();
}

void UninitShop(void)
{
	UninitShopBg();
	UninitShopCard();
	UninitShopDelete();
	UninitShopGold();
	UninitShopReload();
	UninitShopExit();
	UninitShopSelect();
}

void UpdateShop(void)
{
	UpdateShopBg();
	UpdateShopCard();
	UpdateShopDelete();
	UpdateShopGold();
	UpdateShopReload();
	UpdateShopExit();
	UpdateShopSelect();
}

void DrawShop(void)
{
	DrawShopBg();
	DrawShopCard();
	DrawShopDelete();
	DrawShopGold();
	DrawShopReload();
	DrawShopExit();
	DrawShopSelect();
}