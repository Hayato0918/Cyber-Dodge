//マップフロア処理 [map_floor.cpp]
#include "map_floor.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "map_player.h"

//-----マクロ定義

//-----プロトタイプ宣言
MAP_FLOOR map_floor[2];
MAP_FLOORBG map_floorbg;

//-----グローバル変数

//-----初期化処理
HRESULT InitMapFloor(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();
	map_floorbg.floornum = map_player->floor;

	map_floorbg.pos = D3DXVECTOR2(1370.0f, 100.0f);
	map_floorbg.size = D3DXVECTOR2(160.f, 80.f);
	map_floorbg.u = 0.f;
	map_floorbg.v = 0.f;

	for (int i = 0; i < 2; i++)
	{
		map_floor[i].pos = D3DXVECTOR2(1375.f + i * 50.f, 107.f);
		map_floor[i].size = D3DXVECTOR2(65.f, 65.f);
		map_floor[i].u = 0.f;
		map_floor[i].v = 0.f;
		map_floor[i].drawflag = false;
	}

	return S_OK;
}

//-----終了処理
void UninitMapFloor(void)
{

}

//-----更新処理
void UpdateMapFloor(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();
	map_floorbg.floornum = map_player->floor;

	if (map_floorbg.floornum < 10)
	{
		map_floor[0].drawflag = false;
		map_floor[1].drawflag = true;
	}
	if (map_floorbg.floornum >= 10)
	{
		map_floor[0].drawflag = true;
		map_floor[1].drawflag = true;
	}

	for (int i = 1; i < 5; i++)
	{
		if (map_floorbg.floornum == i)
		{
			map_floor[1].u = 0.2f * i;
			map_floor[1].v = 0.f;
		}
	}
	for (int i = 5; i < 10; i++)
	{
		if (map_floorbg.floornum == i)
		{
			map_floor[1].u = 0.2f * i;
			map_floor[1].v = 0.5f;
		}
	}
	for (int i = 10; i < 20; i++)
	{
		if (map_floorbg.floornum == i)
		{
			map_floor[0].u = 0.2f;
			map_floor[0].v = 0.f;
		}
	}
	for (int i = 10; i < 15; i++)
	{
		if (map_floorbg.floornum == i)
		{
			map_floor[1].u = 0.2f * i;
			map_floor[1].v = 0.f;
		}
	}
	for (int i = 15; i < 20; i++)
	{
		if (map_floorbg.floornum == i)
		{
			map_floor[1].u = 0.2f * i;
			map_floor[1].v = 0.5f;
		}
	}
	for (int i = 20; i < 30; i++)
	{
		if (map_floorbg.floornum == i)
		{
			map_floor[0].u = 0.4f;
			map_floor[0].v = 0.f;
		}
	}
	for (int i = 20; i < 25; i++)
	{
		if (map_floorbg.floornum == i)
		{
			map_floor[1].u = 0.2f * i;
			map_floor[1].v = 0.f;
		}
	}
	for (int i = 25; i < 30; i++)
	{
		if (map_floorbg.floornum == i)
		{
			map_floor[1].u = 0.2f * i;
			map_floor[1].v = 0.5f;
		}
	}

}

//-----描画処理
void DrawMapFloor(void)
{
	DrawSpriteLeftTop(map_floorbg.texture, map_floorbg.pos.x, map_floorbg.pos.y, map_floorbg.size.x, map_floorbg.size.y,0.0f, 0.0f, 1.0f, 1.0f);

	for (int i = 0; i < 2; i++)
	{
		if(map_floor[i].drawflag == true)
		DrawSpriteLeftTop(map_floorbg.numtexture, map_floor[i].pos.x, map_floor[i].pos.y, map_floor[i].size.x, map_floor[i].size.y,
			map_floor[i].u, map_floor[i].v, 0.2f, 0.5f);
	}
}

MAP_FLOORBG* GetMapFloorNum()
{
	return &map_floorbg;
}