//タイトル処理 [title.cpp]
#include "title.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "map_point.h"

//-----マクロ定義

//-----プロトタイプ宣言
TITLE title;

//-----グローバル変数

//-----初期化処理
HRESULT InitTitle(void)
{
	title.pos = D3DXVECTOR2(0.0f, 0.0f);
	title.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	title.texture = LoadTexture("data/TEXTURE/title.png");

	MAP_PLAYER* map_player = GetMapPlayer();
	map_player->UDcount = 0;

	return S_OK;
}

//-----終了処理
void UninitTitle(void)
{

}

//-----更新処理
void UpdateTitle(void)
{
	if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
	{
		SceneTransition(SCENE_MAP);
	}
}

//-----描画処理
void DrawTitle(void)
{
	DrawSpriteLeftTop(title.texture, title.pos.x, title.pos.y, title.size.x, title.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}