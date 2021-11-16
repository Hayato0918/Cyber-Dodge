//マップ処理 [map.cpp]
#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "map_player.h"

//-----マクロ定義
#define map_num 24

//-----プロトタイプ宣言
MAP map[map_num];

//-----グローバル変数
int map_texture;

//-----初期化処理
HRESULT InitMap(void)
{
	for (int i = 0; i < map_num; i++)
	{
			map[i].size = D3DXVECTOR2(40.0f, 40.0f);
			map[i].uw = 0.25f;
			map[i].vh = 0.5f;
	}
	map_texture = LoadTexture("data/TEXTURE/map_point.png");

	//スタートマス/水色
	map[0].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 - map[0].size.x, 100);
	map[0].u = 0.5f;
	map[0].v = 0.5f;
	//0-0通常敵マス/オレンジ
	map[1].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.2 - map[1].size.x, 300);
	map[1].u = 0.0f;
	map[1].v = 0.5f;
	//0-1通常敵マス/オレンジ
	map[2].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.4 - map[2].size.x, 300);
	map[2].u = 0.0f;
	map[2].v = 0.5f;
	//0-2通常敵マス/オレンジ
	map[3].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.6 - map[3].size.x, 300);
	map[3].u = 0.0f;
	map[3].v = 0.5f;
	//0-3通常敵マス/オレンジ
	map[4].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.8 - map[4].size.x, 300);
	map[4].u = 0.0f;
	map[4].v = 0.5f;
	//1-0通常敵マス/オレンジ
	map[5].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.3 - map[5].size.x, 500);
	map[5].u = 0.0f;
	map[5].v = 0.5f;
	//1-1通常敵マス/オレンジ
	map[6].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 - map[6].size.x, 500);
	map[6].u = 0.0f;
	map[6].v = 0.5f;
	//1-2強敵マス/赤
	map[7].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.7 - map[7].size.x, 500);
	map[7].u = 0.0f;
	map[7].v = 0.0f;
	//2-0強敵マス/赤
	map[8].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.2 - map[8].size.x, 700);
	map[8].u = 0.0f;
	map[8].v = 0.0f;
	//2-1イベントマス/青
	map[9].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.2 - map[9].size.x, 700);
	map[9].u = 0.0f;
	map[9].v = 0.0f;











	return S_OK;
}

//-----終了処理
void UninitMap(void)
{

}

//-----更新処理
void UpdateMap(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (GetKeyboardPress(DIK_W))
	{
		for (int i = 0; i < map_num; i++)
			map[i].pos.y += 3;
	}
	if (GetKeyboardPress(DIK_S))
	{
		for (int i = 0; i < map_num; i++)
			map[i].pos.y -= 3;
	}



	////左から2番目上から1番目のマスに行ったら
	//if (map_player->LRcount == 1 && map_player->UDcount == 0)
	//	//バトルシーンに進む
	//	SceneTransition(SCENE_GAME);

	////-----ゲーム画面に戻る処理
	//if (GetKeyboardTrigger(DIK_M))
	//	SceneTransition(SCENE_GAME);
}

//-----描画処理
void DrawMap(void)
{
	for (int i = 0; i < map_num; i++)
		DrawSpriteLeftTop(map_texture, map[i].pos.x, map[i].pos.y, map[i].size.x, map[i].size.y,
			map[i].u, map[i].v, map[i].uw, map[i].vh);
}

//-----構造体ポインタ取得処理
MAP* GetMap()
{
	return &map[0];
}