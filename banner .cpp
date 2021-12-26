//バナー処理 [banner.cpp]
#include "banner.h"
//システム.h
#include "texture.h"
#include "sprite.h"

#include "banner_bg.h"
#include "banner_icon.h"
#include "banner_name.h"
#include "banner_hp.h"
#include "banner_gold.h"
#include "banner_bug.h"

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
	//icon
	InitBannerIcon();
	//name
	InitBannerName();
	//hp
	InitBannerHp();
	//gold
	InitBannerGold();
	//bug
	InitBannerBug();

	return S_OK;
}

//-----終了処理
void UninitBanner(void)
{
	//BG
	UninitBannerBG();
	//icon
	UninitBannerIcon();
	//name
	UninitBannerName();
	//hp
	UninitBannerHp();
	//gold
	UninitBannerGold();
	//bug
	UninitBannerBug();
}

//-----更新処理
void UpdateBanner(void)
{
	//BG
	UpdateBannerBG();
	//icon
	UpdateBannerIcon();
	//name
	UpdateBannerName();
	//hp
	UpdateBannerHp();
	//gold
	UpdateBannerGold();
	//bug
	UpdateBannerBug();
}

//-----描画処理
void DrawBanner(void)
{
	//BG
	DrawBannerBG();
	//icon
	DrawBannerIcon();
	//name
	DrawBannerName();
	//hp
	DrawBannerHp();
	//gold
	DrawBannerGold();
	//bug
	DrawBannerBug();
}