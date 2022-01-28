//バナー背景処理 [banner_bg.cpp]
#include "banner_bg.h"
//システム.h
#include "texture.h"
#include "sprite.h"

//-----マクロ定義

//-----プロトタイプ宣言
BANNER_BG banner_bg;

//-----グローバル変数

//-----初期化処理
HRESULT InitBannerBG(void)
{
	banner_bg.pos = D3DXVECTOR2(0.0f, 0.0f);
	banner_bg.size = D3DXVECTOR2(1600.f, 60.f);
	return S_OK;
}

//-----終了処理
void UninitBannerBG(void)
{

}

//-----更新処理
void UpdateBannerBG(void)
{

}

//-----描画処理
void DrawBannerBG(void)
{
	//バナー背景
	DrawSpriteLeftTop(banner_bg.texture, banner_bg.pos.x, banner_bg.pos.y, banner_bg.size.x, banner_bg.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

BANNER_BG* GetBannerBG()
{
	return &banner_bg;
}