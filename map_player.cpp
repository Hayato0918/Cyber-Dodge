//マップ移動処理 [map_player.cpp]
#include "map_player.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "map.h"

//-----マクロ定義

//-----プロトタイプ宣言
MAP_PLAYER map_player;

//-----グローバル変数

//-----初期化処理
HRESULT InitMapPlayer(void)
{
	MAP* map = GetMap();

	map_player.size = D3DXVECTOR2(80.0f, 80.0f);
	map_player.pos = D3DXVECTOR2(map[0].pos.x - map[0].size.x * 0.5, map[0].pos.y - map_player.size.y + map[0].size.y * 0.5);
	map_player.texture = LoadTexture("data/TEXTURE/map_player.png");


	map_player.circlepos = D3DXVECTOR2(map[1].pos.x, map[1].pos.y);
	map_player.circlesize = D3DXVECTOR2(40.0f, 40.0f);
	map_player.circletexture = LoadTexture("data/TEXTURE/circle.png");

	return S_OK;
}

//-----終了処理
void UninitMapPlayer(void)
{

}

//-----更新処理
void UpdateMapPlayer(void)
{
	MAP* map = GetMap();

	//左右選択
	if (GetKeyboardTrigger(DIK_D) && map_player.LRcount < 3 && map_player.UDcount == 0)
	{
		map_player.LRcount = map_player.LRcount + 1;
		map_player.circlepos.x = map_player.circlepos.x + SCREEN_WIDTH * 0.2;
	}
	if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0 && map_player.UDcount == 0)
	{
		map_player.LRcount = map_player.LRcount - 1;
		map_player.circlepos.x = map_player.circlepos.x - SCREEN_WIDTH * 0.2;
	}
	if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount == 0)
	{
		if (map_player.LRcount == 0)
		{
			map_player.pos = D3DXVECTOR2(map[1].pos.x - map[1].size.x * 0.5, map[1].pos.y - map_player.size.y + map[1].size.y * 0.5);
		}
	}
}

//-----描画処理
void DrawMapPlayer(void)
{
	DrawSpriteLeftTop(map_player.circletexture, map_player.circlepos.x, map_player.circlepos.y, map_player.circlesize.x, map_player.circlesize.y,
		0.0f, 0.0f, 1.0f, 1.0f);

	DrawSpriteLeftTop(map_player.texture, map_player.pos.x, map_player.pos.y, map_player.size.x, map_player.size.y, 
		0.0f, 0.0f, 1.0f, 1.0f);
}

MAP_PLAYER* GetMapPlayer()
{
	return &map_player;
}

