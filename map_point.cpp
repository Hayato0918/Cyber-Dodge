//マップマス/マッププレイヤー/マップライン処理 [map_point.cpp]
#include <stdlib.h>
#include <time.h>

#include "map_point.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "map_hack.h"

//-----マクロ定義
#define map_num 21

//-----プロトタイプ宣言
MAP map[map_num];
MAP_SB map_sb;

//-----グローバル変数
int map_texture;	//マスのテクスチャを設定する変数

//-----初期化処理
HRESULT InitMapPoint(void)
{
		//map_texture = LoadTexture("data/TEXTURE/map/map_point.png");

		//-----シート1の場合
		//-----1段目
		map[0].pos = D3DXVECTOR2(320.f, 250.f);
		map[1].pos = D3DXVECTOR2(620.f, 250.f);
		map[2].pos = D3DXVECTOR2(930.f, 250.f);
		map[3].pos = D3DXVECTOR2(1245.f, 250.f);
		//-----2段目
		map[4].pos = D3DXVECTOR2(400.f, 450.f);
		map[5].pos = D3DXVECTOR2(800.f, 450.f);
		map[6].pos = D3DXVECTOR2(1200.f, 450.f);
		//-----3段目
		map[7].pos = D3DXVECTOR2(190.f, 650.f);
		map[8].pos = D3DXVECTOR2(735.f, 650.f);
		map[9].pos = D3DXVECTOR2(1065.f, 650.f);
		//-----4段目
		map[10].pos = D3DXVECTOR2(410, 860.f);
		map[11].pos = D3DXVECTOR2(950.f, 860.f);
		map[12].pos = D3DXVECTOR2(1265.f, 860.f);
		//-----5段目
		map[13].pos = D3DXVECTOR2(710.f, 1050.f);
		map[14].pos = D3DXVECTOR2(1115.f, 1060.f);
		//-----6段目
		map[15].pos = D3DXVECTOR2(250, 1245.f);
		map[16].pos = D3DXVECTOR2(710.f, 1245.f);
		map[17].pos = D3DXVECTOR2(965.f, 1245.f);
		//-----7段目
		map[18].pos = D3DXVECTOR2(430, 1445.f);
		map[19].pos = D3DXVECTOR2(700.f, 1445.f);
		map[20].pos = D3DXVECTOR2(965.f, 1445.f);

		//-----ランダムコードの設定
		srand((unsigned int)time(NULL));
		for (int i = 0; i < map_num; i++)
			map[i].randomcode = (rand() % 5) + 1;

		//----1段目をチュートリアルマスにする
		for (int i = 0; i < 4; i++)
			map[i].randomcode = 1;
		//-----ボスマスの手前は戦闘マス以外にする
		for(int i = 18; i < 21; i++)
			map[i].randomcode = (rand() % 3) + 3;



		//-----ここからすべてのシートに適用
		for (int i = 0; i < map_num; i++)
		{
			map[i].size = D3DXVECTOR2(100.f, 100.f);

			//-----randomcodeの値に応じて色を決める
			switch (map[i].randomcode)
			{
			case 1:		//オレンジ(通常敵マス)
				map[i].u = 0.0f;
				break;
			case 2:		//赤(強敵マス)
				map[i].u = 0.166f;
				break;
			case 3:		//緑(休憩マス)
				map[i].u = 0.498f;
				break;
			case 4:		//青(イベントマス)
				map[i].u = 0.664f;
				break;
			case 5:		//黄色(商人マス)
				map[i].u = 0.83f;
				break;
			}
		}

		//スタートマス
		map_sb.startsize = D3DXVECTOR2(80, 80);
		map_sb.startpos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f - map_sb.startsize.x, 100);
		//ボスマス
		map_sb.bosssize = D3DXVECTOR2(120, 120);
		map_sb.bosspos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f - map_sb.bosssize.x, 1700);

	return S_OK;
}

//-----終了処理
void UninitMapPoint(void)
{

}

