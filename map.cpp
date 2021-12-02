//マップ処理 [map.cpp]
#include <stdlib.h>
#include <time.h>

#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"
#include "map.h"
#include "map_player.h"

//-----マクロ定義
#define map_num 28

//-----プロトタイプ宣言
MAP map[map_num];
MAPSEN mapsen;

//-----グローバル変数
int map_texture;
int mapsen_texture;

float map_y;
float map_x;
int mapcount;

//-----初期化処理
HRESULT InitMap(void)
{

	MAP_PLAYER* map_player = GetMapPlayer();

	mapsen.pos = D3DXVECTOR2(0.0f, 0.0f);
	mapsen.size = D3DXVECTOR2(SCREEN_WIDTH, 2000.0f);
	mapsen_texture = LoadTexture("data/TEXTURE/mapsen.png");
	map_y = 300;
	map_x = ((rand() % 2) + 2) * 0.1f;
	mapcount = 0;

	map_texture = LoadTexture("data/TEXTURE/map_point.png");

	for (int i = 0; i < map_num; i++)
	{
		map[i].size = D3DXVECTOR2(80.0f, 80.0f);
		map[i].uw = 0.25f;
		map[i].vh = 0.5f;

		//マスの色をランダムに
		map[i].randomcode = (rand() % 7) + 1;
		switch (map[i].randomcode)
		{
		case 1:
			map[i].u = 0.0f;
			map[i].v = 0.0f;
			break;
		case 2:
			map[i].u = 0.25f;
			map[i].v = 0.0f;
			break;
		case 3:
			map[i].u = 0.5f;
			map[i].v = 0.0f;
			break;
		case 4:
			map[i].u = 0.75f;
			map[i].v = 0.0f;
			break;
		case 5:
			map[i].u = 0.0f;
			map[i].v = 0.5f;
			break;
		case 6:
			map[i].u = 0.25f;
			map[i].v = 0.5f;
			break;
		case 7:
			map[i].u = 0.5f;
			map[i].v = 0.5f;
			break;
		}
	}


	for (int i = 1; i < map_num; i++)
	{
		map[i].pos = D3DXVECTOR2(SCREEN_WIDTH * map_x - map[i].size.x, map_y);
		map_x = map_x + ((rand() % 2) + 1) * 0.1f;
		mapcount = mapcount + 1;
															//「aの値が◯だったら、▽のイベントを多く出す」とかもできる
		if (mapcount > 2 && mapcount < 4)
		{
			map[i].randomcode = (rand() % 2);
			if (map[i].randomcode == 1)
			{
				map_y = map_y + 200;
				map_x = ((rand() % 2) + 2) * 0.1f;
				mapcount = 0;
			}
		}
		if (mapcount >= 4)
		{
			map_y = map_y + 200;
			map_x = ((rand() % 2) + 2) * 0.1f;
			mapcount = 0;
		}

		if (map_y >= 1700)	//ボスマスのy座標までたどり着いたら、それ以降のマスを消す
		{
			map_y = 20000;
		}
	}

	//スタートマス
	map[0].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f - map[0].size.x, 100);
	//ボスマス
	map[map_num - 1].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f - map[23].size.x, 1700);

	return S_OK;
}

//-----終了処理
void UninitMap(void)
{

}

//-----更新処理
void UpdateMap(void)
{
	srand((unsigned int)time(NULL));


	MAP_PLAYER* map_player = GetMapPlayer();

	//マップスクロール
	if (GetKeyboardPress(DIK_W))
	{
		for (int i = 0; i < map_num; i++)
		map[i].pos.y += 3;
		mapsen.pos.y += 3;
	}
	if (GetKeyboardPress(DIK_S))
	{
		for (int i = 0; i < map_num; i++)
		map[i].pos.y -= 3;
		mapsen.pos.y -= 3;
	}
}

//-----描画処理
void DrawMap(void)
{
	DrawSpriteLeftTop(mapsen_texture, mapsen.pos.x, mapsen.pos.y, mapsen.size.x, mapsen.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

	for (int i = 0; i < map_num; i++)
		DrawSpriteLeftTop(map_texture, map[i].pos.x, map[i].pos.y, map[i].size.x, map[i].size.y,
			map[i].u, map[i].v, map[i].uw, map[i].vh);
}

MAP* GetMap(void)
{
	return &map[0];
}