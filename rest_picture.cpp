//休憩マス一枚絵処理 [rest_picture.cpp]
#include "rest_picture.h"
//システム.h
#include "texture.h"
#include "sprite.h"

REST_PICTURE rest_picture;

HRESULT InitRestPicture(void)
{
	rest_picture.pos = D3DXVECTOR2(50.0f, 100.0f);
	rest_picture.size = D3DXVECTOR2(500.0f, 750.0f);
	rest_picture.texture = LoadTexture("data/TEXTURE/test/yellow.png");

	return S_OK;
}

void UninitRestPicture(void)
{

}

void UpdateRestPicture(void)
{

}

void DrawRestPicture(void)
{
	DrawSpriteLeftTop(rest_picture.texture, rest_picture.pos.x, rest_picture.pos.y, rest_picture.size.x, rest_picture.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}