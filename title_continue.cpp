//タイトルスタートボタン処理 [title_continue.cpp]
#include "title_continue.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "title_bg.h"
#include "title_select.h"

//-----マクロ定義

//-----プロトタイプ宣言
TITLE_CONTINUE title_continue;

//-----グローバル変数

//-----初期化処理
HRESULT InitTitleContinue(void)
{
	title_continue.pos = D3DXVECTOR2(1250.f, 600.f);	//1600:900→1210,670
	title_continue.size = D3DXVECTOR2(310.f, 70.f);	//1600:900→380,70

	return S_OK;
}

//-----終了処理
void UninitTitleContinue(void)
{

}

//-----更新処理
void UpdateTitleContinue(void)
{
	TITLE_BG* title_bg = GetTitleBG();
	TITLE_SELECT* title_select = GetTitleSelect();

	if (PADUSE == 0)
	{
		if (title_select->count == 1 && IsButtonTriggered(0, BUTTON_Y) && title_bg->drawflag == true)
		{
			SceneTransition(SCENE_RANKING);
		}
	}

	if (PADUSE == 1)
	{
		if (title_select->count == 1 && GetKeyboardTrigger(DIK_RETURN) && title_bg->drawflag == true)
		{
			SceneTransition(SCENE_RANKING);
		}
	}
}

//-----描画処理
void DrawTitleContinue(void)
{
	TITLE_BG* title_bg = GetTitleBG();

	if (title_bg->drawflag == true)
		DrawSpriteLeftTop(title_continue.texture, title_continue.pos.x, title_continue.pos.y, title_continue.size.x, title_continue.size.y,
			0.0f, 0.0f, 1.0f, 1.0f);
}

TITLE_CONTINUE* GetTitleContinue()
{
	return &title_continue;
}