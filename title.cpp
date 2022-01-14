//タイトル処理 [title.cpp]
#include "title.h"
//
#include "title_bg.h"
#include "title_teamname.h"
#include "title_gamestart.h"
#include "title_continue.h"
#include "title_option.h"
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
	InitTitleContinue();
	InitTitleOption();
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
	UninitTitleContinue();
	UninitTitleOption();
	UninitTitleExit();
	UninitTitleSelect();
}

//-----更新処理
void UpdateTitle(void)
{
	UpdateTitleBG();
	UpdateTitleTeamName();
	UpdateTitleStart();
	UpdateTitleContinue();
	UpdateTitleOption();
	UpdateTitleExit();
	UpdateTitleSelect();
}

//-----描画処理
void DrawTitle(void)
{
	DrawTitleBG();
	DrawTitleTeamName();
	DrawTitleStart();
	DrawTitleContinue();
	DrawTitleOption();
	DrawTitleExit();
	DrawTitleSelect();
}