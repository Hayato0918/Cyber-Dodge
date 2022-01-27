//ランキング処理 [ranking.cpp]
#include "ranking.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"

#include "ranking_bg.h"
#include "ranking_name.h"
#include "ranking_floor.h"
#include "ranking_score.h"

//-----定数定義

//-----構造体宣言

//-----プロトタイプ宣言

//-----グローバル変数の定義


//-----初期化関数
HRESULT InitRanking(void)
{
	InitRankingBG();
	InitRankingName();
	InitRankingFloor();
	InitRankingScore();

	return S_OK;
}

//-----終了処理関数
void UninitRanking(void)
{
	UninitRankingBG();
	UninitRankingName();
	UninitRankingFloor();
	UninitRankingScore();
}

//-----更新処理をする関数
void UpdateRanking(void)
{
	UpdateRankingBG();
	UpdateRankingName();
	UpdateRankingFloor();
	UpdateRankingScore();

	if (IsButtonTriggered(0, BUTTON_Y))
		SceneTransition(SCENE_TITLE);
}

//-----描画処理関数
void DrawRanking(void)
{
	DrawRankingBG();
	DrawRankingName();
	DrawRankingFloor();
	DrawRankingScore();
}