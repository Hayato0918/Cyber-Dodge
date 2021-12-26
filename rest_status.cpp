//休憩マスステータス表示処理 [rest_status.cpp]
#include "rest_status.h"
//システム.h
#include "texture.h"
#include "sprite.h"

REST_STATUS rest_status;

HRESULT InitRestStatus(void)
{
	rest_status.pos = D3DXVECTOR2(600.0f, 500.0f);
	rest_status.size = D3DXVECTOR2(400.f, 350.f);
	rest_status.texture = LoadTexture("data/TEXTURE/test/yellow.png");

	return S_OK;
}

void UninitRestStatus(void)
{

}

void UpdateRestStatus(void)
{

}

void DrawRestStatus(void)
{
	DrawSpriteLeftTop(rest_status.texture, rest_status.pos.x, rest_status.pos.y, rest_status.size.x, rest_status.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}