//タイトル終了ボタン処理 [title_exit.cpp]
#include "title_exit.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "title_bg.h"
#include "title_select.h"

//-----マクロ定義

//-----プロトタイプ宣言
TITLE_EXIT title_exit;

//-----グローバル変数

//-----初期化処理
HRESULT InitTitleExit(void)
{
	title_exit.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.794f, SCREEN_HEIGHT * 0.9f);	//1600:900→1270,810
	title_exit.size = D3DXVECTOR2(SCREEN_WIDTH * 0.238f, SCREEN_HEIGHT * 0.078f);	//1600:900→380,70
	title_exit.texture = LoadTexture("data/TEXTURE/title/exit.png");

	return S_OK;
}

//-----終了処理
void UninitTitleExit(void)
{

}

//-----更新処理
void UpdateTitleExit(void)
{
	TITLE_SELECT* title_select = GetTitleSelect();
	TITLE_BG* title_bg = GetTitleBG();

	if (title_select->count == 3 && GetKeyboardTrigger(DIK_RETURN) && title_bg->drawflag == true)
		exit(0);
}

//-----描画処理
void DrawTitleExit(void)
{
	TITLE_BG* title_bg = GetTitleBG();

	if (title_bg->drawflag == true)
		DrawSpriteLeftTop(title_exit.texture, title_exit.pos.x, title_exit.pos.y, title_exit.size.x, title_exit.size.y,
			0.0f, 0.0f, 1.0f, 1.0f);
}

TITLE_EXIT* GetTitleExit()
{
	return &title_exit;
}