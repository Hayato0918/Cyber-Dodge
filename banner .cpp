//バナー処理 [banner.cpp]
#include "banner.h"
//システム.h
#include "texture.h"
#include "sprite.h"

#include "banner_bg.h"
#include "banner_name.h"
#include "banner_hp.h"
#include "banner_gold.h"
#include "banner_bug.h"
#include "banner_score.h"

#include "map_point.h"
#include "bugincrease.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数

//-----初期化処理
HRESULT InitBanner(void)
{
	//BG
	InitBannerBG();
	//name
	InitBannerName();
	//hp
	InitBannerHp();
	//gold
	InitBannerGold();
	//bug
	InitBannerBug();
	//score
	InitBannerScore();

	return S_OK;
}

//-----終了処理
void UninitBanner(void)
{
	//BG
	UninitBannerBG();
	//name
	UninitBannerName();
	//hp
	UninitBannerHp();
	//gold
	UninitBannerGold();
	//bug
	UninitBannerBug();
	//score
	UninitBannerScore();
}

//-----更新処理
void UpdateBanner(void)
{
	//BG
	UpdateBannerBG();
	//name
	UpdateBannerName();
	//hp
	UpdateBannerHp();
	//gold
	UpdateBannerGold();
	//bug
	UpdateBannerBug();
	//score
	UpdateBannerScore();
}

//-----描画処理
void DrawBanner(void)
{
	//BG
	DrawBannerBG();
	//name
	DrawBannerName();
	//hp
	DrawBannerHp();
	//gold
	DrawBannerGold();
	//bug
	DrawBannerBug();
	//score
	DrawBannerScore();
}