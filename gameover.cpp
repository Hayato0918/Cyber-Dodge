//ゲームオーバー処理 [gameover.cpp]
#include "gameover.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

//-----マクロ定義

//-----プロトタイプ宣言
GAMEOVER gameover;

//-----グローバル変数

//-----初期化処理
HRESULT InitGameOver(void)
{
	gameover.pos = D3DXVECTOR2(0.0f, 0.0f);
	gameover.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	gameover.texture = LoadTexture("data/TEXTURE/GAMEOVER.png");

	return S_OK;
}

//-----終了処理
void UninitGameOver(void)
{

}

//-----更新処理
void UpdateGameOver(void)
{
	if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
	{
		SceneTransition(SCENE_TITLE);
	}
}

//-----描画処理
void DrawGameOver(void)
{
	DrawSpriteLeftTop(gameover.texture, gameover.pos.x, gameover.pos.y, gameover.size.x, gameover.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}