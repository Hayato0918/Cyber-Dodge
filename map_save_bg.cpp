//セーブ背景処理 [map_save_bg.cpp]
#include "Map_save_bg.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"

MAPSAVE_BG map_save_bg;

HRESULT InitMapSaveBG(void)
{
	map_save_bg.pos = D3DXVECTOR2(450.0f, 200.0f);
	map_save_bg.size = D3DXVECTOR2(700.f, 500);
	map_save_bg.texture = LoadTexture("data/TEXTURE/map/save.png");
	map_save_bg.drawflag = false;

	return S_OK;
}

void UninitMapSaveBG(void)
{

}

void UpdateMapSaveBG(void)
{
	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_1))
			map_save_bg.drawflag = true;
	}
}

void DrawMapSaveBG(void)
{
	if(map_save_bg.drawflag == true)
	DrawSpriteLeftTop(map_save_bg.texture, map_save_bg.pos.x, map_save_bg.pos.y, map_save_bg.size.x, map_save_bg.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

MAPSAVE_BG* GetMapSaveBG()
{
	return &map_save_bg;
}