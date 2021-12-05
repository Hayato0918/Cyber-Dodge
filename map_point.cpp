//マップ処理 [map.cpp]
#include <stdlib.h>
#include <time.h>

#include "map_point.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "map_hack.h"

//-----マクロ定義
#define map_xnum 4
#define map_ynum 7

//-----プロトタイプ宣言
MAP map[map_xnum][map_ynum];
MAP_PLAYER map_player;
MAP_SB map_sb;

//-----グローバル変数
int map_texture;	//マスのテクスチャを設定する変数

float map_x;	//マスのx座標をランダムにするための変数
float map_y;	//マスのy座標をランダムにするための変数
int mapcount;	

//-----初期化処理
HRESULT InitMapPoint(void)
{
	if (map_player.UDcount == 0)	//一回だけ呼ぶ
	{
		map_y = 300;
		//マスのx座標をランダムにする
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

				//マスの色をランダムにする
				map[x][y].randomcode = (rand() % 5) + 1;
				switch (map[x][y].randomcode)
				{
				case 1:		//オレンジ(通常敵マス)
					map[x][y].u = 0.0f;
					break;
				case 2:		//赤(強敵ます)
					map[x][y].u = 0.166f;
					break;
				case 3:		//緑(休憩マス)
					map[x][y].u = 0.498f;
					break;
				case 4:		//青(イベントマス)
					map[x][y].u = 0.664f;
					break;
				case 5:		//黄色(商人マス)
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
					map_y = 0;
				}
			}
		}

		//スタートマス
		map_sb.startsize = D3DXVECTOR2(80, 80);
		map_sb.startpos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f - map_sb.startsize.x, 100);
		//ボスマス
		map_sb.bosssize = D3DXVECTOR2(120, 120);
		map_sb.bosspos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f - map_sb.bosssize.x, 1700);
	}

	return S_OK;
}

//-----終了処理
void UninitMapPoint(void)
{

}

//-----更新処理
void UpdateMapPoint(void)
{
	srand((unsigned int)time(NULL));

	MAP_HACK* map_hack = GetMapHack();

	//マスをハッキングして、任意のマスに変える
	if (map_hack->isUse == true)
	{
		if (GetKeyboardTrigger(DIK_RETURN))
		{
			if (map_hack->UDcount == 0)		//通常敵マス
			{
				map[map_player.LRcount][map_player.UDcount].randomcode = 1;
				map[map_player.LRcount][map_player.UDcount].u = 0.0f;
			}
			if (map_hack->UDcount == 1)		//強敵マス
			{
				map[map_player.LRcount][map_player.UDcount].randomcode = 2;
				map[map_player.LRcount][map_player.UDcount].u = 0.166f;
			}
			if (map_hack->UDcount == 2)		//休憩マス
			{
				map[map_player.LRcount][map_player.UDcount].randomcode = 3;
				map[map_player.LRcount][map_player.UDcount].u = 0.498f;
			}
			if (map_hack->UDcount == 3)		//イベントマス
			{
				map[map_player.LRcount][map_player.UDcount].randomcode = 4;
				map[map_player.LRcount][map_player.UDcount].u = 0.664f;
			}
			if (map_hack->UDcount == 4)		//商人マス
			{
				map[map_player.LRcount][map_player.UDcount].randomcode = 5;
				map[map_player.LRcount][map_player.UDcount].u = 0.83f;
			}
		}
	}

	//マップスクロール
	if (map_hack->isUse == false)
	{
		if (GetKeyboardPress(DIK_W))
		{
			map_sb.startpos.y += 3;
			map_sb.bosspos.y += 3;

			for (int y = 0; y < map_ynum; y++)
			{
				for (int x = 0; x < map_xnum; x++)
					map[x][y].pos.y += 3;
			}
		}
		if (GetKeyboardPress(DIK_S))
		{
			map_sb.startpos.y -= 3;
			map_sb.bosspos.y -= 3;

			for (int y = 0; y < map_ynum; y++)
			{
				for (int x = 0; x < map_xnum; x++)
					map[x][y].pos.y -= 3;
			}
		}
	}
}

//-----描画処理
void DrawMapPoint(void)
{
	//スタートマスの描画
	DrawSpriteLeftTop(map_texture, map_sb.startpos.x, map_sb.startpos.y, map_sb.startsize.x, map_sb.startsize.y, 0.664f, 0.0f, 0.166f, 1.0f);
	//ボスマスの描画
	DrawSpriteLeftTop(map_texture, map_sb.bosspos.x, map_sb.bosspos.y, map_sb.bosssize.x, map_sb.bosssize.y, 0.332f, 0.0f, 0.166f, 1.0f);

	for (int y = 0; y < map_ynum; y++)
	{
		for (int x = 0; x < map_xnum; x++)
		{
			if(map[x][y].pos.x > 0)
			DrawSpriteLeftTop(map_texture, map[x][y].pos.x, map[x][y].pos.y, map[x][y].size.x, map[x][y].size.y,
				map[x][y].u, map[x][y].v, map[x][y].uw, map[x][y].vh);
		}
	}
}

