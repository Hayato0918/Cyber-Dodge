//タイトル設定ボタン処理 [title_exit.cpp]
#include "title_option.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "title_bg.h"
#include "title_select.h"

//-----マクロ定義

//-----プロトタイプ宣言
TITLE_OPTION title_option;

//-----グローバル変数

//-----初期化処理
HRESULT InitTitleOption(void)
{
	title_option.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.775f, SCREEN_HEIGHT * 0.822f);	//1600:900→1240,740
	title_option.size = D3DXVECTOR2(SCREEN_WIDTH * 0.238f, SCREEN_HEIGHT * 0.078f);	//1600:900→380,70
	title_option.texture = LoadTexture("data/TEXTURE/title/option.png");

	return S_OK;
}

//-----終了処理
void UninitTitleOption(void)
{

}

//-----更新処理
void UpdateTitleOption(void)
{
	TITLE_SELECT* title_select = GetTitleSelect();
	TITLE_BG* title_bg = GetTitleBG();

	if (PADUSE == 0)
	{
		if (title_select->count == 2 && IsButtonTriggered(0, BUTTON_Y) && title_bg->drawflag == true)
			SceneTransition(SCENE_OPTION);
	}

	if (PADUSE == 1)
	{
		if (title_select->count == 2 && GetKeyboardTrigger(DIK_RETURN) && title_bg->drawflag == true)
			SceneTransition(SCENE_OPTION);
	}
}

//-----描画処理
void DrawTitleOption(void)
{
	TITLE_BG* title_bg = GetTitleBG();

	if (title_bg->drawflag == true)
		DrawSpriteLeftTop(title_option.texture, title_option.pos.x, title_option.pos.y, title_option.size.x, title_option.size.y,
			0.0f, 0.0f, 1.0f, 1.0f);
}

TITLE_OPTION* GetTitleOption()
{
	return &title_option;
}