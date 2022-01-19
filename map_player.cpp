//マップマス/マッププレイヤー/マップライン処理 [map_point.cpp]
#include <stdlib.h>
#include <time.h>

#include "map_player.h"
#include "map_point.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "map_hack.h"

//-----マクロ定義

//-----プロトタイプ宣言
MAP_PLAYER map_player;

//-----グローバル変数

//-----初期化処理
HRESULT InitMapPlayer(void)
{
		MAP* map = GetMapPoint();
		MAP_SB* map_sb = GetMapSB();

		//プレイヤーの初期化
		if (map_player.UDcount == 0)
		{
			map_player.size = D3DXVECTOR2(100.0f, 100.0f);
			map_player.pos = D3DXVECTOR2(map_sb->startpos.x, map_sb->startpos.y - map_player.size.y * 0.5f);
			map_player.texture = LoadTexture("data/TEXTURE/map_player.png");
			map_player.UDcount = 0;
			map_player.LRcount = 0;
			map_player.nowpos = 0;

			//選択の枠の初期化
			map_player.circlepos = D3DXVECTOR2(map[0].pos.x, map[0].pos.y);
			map_player.circlesize = D3DXVECTOR2(80.0f, 80.0f);
			map_player.circletexture = LoadTexture("data/TEXTURE/map/circle.png");

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
	MAP* map = GetMapPoint();
	MAP_SB* map_sb = GetMapSB();

	//-----マップスクロール
	if (map_hack->isUse == false)
	{
		if (PADUSE == 1)
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

			//-----シート1の場合
			//-----5段目
			//11→13、11→14
			if (map_player.nowpos == 11)
			{
				if (GetKeyboardTrigger(DIK_A) && map_player.UDcount == 4 && map_player.LRcount > 0)
				{
					map_player.LRcount = map_player.LRcount - 1;
					map_player.circlepos.x = map[map_player.LRcount + 13].pos.x;
				}
				if (GetKeyboardTrigger(DIK_D) && map_player.UDcount == 4 && map_player.LRcount < 1)
				{
					map_player.LRcount = map_player.LRcount + 1;
					map_player.circlepos.x = map[map_player.LRcount + 13].pos.x;
				}

				if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount == 4)
				{
					map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 13].pos.x, map[map_player.LRcount + 13].pos.y);
					if (map_player.LRcount == 0)
					{
						map_player.circlepos = D3DXVECTOR2(map[16].pos.x, map[16].pos.y);
						map_player.nowpos = 13;
					}
					if (map_player.LRcount == 1)
					{
						map_player.circlepos = D3DXVECTOR2(map[17].pos.x, map[17].pos.y);
						map_player.nowpos = 14;
					}
					map_player.LRcount = 0;
					map_player.UDcount = map_player.UDcount + 1;
				}
			}

			//-----4段目
			//7→10
			if (map_player.nowpos == 7)
			{
				if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount == 3)
				{
					map_player.pos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
					map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
					map_player.nowpos = 10;
					map_player.LRcount = 0;
					map_player.UDcount = map_player.UDcount + 1;
				}
			}
			//8→10、8→11
			if (map_player.nowpos == 8)
			{
				if (GetKeyboardTrigger(DIK_A) && map_player.UDcount == 3 && map_player.LRcount > 0)
				{
					map_player.LRcount = map_player.LRcount - 1;
					map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
				}
				if (GetKeyboardTrigger(DIK_D) && map_player.UDcount == 3 && map_player.LRcount < 1)
				{
					map_player.LRcount = map_player.LRcount + 1;
					map_player.circlepos.x = map[map_player.LRcount + 10].pos.x;
				}

				if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount == 3)
				{
					map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 10].pos.x, map[map_player.LRcount + 10].pos.y);
					if (map_player.LRcount == 0)
					{
						map_player.circlepos = D3DXVECTOR2(map[15].pos.x, map[15].pos.y);
						map_player.nowpos = 10;
					}
					if (map_player.LRcount == 1)
					{
						map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
						map_player.nowpos = 11;
					}
					map_player.LRcount = 0;
					map_player.UDcount = map_player.UDcount + 1;
				}
			}
			//9→11、9→12
			if (map_player.nowpos == 9)
			{
				if (GetKeyboardTrigger(DIK_A) && map_player.UDcount == 3 && map_player.LRcount > 0)
				{
					map_player.LRcount = map_player.LRcount - 1;
					map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
				}
				if (GetKeyboardTrigger(DIK_D) && map_player.UDcount == 3 && map_player.LRcount < 1)
				{
					map_player.LRcount = map_player.LRcount + 1;
					map_player.circlepos.x = map[map_player.LRcount + 11].pos.x;
				}

				if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount == 3)
				{
					map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 11].pos.x, map[map_player.LRcount + 11].pos.y);
					if (map_player.LRcount == 0)
					{
						map_player.circlepos = D3DXVECTOR2(map[13].pos.x, map[13].pos.y);
						map_player.nowpos = 11;
					}
					if (map_player.LRcount == 1)
					{
						map_player.circlepos = D3DXVECTOR2(map[14].pos.x, map[14].pos.y);
						map_player.nowpos = 12;
					}
					map_player.LRcount = 0;
					map_player.UDcount = map_player.UDcount + 1;
				}
			}

			//-----3段目
			//4→7
			if (map_player.nowpos == 4)
			{
				if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount == 2)
				{
					map_player.pos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
					map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
					map_player.nowpos = 7;
					map_player.LRcount = 0;
					map_player.UDcount = map_player.UDcount + 1;
				}
			}
			//5→8
			if (map_player.nowpos == 5)
			{
				if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount == 2)
				{
					map_player.pos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
					map_player.circlepos = D3DXVECTOR2(map[10].pos.x, map[10].pos.y);
					map_player.nowpos = 8;
					map_player.LRcount = 0;
					map_player.UDcount = map_player.UDcount + 1;
				}
			}
			//6→9
			if (map_player.nowpos == 6)
			{
				if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount == 2)
				{
					map_player.pos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
					map_player.circlepos = D3DXVECTOR2(map[11].pos.x, map[11].pos.y);
					map_player.nowpos = 9;
					map_player.LRcount = 0;
					map_player.UDcount = map_player.UDcount + 1;
				}
			}

			//-----2段目
			//0→4、1→4
			if (map_player.nowpos == 0 || map_player.nowpos == 1)
			{
				if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount == 1)
				{
					map_player.pos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
					map_player.circlepos = D3DXVECTOR2(map[7].pos.x, map[7].pos.y);
					map_player.nowpos = 4;
					map_player.LRcount = 0;
					map_player.UDcount = map_player.UDcount + 1;
				}
			}
			if (map_player.nowpos == 2)
			{
				if (GetKeyboardTrigger(DIK_A) && map_player.UDcount == 1 && map_player.LRcount > 0)
				{
					map_player.LRcount = map_player.LRcount - 1;
					map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
				}
				if (GetKeyboardTrigger(DIK_D) && map_player.UDcount == 1 && map_player.LRcount < 1)
				{
					map_player.LRcount = map_player.LRcount + 1;
					map_player.circlepos.x = map[map_player.LRcount + 5].pos.x;
				}
				if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount == 1)
				{
					map_player.pos = D3DXVECTOR2(map[map_player.LRcount + 5].pos.x, map[map_player.LRcount + 5].pos.y);
					if (map_player.LRcount == 0)
					{
						map_player.circlepos = D3DXVECTOR2(map[8].pos.x, map[8].pos.y);
						map_player.nowpos = 5;
					}
					if (map_player.LRcount == 1)
					{
						map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
						map_player.nowpos = 6;
					}
					map_player.LRcount = 0;
					map_player.UDcount = map_player.UDcount + 1;
				}

			}
			//3→6
			if (map_player.nowpos == 3)
			{
				if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount == 1)
				{
					map_player.pos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
					map_player.circlepos = D3DXVECTOR2(map[9].pos.x, map[9].pos.y);
					map_player.nowpos = 6;
					map_player.LRcount = 0;
					map_player.UDcount = map_player.UDcount + 1;
				}
			}

			//-----1段目
			if (GetKeyboardTrigger(DIK_A) && map_player.UDcount == 0 && map_player.LRcount > 0)	//左
			{
				map_player.LRcount = map_player.LRcount - 1;
				map_player.circlepos.x = map[map_player.LRcount].pos.x;
			}
			if (GetKeyboardTrigger(DIK_D) && map_player.UDcount == 0 && map_player.LRcount < 3)	//右
			{
				map_player.LRcount = map_player.LRcount + 1;
				map_player.circlepos.x = map[map_player.LRcount].pos.x;
			}
			if (GetKeyboardTrigger(DIK_RETURN) && map_player.UDcount == 0)
			{
				map_player.pos = D3DXVECTOR2(map[map_player.LRcount].pos.x, map[map_player.LRcount].pos.y);
				map_player.nowpos = map_player.LRcount;
				if(map_player.nowpos == 0 || map_player.nowpos == 1)
					map_player.circlepos = D3DXVECTOR2(map[4].pos.x, map[4].pos.y);
				if (map_player.nowpos == 2)
					map_player.circlepos = D3DXVECTOR2(map[5].pos.x, map[5].pos.y);
				if (map_player.nowpos == 3)
					map_player.circlepos = D3DXVECTOR2(map[6].pos.x, map[6].pos.y);
				map_player.LRcount = 0;
				map_player.UDcount = map_player.UDcount + 1;
			}
		}
	}

	//選択したマスに対応したシーンに飛ぶ
	if (GetKeyboardTrigger(DIK_RETURN))
	{
		if (map[map_player.nowpos].randomcode == 1)	//通常敵マス
		{
			map_player.gamecount = map_player.gamecount + 1;	//ゲームシーンに入った回数を記録する
			map_player.encount = (rand() % 2) + 1;	//ここで出現する敵をランダムに決める
			map_player.encount = 2;
			SceneTransition(SCENE_GAME);
		}
		if (map[map_player.nowpos].randomcode == 2)	//強敵マス
		{
			SceneTransition(SCENE_GAME);
		}
		if (map[map_player.nowpos].randomcode == 3)	//休憩マス
		{
			SceneTransition(SCENE_REST);
		}
		if (map[map_player.nowpos].randomcode == 4)	//イベントマス
		{
			SceneTransition(SCENE_EVENT);
		}
		if (map[map_player.nowpos].randomcode == 5)	//商人マス
		{
			SceneTransition(SCENE_SHOP);
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

MAP_PLAYER* GetMapPlayer()
{
	return &map_player;
}