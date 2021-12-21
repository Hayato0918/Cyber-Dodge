//商人マススキル削除処理[shop_delete.cpp]
#include "shop_delete.h"

#include "texture.h"
#include "sprite.h"

SHOP_DELETE shop_delete;

void InitShopDelete()
{
	shop_delete.pos = D3DXVECTOR2(160.0f, 525.0f);
	shop_delete.size = D3DXVECTOR2(300.0f, 250.0f);
	shop_delete.texture = LoadTexture("data/TEXTURE/test/red.png");
}

void UninitShopDelete()
{

}

void UpdateShopDelete()
{

}

void DrawShopDelete()
{
		DrawSpriteLeftTop(shop_delete.texture, shop_delete.pos.x, shop_delete.pos.y, shop_delete.size.x, shop_delete.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

SHOP_DELETE* GetShopDelete(void)
{
	return &shop_delete;
}