//ãxåeÉ}ÉXîwåièàóù [rest_bg.cpp]
#include "rest_bg.h"
//ÉVÉXÉeÉÄ.h
#include "texture.h"
#include "sprite.h"

REST_BG rest_bg;

HRESULT InitRestBG(void)
{
	rest_bg.pos = D3DXVECTOR2(0.0f, 0.0f);
	rest_bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	rest_bg.texture = LoadTexture("data/TEXTURE/test/black.png");

	return S_OK;
}

void UninitRestBG(void)
{

}

void UpdateRestBG(void)
{

}

void DrawRestBG(void)
{
	DrawSpriteLeftTop(rest_bg.texture, rest_bg.pos.x, rest_bg.pos.y, rest_bg.size.x, rest_bg.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}