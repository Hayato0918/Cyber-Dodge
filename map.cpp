//マップ処理 [map.cpp]
#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "map_player.h"

//-----マクロ定義
#define map_x 4
#define map_y 4
#define mapdistance_x 190	//マスの左右間隔
#define mapdistance_y 135	//マスの上下間隔

//-----プロトタイプ宣言
MAP_POINT map_point;
MAP map[map_x][map_y];

//-----グローバル変数

//-----初期化処理
HRESULT InitMap(void)
{
	map_point.num = D3DXVECTOR2(map_x, map_y);
	map_point.distance = D3DXVECTOR2(mapdistance_x, mapdistance_y);

	for (int i = 0; i < map_point.num.y; i++)
	{
		for (int j = 0; j < map_point.num.x; j++)
		{
			map[j][i].pos = D3DXVECTOR2(195.0f + map_point.distance.x * j, 67.5f + map_point.distance.y * i);
			map[j][i].size = D3DXVECTOR2(40.0f, 40.0f);
			map[j][i].texture = LoadTexture("data/TEXTURE/map_point.png");
			map[j][i].u = 0.0f;
			map[j][i].v = 0.0f;
			map[j][i].uw = 0.25f;
			map[j][i].vh = 0.5f;

		}
	}

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

	//左から2番目上から1番目のマスに行ったら
	if (map_player->LRcount == 1 && map_player->UDcount == 0)
		//バトルシーンに進む
		SceneTransition(SCENE_GAME);

	//-----ゲーム画面に戻る処理
	if (GetKeyboardTrigger(DIK_M))
		SceneTransition(SCENE_GAME);
}

//-----描画処理
void DrawMap(void)
{
	for (int i = 0; i < map_y; i++)
	{
		for (int j = 0; j < map_x; j++)
			DrawSpriteLeftTop(map[j][i].texture, map[j][i].pos.x, map[j][i].pos.y, map[j][i].size.x, map[j][i].size.y,
				map[j][i].u, map[j][i].v, map[j][i].uw, map[j][i].vh);
	}
}

//-----構造体ポインタ取得処理
MAP_POINT* GetMapPoint()
{
	return &map_point;
}