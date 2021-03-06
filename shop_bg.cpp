//???l?}?X?w?i????[shop_bg.cpp]
#include "shop_bg.h"

#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"
#include "sound.h"

SHOP_BG shop_bg;

HRESULT InitShopBg()
{
	shop_bg.pos = D3DXVECTOR2(0.0f, 0.0f);
	shop_bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	shop_bg.sound = LoadSound("data/BGM/shopBGM.wav");

	PlaySound(shop_bg.sound, -1);

	return S_OK;
}

void UninitShopBg()
{
	StopSoundAll();
}

void UpdateShopBg()
{

}

void DrawShopBg()
{
	DrawSpriteLeftTop(shop_bg.texture, shop_bg.pos.x, shop_bg.pos.y, shop_bg.size.x, shop_bg.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}


SHOP_BG* GetShopBG()
{
	return &shop_bg;
}