//商人マスゴールド消費処理[shop_gold.cpp]
#include "shop_gold.h"

#include "shop.h"
#include "shop_card.h"

#include "texture.h"
#include "sprite.h"

SHOP_GOLD shop_gold[shop_skill];	//スキルカード
SHOP_GOLDTEXTURE shop_goldtexture;

HRESULT InitShopGold()
{
	SHOP_CARD* shop_card = GetShopCard();

	for (int i = 0; i < shop_skill; i++)
	{
		shop_gold[i].pos = D3DXVECTOR2(shop_card[i].pos.x, shop_card[i].pos.y + shop_card[i].size.y + SCREEN_HEIGHT * 0.033333f);
		shop_gold[i].size = D3DXVECTOR2(shop_card[i].size.x, SCREEN_HEIGHT * 0.055555f);	//200,50
		shop_gold[i].v = 0.f;
		shop_gold[i].gold = 0;
	}

	return S_OK;
}

void UninitShopGold()
{

}

void UpdateShopGold()
{
	SHOP_CARD* shop_card = GetShopCard();

	for (int i = 0; i < shop_skill; i++)
	{
		//割り当てられたcodeに対応したテクスチャを表示
		if (shop_card[i].code == 1)
		{
			shop_gold[i].gold = 220;
			shop_gold[i].v = 0.142857f;
		}
		if (shop_card[i].code == 2)
		{
			shop_gold[i].gold = 250;
			shop_gold[i].v = 0.285714f;
		}
		if (shop_card[i].code == 3)
		{
			shop_gold[i].gold = 220;
			shop_gold[i].v = 0.142857f;
		}
		if (shop_card[i].code == 4)
		{
			shop_gold[i].gold = 220;
			shop_gold[i].v = 0.142857f;
		}
		if (shop_card[i].code == 5)
		{
			shop_gold[i].gold = 220;
			shop_gold[i].v = 0.142857f;
		}
		if (shop_card[i].code == 6)
		{
			shop_gold[i].gold = 220;
			shop_gold[i].v = 0.142857f;
		}
		if (shop_card[i].code == 7)
		{
			shop_gold[i].gold = 200;
			shop_gold[i].v = 0.f;
		}
		if (shop_card[i].code == 8)
		{
			shop_gold[i].gold = 300;
			shop_gold[i].v = 0.714285f;
		}
		if (shop_card[i].code == 9)
		{
			shop_gold[i].v = 0.142857f;
			shop_gold[i].gold = 220;
		}
		if (shop_card[i].code == 10)
		{
			shop_gold[i].gold = 300;
			shop_gold[i].v = 0.714285f;
		}
		if (shop_card[i].code == 11)
		{
			shop_gold[i].gold = 200;
			shop_gold[i].v = 0.f;
		}
		if (shop_card[i].code == 12)
		{
			shop_gold[i].gold = 220;
			shop_gold[i].v = 0.142857f;
		}
		if (shop_card[i].code == 13)
		{
			shop_gold[i].gold = 250;
			shop_gold[i].v = 0.285714f;
		}
		if (shop_card[i].code == 14)
		{
			shop_gold[i].gold = 200;
			shop_gold[i].v = 0.f;
		}
		//if (shop_card[i].code == 15)
		//{
		//	shop_gold[i].gold = 280;
		//	shop_gold[i].v = 0.571428f;
		//}
		if (shop_card[i].code == 16)
		{
			shop_gold[i].gold = 200;
			shop_gold[i].v = 0.f;
		}
		if (shop_card[i].code == 17)
		{
			shop_gold[i].gold = 250;
			shop_gold[i].v = 0.285714f;
		}
		if (shop_card[i].code == 18)
		{
			shop_gold[i].gold = 250;
			shop_gold[i].v = 0.285714f;
		}
		if (shop_card[i].code == 19)
		{
			shop_gold[i].gold = 270;
			shop_gold[i].v = 0.428571f;
		}
		if (shop_card[i].code == 20)
		{
			shop_gold[i].gold = 250;
			shop_gold[i].v = 0.285714f;
		}
		if (shop_card[i].code == 21)
		{
			shop_gold[i].gold = 220;
			shop_gold[i].v = 0.142857f;
		}
		if (shop_card[i].code == 22)
		{
			shop_gold[i].gold = 220;
			shop_gold[i].v = 0.142857f;
		}
		if (shop_card[i].code == 23)
		{
			shop_gold[i].gold = 250;
			shop_gold[i].v = 0.285714f;
		}
		if (shop_card[i].code == 24)
		{
			shop_gold[i].gold = 220;
			shop_gold[i].v = 0.142857f;
		}
		if (shop_card[i].code == 25)
		{
			shop_gold[i].gold = 400;
			shop_gold[i].v = 0.857142f;
		}
		if (shop_card[i].code == 26)
		{
			shop_gold[i].gold = 250;
			shop_gold[i].v = 0.285714f;
		}
	}
}

void DrawShopGold()
{
	for (int i = 0; i < shop_skill; i++)
		DrawSpriteLeftTop(shop_goldtexture.texture, shop_gold[i].pos.x, shop_gold[i].pos.y, shop_gold[i].size.x, shop_gold[i].size.y,
			0.0f, shop_gold[i].v, 1.0f, 0.142857f);
}

SHOP_GOLD* GetShopGold()
{
	return &shop_gold[0];
}

SHOP_GOLDTEXTURE* GetShopGoldTexture()
{
	return &shop_goldtexture;
}