//-----更新処理
void UpdateMapPoint(void)
{
	MAP_HACK* map_hack = GetMapHack();

	//-----マップスクロール
	if (GetKeyboardPress(DIK_W))
	{
		for (int i = 0; i < map_num; i++)
			map[i].pos.y += 3.f;
		map_sb.startpos.y += 3.f;
		map_sb.bosspos.y += 3.f;
	}
	if (GetKeyboardPress(DIK_S))
	{
		for (int i = 0; i < map_num; i++)
			map[i].pos.y -= 3.f;
		map_sb.startpos.y -= 3.f;
		map_sb.bosspos.y -= 3.f;
	}

	//マスをハッキングして、任意のマスに変える
	if (map_hack->isUse == true)
	{
		//if (PADUSE == 0)
		//{
		//	if (IsButtonTriggered(0, BUTTON_X))
		//	{
		//		if (map_hack->UDcount == 0)		//通常敵マス
		//		{
		//			map[map_player.UDcount][map_player.LRcount].randomcode = 1;
		//			map[map_player.UDcount][map_player.LRcount].u = 0.0f;
		//		}
		//		if (map_hack->UDcount == 1)		//強敵マス
		//		{
		//			map[map_player.UDcount][map_player.LRcount].randomcode = 2;
		//			map[map_player.UDcount][map_player.LRcount].u = 0.166f;
		//		}
		//		if (map_hack->UDcount == 2)		//休憩マス
		//		{
		//			map[map_player.UDcount][map_player.LRcount].randomcode = 3;
		//			map[map_player.UDcount][map_player.LRcount].u = 0.498f;
		//		}
		//		if (map_hack->UDcount == 3)		//イベントマス
		//		{
		//			map[map_player.UDcount][map_player.LRcount].randomcode = 4;
		//			map[map_player.UDcount][map_player.LRcount].u = 0.664f;
		//		}
		//		if (map_hack->UDcount == 4)		//商人マス
		//		{
		//			map[map_player.UDcount][map_player.LRcount].randomcode = 5;
		//			map[map_player.UDcount][map_player.LRcount].u = 0.83f;
		//		}
		//	}
		//}
		//if (PADUSE == 1)
		//{
		//	if (GetKeyboardTrigger(DIK_RETURN))
		//	{
		//		if (map_hack->UDcount == 0)		//通常敵マス
		//		{
		//			map[map_player.UDcount][map_player.LRcount].randomcode = 1;
		//			map[map_player.UDcount][map_player.LRcount].u = 0.0f;
		//		}
		//		if (map_hack->UDcount == 1)		//強敵マス
		//		{
		//			map[map_player.UDcount][map_player.LRcount].randomcode = 2;
		//			map[map_player.UDcount][map_player.LRcount].u = 0.166f;
		//		}
		//		if (map_hack->UDcount == 2)		//休憩マス
		//		{
		//			map[map_player.UDcount][map_player.LRcount].randomcode = 3;
		//			map[map_player.UDcount][map_player.LRcount].u = 0.498f;
		//		}
		//		if (map_hack->UDcount == 3)		//イベントマス
		//		{
		//			map[map_player.UDcount][map_player.LRcount].randomcode = 4;
		//			map[map_player.UDcount][map_player.LRcount].u = 0.664f;
		//		}
		//		if (map_hack->UDcount == 4)		//商人マス
		//		{
		//			map[map_player.UDcount][map_player.LRcount].randomcode = 5;
		//			map[map_player.UDcount][map_player.LRcount].u = 0.83f;
		//		}
		//	}
		//}
	}
}

//-----描画処理
void DrawMapPoint(void)
{
	//スタートマスの描画
	DrawSpriteLeftTop(map_texture, map_sb.startpos.x, map_sb.startpos.y, map_sb.startsize.x, map_sb.startsize.y, 0.664f, 0.0f, 0.166f, 1.0f);
	//ボスマスの描画
	DrawSpriteLeftTop(map_texture, map_sb.bosspos.x, map_sb.bosspos.y, map_sb.bosssize.x, map_sb.bosssize.y, 0.332f, 0.0f, 0.166f, 1.0f);
	//マスの描画
	for (int i = 0; i < map_num; i++)
		DrawSpriteLeftTop(map_texture, map[i].pos.x, map[i].pos.y, map[i].size.x, map[i].size.y, map[i].u, map[i].v, map[i].uw, map[i].vh);
}

MAP* GetMapPoint()
{
	return &map[0];
}

MAP_SB* GetMapSB()
{
	return &map_sb;
}