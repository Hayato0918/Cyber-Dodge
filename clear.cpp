//クリア処理 [clear.cpp]
#include "clear.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

//-----マクロ定義

//-----プロトタイプ宣言
CLEAR clear;

//-----グローバル変数

//-----初期化処理
HRESULT InitClear(void)
{
	clear.pos = D3DXVECTOR2(0.0f, 0.0f);
	clear.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	clear.texture = LoadTexture("data/TEXTURE/GAMECLEAR.png");

	return S_OK;
}

//-----終了処理
void UninitClear(void)
{

}

//-----更新処理
void UpdateClear(void)
{
	if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
	{
		SceneTransition(SCENE_TITLE);
	}
}

//-----描画処理
void DrawClear(void)
{
	DrawSpriteLeftTop(clear.texture, clear.pos.x, clear.pos.y, clear.size.x, clear.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}