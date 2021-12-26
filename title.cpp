//タイトル処理 [title.cpp]
#include "title.h"
//システム.h
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "map_point.h"
//
#include "title_bg.h"
#include "title_teamname.h"
#include "title_gamestart.h"
#include "title_exit.h"
#include "title_select.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数

//-----初期化処理
HRESULT InitTitle(void)
{
	InitTitleBG();
	InitTitleTeamName();
	InitTitleStart();
	InitTitleExit();
	InitTitleSelect();

	return S_OK;
}

//-----終了処理
void UninitTitle(void)
{
	UninitTitleBG();
	UninitTitleTeamName();
	UninitTitleStart();
	UninitTitleExit();
	UninitTitleSelect();
}

//-----更新処理
void UpdateTitle(void)
{
	UpdateTitleBG();
	UpdateTitleTeamName();
	UpdateTitleStart();
	UpdateTitleExit();
	UpdateTitleSelect();

	//if (PADUSE == 0)
	//{
	//	if (IsButtonTriggered(0, BUTTON_X) && GetFadeState() == FADE_NONE)
	//		SceneTransition(SCENE_MAP);
	//}
	//if (PADUSE == 1)
	//{
	//	if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
	//		SceneTransition(SCENE_MAP);
	//}
}

//-----描画処理
void DrawTitle(void)
{
	DrawTitleBG();
	DrawTitleTeamName();
	DrawTitleStart();
	DrawTitleExit();
	DrawTitleSelect();
}