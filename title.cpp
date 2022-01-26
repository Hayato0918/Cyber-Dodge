//タイトル処理 [title.cpp]
#include "title.h"
//
#include "sound.h"
//
#include "title_bg.h"
#include "title_teamname.h"
#include "title_gamestart.h"
#include "title_continue.h"
#include "title_option.h"
#include "title_exit.h"
#include "title_select.h"

#include "map_player.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数

//-----初期化処理
HRESULT InitTitle(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	map_player->UDcount = 0;
	map_player->gamecount = 0;
	map_player->floor = 0;

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
	DrawTitleSelect();
	DrawTitleStart();
	DrawTitleContinue();
	DrawTitleOption();
	DrawTitleExit();

}