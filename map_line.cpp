//マップライン処理 [map_line.cpp]
#include "map_line.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include <stdlib.h>
#include <time.h>

#include "map_player.h"
#include "map_hack.h"
#include "map_save_bg.h"
#include "map_bg.h"
#include "deckmenu.h"

//-----マクロ定義

//-----プロトタイプ宣言
MAP_LINE map_line;

//-----グローバル変数

//-----初期化処理
HRESULT InitMapLine(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();
	DECKMENU* deckmenu = GetDeckmenu();

	if (map_player->UDcount == 0 && deckmenu->openflag == false)
	{
		map_line.pos = D3DXVECTOR2(0.0f, SCREEN_HEIGHT * 0.055555f);
		map_line.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT * 2.f);

		//-----ランダムコードの設定
		srand((unsigned int)time(NULL));
		map_line.randomcode = (rand() % 4) + 1;

		if(map_player->floor == 0)
			map_line.randomcode = 1;

		if(map_line.randomcode == 1)
			map_line.texture = LoadTexture("data/TEXTURE/map/mapline_1.png");
		if (map_line.randomcode == 2)
			map_line.texture = LoadTexture("data/TEXTURE/map/mapline_2.png");
		if (map_line.randomcode == 3)
			map_line.texture = LoadTexture("data/TEXTURE/map/mapline_3.png");
		if (map_line.randomcode == 4)
			map_line.texture = LoadTexture("data/TEXTURE/map/mapline_4.png");
	}

	return S_OK;
}

//-----終了処理
void UninitMapLine(void)
{

}

//-----更新処理
void UpdateMapLine(void)
{
	MAP_HACK* map_hack = GetMapHack();
	MAPSAVE_BG* map_save = GetMapSaveBG();
	MAP_BG* map_bg = GetMapBG();

	if (map_hack->isUse == false && map_save->drawflag == false)
	{
		if (PADUSE == 0)
		{
			if (IsButtonPressed(0, BUTTON_UP) && map_bg->pos.y < 60)
				map_line.pos.y += 5;
			if (IsButtonPressed(0, BUTTON_DOWN) && map_bg->pos.y > -580)
				map_line.pos.y -= 5;
		}

		if (PADUSE == 1)
		{
			if (GetKeyboardPress(DIK_W) && map_bg->pos.y < 60)
				map_line.pos.y += 5;
			if (GetKeyboardPress(DIK_S) && map_bg->pos.y > -580)
				map_line.pos.y -= 5;
		}
	}
}

//-----描画処理
void DrawMapLine(void)
{
	DrawSpriteLeftTop(map_line.texture, map_line.pos.x, map_line.pos.y, map_line.size.x, map_line.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
}

MAP_LINE* GetMapLine()
{
	return &map_line;
}