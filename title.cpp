//タイトル処理 [title.cpp]
#include "title.h"
//
#include "sound.h"
//
#include "title_bg.h"
#include "title_teamname.h"
#include "title_gamestart.h"
#include "title_continue.h"
#include "title_ranking.h"
#include "title_option.h"
#include "title_exit.h"
#include "title_select.h"

#include "map_player.h"

#include "textureload.h"

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

	TextureLoad();
	InitTitleBG();
	InitTitleTeamName();
	InitTitleStart();
	InitTitleContinue();
	InitTitleRanking();
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
	UninitTitleRanking();
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
	UpdateTitleRanking();
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
	DrawTitleRanking();
	DrawTitleOption();
	DrawTitleExit();
}