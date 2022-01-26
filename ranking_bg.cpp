//ランキング_背景処理 [ranking_bg.cpp]
#include "ranking_bg.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "Texture.h"
#include "sprite.h"
#include "sound.h"

//-----定数定義

//-----構造体宣言

//-----プロトタイプ宣言
RANKING_BG ranking_bg;

//-----グローバル変数の定義


//-----初期化関数
HRESULT InitRankingBG(void)
{
	ranking_bg.pos = D3DXVECTOR2(0.f, 0.f);
	ranking_bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	ranking_bg.texture = LoadTexture("data/TEXTURE/ranking.png");

	return S_OK;
}

//-----終了処理関数
void UninitRankingBG(void)
{

}

//-----更新処理をする関数
void UpdateRankingBG(void)
{

}

//-----描画処理関数
void DrawRankingBG(void)
{
	DrawSpriteLeftTop(ranking_bg.texture, ranking_bg.pos.x, ranking_bg.pos.y, ranking_bg.size.x, ranking_bg.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}