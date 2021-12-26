//è§êlÉ}ÉXîwåièàóù[shop_bg.cpp]
#include "shop_bg.h"

#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

SHOP_BG shop_bg;

HRESULT InitShopBg()
{
	shop_bg.pos = D3DXVECTOR2(0.0f, 0.0f);
	shop_bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	shop_bg.texture = LoadTexture("data/TEXTURE/test/black.png");

	return S_OK;
}

void UninitShopBg()
{

}

void UpdateShopBg()
{

}

void DrawShopBg()
{
	DrawSpriteLeftTop(shop_bg.texture, shop_bg.pos.x, shop_bg.pos.y, shop_bg.size.x, shop_bg.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}