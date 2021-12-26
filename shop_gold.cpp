//商人マスゴールド消費処理[shop_gold.cpp]
#include "shop_gold.h"

#include "shop.h"
#include "shop_card.h"
#include "shop_delete.h"

#include "texture.h"
#include "sprite.h"

SHOP_GOLD shop_gold[shop_skill + 1];	//スキルカード+スキル削除

HRESULT InitShopGold()
{
	SHOP_CARD* shop_card = GetShopCard();
	SHOP_DELETE* shop_delete = GetShopDelete();

	for (int i = 0; i < shop_skill; i++)
	{
		shop_gold[i].pos = D3DXVECTOR2(shop_card[i].pos.x, shop_card[i].pos.y + shop_card[i].size.y + 30.0f);
		shop_gold[i].size = D3DXVECTOR2(shop_card[i].size.x, 50.0f);
		shop_gold[i].texture = LoadTexture("data/TEXTURE/test/yellow.png");
	}

	shop_gold[shop_skill].pos = D3DXVECTOR2(shop_delete->pos.x, shop_delete->pos.y + shop_delete->size.y + 30.0f);
	shop_gold[shop_skill].size = D3DXVECTOR2(shop_delete->size.x, 50.0f);
	shop_gold[shop_skill].texture = LoadTexture("data/TEXTURE/test/yellow.png");

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

	DrawSpriteLeftTop(shop_gold[shop_skill].texture, shop_gold[shop_skill].pos.x, shop_gold[shop_skill].pos.y, 
							shop_gold[shop_skill].size.x, shop_gold[shop_skill].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}