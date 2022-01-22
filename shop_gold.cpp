//商人マスゴールド消費処理[shop_gold.cpp]
#include "shop_gold.h"

#include "shop.h"
#include "shop_card.h"

#include "texture.h"
#include "sprite.h"

SHOP_GOLD shop_gold[shop_skill];	//スキルカード

HRESULT InitShopGold()
{
	SHOP_CARD* shop_card = GetShopCard();

	for (int i = 0; i < shop_skill; i++)
	{
		shop_gold[i].pos = D3DXVECTOR2(shop_card[i].pos.x, shop_card[i].pos.y + shop_card[i].size.y + SCREEN_HEIGHT * 0.033333f);
		shop_gold[i].size = D3DXVECTOR2(shop_card[i].size.x, SCREEN_HEIGHT * 0.055555f);
		shop_gold[i].texture = LoadTexture("data/TEXTURE/test/yellow.png");
	}

	return S_OK;
}

void UninitShopGold()
{

}

void UpdateShopGold()
{

}

void DrawShopGold()
{
	for (int i = 0; i < shop_skill; i++)
		DrawSpriteLeftTop(shop_gold[i].texture, shop_gold[i].pos.x, shop_gold[i].pos.y, shop_gold[i].size.x, shop_gold[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}