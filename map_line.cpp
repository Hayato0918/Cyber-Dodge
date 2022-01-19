//マップライン処理 [map_line.cpp]
#include "map_line.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "map_player.h"

//-----マクロ定義

//-----プロトタイプ宣言
MAP_LINE map_line;

//-----グローバル変数

//-----初期化処理
HRESULT InitMapLine(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->UDcount == 0)
	{
		map_line.pos = D3DXVECTOR2(0.0f, 50.0f);
		map_line.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT * 2.f);
		map_line.texture = LoadTexture("data/TEXTURE/map/mapline_1.png");
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
	if (GetKeyboardPress(DIK_W))
		map_line.pos.y += 3;
	if (GetKeyboardPress(DIK_S))
		map_line.pos.y -= 3;
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