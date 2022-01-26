//ゲームオーバー処理 [gameover.cpp]
#include "gameover.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include "gameover_F.h"
#include "gameover_score.h"

#include "save.h"

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

	InitGameOverF();
	InitGameOverScore();

	NameSave();
	FloorSave();
	ScoreSave();

	return S_OK;
}

//-----終了処理
void UninitGameOver(void)
{
	UninitGameOverF();
	UninitGameOverScore();
}

//-----更新処理
void UpdateGameOver(void)
{
	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_Y) && GetFadeState() == FADE_NONE)
			SceneTransition(SCENE_TITLE);
	}
	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
			SceneTransition(SCENE_TITLE);
	}

	UpdateGameOverF();
	UpdateGameOverScore();
}

//-----描画処理
void DrawGameOver(void)
{
	DrawSpriteLeftTop(gameover.texture, gameover.pos.x, gameover.pos.y, gameover.size.x, gameover.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

	DrawGameOverF();
	DrawGameOverScore();
}