//-----------------------------------------------//
//--------------|プレイヤーの設定|--------------//
//---------------------------------------------//

//-----初期化処理
HRESULT InitMapPlayer(void)
{
	if (map_player.UDcount == 0)
	{
		//プレイヤーの初期化
		map_player.size = D3DXVECTOR2(80.0f, 80.0f);
		map_player.pos = D3DXVECTOR2(map_sb.startpos.x, map_sb.startpos.y - map_player.size.y * 0.5f);
		map_player.texture = LoadTexture("data/TEXTURE/map_player.png");
		map_player.LRcount = 0;
		map_player.UDcount = 0;

		//選択の枠の初期化
		map_player.circlepos = D3DXVECTOR2(map[0][0].pos.x, map[0][0].pos.y);
		map_player.circlesize = D3DXVECTOR2(80.0f, 80.0f);
		map_player.circletexture = LoadTexture("data/TEXTURE/circle.png");

		map_player.gamecount = 0;
	}
	return S_OK;
}

//終了処理
void UninitMapPlayer(void)
{

}

//-----更新処理
void UpdateMapPlayer(void)
{
	MAP_HACK* map_hack = GetMapHack();

	//マップスクロール
	if (map_hack->isUse == false)
	{
		if (GetKeyboardPress(DIK_W))	//上
		{
			map_player.pos.y += 3;
			map_player.circlepos.y += 3;
		}
		if (GetKeyboardPress(DIK_S))	//下
		{
			map_player.pos.y -= 3;
			map_player.circlepos.y -= 3;
		}

		//1つ左のマスにカーソルを合わせる
		if (GetKeyboardTrigger(DIK_A) && map_player.LRcount > 0 && map_player.UDcount < 7)
		{
			map_player.LRcount = map_player.LRcount - 1;
			map_player.circlepos.x = map[map_player.LRcount][map_player.UDcount].pos.x;
		}
		//1つ右のマスにカーソルを合わせる
		if (GetKeyboardTrigger(DIK_D) && map_player.circlepos.x < map[map_player.LRcount + 1][map_player.UDcount].pos.x && map_player.UDcount < 7)
		{
			map_player.LRcount = map_player.LRcount + 1;
			map_player.circlepos.x = map[map_player.LRcount][map_player.UDcount].pos.x;
		}
		//カーソルを合わせたマスにプレイヤーを動かす
		if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount < 8)
		{
			//選択したマスまでプレイヤーを移動させる
			if (map_player.UDcount < 7)		//ボス前まで
			{
				map_player.pos.x = map[map_player.LRcount][map_player.UDcount].pos.x;
				map_player.pos.y = map_player.pos.y + 200;
			}
			if (map_player.UDcount == 7)	//ボスマス
				map_player.pos = D3DXVECTOR2(map_sb.bosspos.x + map_player.size.x * 0.25f, map_sb.bosspos.y);

			//選択したマスに対応したシーンに飛ぶ
			if (map[map_player.LRcount][map_player.UDcount].randomcode == 1)	//通常敵マス
			{
				map_player.gamecount = map_player.gamecount + 1;
				SceneTransition(SCENE_GAME);
			}
			if (map[map_player.LRcount][map_player.UDcount].randomcode == 2)	//強敵マス
				SceneTransition(SCENE_GAME);
			if (map[map_player.LRcount][map_player.UDcount].randomcode == 3)	//休憩マス
				SceneTransition(SCENE_REST);
			if (map[map_player.LRcount][map_player.UDcount].randomcode == 4)	//イベントマス
				SceneTransition(SCENE_EVENT);
			if (map[map_player.LRcount][map_player.UDcount].randomcode == 5)	//商人マス
				SceneTransition(SCENE_SHOP);

			map_player.LRcount = 0;
			map_player.UDcount = map_player.UDcount + 1;

			//次の選択肢までカーソルを移動させる
			if (map_player.UDcount < 7)		//ボス前まで
			{
				map_player.circlepos.x = map[map_player.LRcount][map_player.UDcount].pos.x;
				map_player.circlepos.y = map[map_player.LRcount][map_player.UDcount].pos.y;
			}
			if (map_player.UDcount == 7)	//ボスマス
			{
				map_player.circlepos = D3DXVECTOR2(map_sb.bosspos.x, map_sb.bosspos.y);
				map_player.circlesize = D3DXVECTOR2(map_sb.bosssize.x, map_sb.bosssize.y);
			}
		}
	}
}

//-----描画処理
void DrawMapPlayer(void)
{
	//枠の描画
	DrawSpriteLeftTop(map_player.circletexture, map_player.circlepos.x, map_player.circlepos.y, map_player.circlesize.x, map_player.circlesize.y,
		0.0f, 0.0f, 1.0f, 1.0f);
	//プレイヤーの描画
	DrawSpriteLeftTop(map_player.texture, map_player.pos.x, map_player.pos.y, map_player.size.x, map_player.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
}

//-----構造体ポインタ取得
MAP_PLAYER* GetMapPlayer()
{
	return &map_player;
}