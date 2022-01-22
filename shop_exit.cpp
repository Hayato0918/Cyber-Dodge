//商人マス退出処理[shop_exit.cpp]
#include "shop_exit.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "scene.h"
#include "fade.h"
//
#include "shop_select.h"
#include "map_player.h"

SHOP_EXIT shop_exit;

HRESULT InitShopExit()
{
	shop_exit.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.6875f, SCREEN_HEIGHT * 0.77777f);
	shop_exit.size = D3DXVECTOR2(SCREEN_WIDTH * 0.25f, SCREEN_HEIGHT * 0.138888f);
	shop_exit.texture = LoadTexture("data/TEXTURE/test/red.png");

	return S_OK;
}

void UninitShopExit()
{

}

void UpdateShopExit()
{
	SHOP_SELECT* shop_select = GetShopSelect();
	MAP_PLAYER* map_player = GetMapPlayer();

	if (GetKeyboardTrigger(DIK_RETURN) && shop_select->ycount == 2)
	{
		map_player->nextflag = true;
		SceneTransition(SCENE_MAP);
	}
}

void DrawShopExit()
{
	DrawSpriteLeftTop(shop_exit.texture, shop_exit.pos.x, shop_exit.pos.y, shop_exit.size.x, shop_exit.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

SHOP_EXIT* GetShopExit()
{
	return &shop_exit;
}