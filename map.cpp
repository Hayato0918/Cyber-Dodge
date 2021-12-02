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
#define map_xnum 4
#define map_ynum 7

//-----プロトタイプ宣言
MAP map[map_xnum][map_ynum];
MAP_PLAYER map_player;

//-----グローバル変数
int map_texture;

float map_x;
float map_y;
int mapcount;

//-----初期化処理
HRESULT InitMap(void)
{
	map_y = 300;
	map_x = ((rand() % 2) + 2) * 0.1f;
	mapcount = 0;

	map_texture = LoadTexture("data/TEXTURE/map_point.png");

	for (int y = 0; y < map_ynum; y++)
	{
		for (int x = 0; x < map_xnum; x++)
		{
			map[x][y].size = D3DXVECTOR2(80.0f, 80.0f);
			map[x][y].uw = 0.166f;
			map[x][y].v = 0.0f;
			map[x][y].vh = 1.0f;

			//マスの色をランダムに
			map[x][y].randomcode = (rand() % 6) + 1;
			switch (map[x][y].randomcode)
			{
			case 1:
				map[x][y].u = 0.0f;
				break;
			case 2:
				map[x][y].u = 0.166f;
				break;
			case 3:
				map[x][y].u = 0.332f;
				break;
			case 4:
				map[x][y].u = 0.498f;
				break;
			case 5:
				map[x][y].u = 0.664f;
				break;
			case 6:
				map[x][y].u = 0.83f;
				break;
			}
		}
	}

	for (int y = 0; y < map_ynum; y++)
	{
		for (int x = 0; x < map_xnum; x++)
		{
			map[x][y].pos = D3DXVECTOR2(SCREEN_WIDTH * map_x - map[x][y].size.x, map_y);
			map_x = map_x + ((rand() % 2) + 1) * 0.1f;
			mapcount = mapcount + 1;
			//「aの値が◯だったら、▽のイベントを多く出す」とかもできる
			if (mapcount > 2 && mapcount < 4)
			{
				map[x][y].randomcode = (rand() % 2);
				if (map[x][y].randomcode == 1)
				{
					x = x + 1;
					map_y = map_y + 200;
					map_x = ((rand() % 2) + 2) * 0.1f;
					mapcount = 0;
				}

			}
			if (mapcount >= 4)
			{
				x = x + 1;
				map_y = map_y + 200;
				map_x = ((rand() % 2) + 2) * 0.1f;
				mapcount = 0;
			}

			if (map_y >= 1700)	//ボスマスのy座標までたどり着いたら、それ以降のマスを消す
			{
				map_y = 20000;
			}
		}
	}

	////スタートマス
	//map[0].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f - map[0].size.x, 100);
	////ボスマス
	//map[map_num - 1].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f - map[23].size.x, 1700);

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


	//MAP_PLAYER* map_player = GetMapPlayer();

	//マップスクロール
	//if (GetKeyboardPress(DIK_W))
	//{
	//	for (int y = 0; y < map_y; y++)
	//	{
	//		for(int x = 0; x < map_xnum; x++)
	//		map[x][y].pos.y += 3;
	//	}
	//}
	if (GetKeyboardPress(DIK_S))
	{
		for (int y = 0; y < map_ynum; y++)
		{
			for (int x = 0; x < map_xnum; x++)
				map[x][y].pos.y -= 3;
		}
	}
}

//-----描画処理
void DrawMap(void)
{
	for (int y = 0; y < map_ynum; y++)
	{
		for (int x = 0; x < map_xnum; x++)
		{
			DrawSpriteLeftTop(map_texture, map[x][y].pos.x, map[x][y].pos.y, map[x][y].size.x, map[x][y].size.y,
				map[x][y].u, map[x][y].v, map[x][y].uw, map[x][y].vh);
		}
	}
}










//-----初期化処理
HRESULT InitMapPlayer(void)
{
	map_player.size = D3DXVECTOR2(80.0f, 80.0f);
	map_player.pos = D3DXVECTOR2(map[0][0].pos.x, map[0][0].pos.y - map_player.size.y * 0.5f);
	map_player.texture = LoadTexture("data/TEXTURE/map_player.png");

	if (map_player.UDcount == 0)
	{
		map_player.LRcount = 0;
		map_player.UDcount = 0;
		map_player.move = false;
		map_player.moveflag = false;
		map_player.movespeedflag = false;
	}

	map_player.circlepos = D3DXVECTOR2(map[0][1].pos.x, map[0][1].pos.y);
	map_player.circlesize = D3DXVECTOR2(80.0f, 80.0f);
	map_player.circletexture = LoadTexture("data/TEXTURE/circle.png");

	map_player.x = 0.0f;
	map_player.y = 0.0f;

	map_player.movespeedflag = false;

	return S_OK;
}

//-----更新処理
void UpdateMapPlayer(void)
{
	//マップスクロール
	if (GetKeyboardPress(DIK_W))
	{
		map_player.pos.y += 3;
		map_player.circlepos.y += 3;
	}
	if (GetKeyboardPress(DIK_S))
	{
		map_player.pos.y -= 3;
		map_player.circlepos.y -= 3;
	}

	//1つ左のマスにカーソルを合わせる
	if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0)
	{
		map_player.LRcount = map_player.LRcount - 1;
		map_player.circlepos.x = map[map_player.LRcount][map_player.UDcount + 1].pos.x;
	}
	//1つ右のマスにカーソルを合わせる
	if (GetKeyboardTrigger(DIK_D) && map_player.circlepos.x < map[map_player.LRcount + 1][map_player.UDcount + 1].pos.x)
	{
		map_player.LRcount = map_player.LRcount + 1;
		map_player.circlepos.x = map[map_player.LRcount][map_player.UDcount + 1].pos.x;
	}
	//カーソルを合わせたマスにプレイヤーを動かす
	if (GetKeyboardTrigger(DIK_RETURN))
	{
		map_player.UDcount = map_player.UDcount + 1;
		if (map[map_player.LRcount][map_player.UDcount].randomcode == 1)
			SceneTransition(SCENE_GAME);

		map_player.pos.x = map[map_player.LRcount][map_player.UDcount].pos.x;
		map_player.pos.y = map_player.pos.y + 200;
		map_player.LRcount = 0;

		map_player.circlepos.x = map[map_player.LRcount][map_player.UDcount + 1].pos.x;
		map_player.circlepos.y = map[map_player.LRcount][map_player.UDcount + 1].pos.y;
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