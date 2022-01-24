//マップBG処理 [map_BG.cpp]
#include "map_bg.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include "sound.h"

#include "map_hack.h"
#include "map_save_bg.h"
#include "soundvolume_select.h"

//-----マクロ定義

//-----プロトタイプ宣言
MAP_BG map_bg;

//-----グローバル変数

//-----初期化処理
HRESULT InitMapBG(void)
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	map_bg.pos = D3DXVECTOR2(0.0f, 0.0f);
	map_bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT * 2.f);
	map_bg.texture = LoadTexture("data/TEXTURE/map/bg.jpg");
	map_bg.sound = LoadSound("data/BGM/mapBGM.wav");

	SetVolume(map_bg.sound, soundvolume_select[0].count * 0.1f + 0.5f);
	PlaySound(map_bg.sound, -1);

	return S_OK;
}

//-----終了処理
void UninitMapBG(void)
{
	StopSoundAll();
}

//-----更新処理
void UpdateMapBG(void)
{
	MAP_HACK* map_hack = GetMapHack();
	MAPSAVE_BG* map_save = GetMapSaveBG();

	if (map_hack->isUse == false && map_save->drawflag == false)
	{
		if (PADUSE == 0)
		{
			if (IsButtonPressed(0, BUTTON_UP))
				map_bg.pos.y += 3;
			if (IsButtonPressed(0, BUTTON_DOWN))
				map_bg.pos.y -= 3;
		}
		if (PADUSE == 1)
		{
			if (GetKeyboardPress(DIK_W))
				map_bg.pos.y += 3;
			if (GetKeyboardPress(DIK_S))
				map_bg.pos.y -= 3;
		}
	}
}

//-----描画処理
void DrawMapBG(void)
{
	DrawSpriteLeftTop(map_bg.texture, map_bg.pos.x, map_bg.pos.y, map_bg.size.x, map_bg.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
}