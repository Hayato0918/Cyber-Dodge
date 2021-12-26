//バナーバグゲージ処理 [banner_bug.cpp]
#include "banner_bug.h"
//システム.h
#include "texture.h"
#include "sprite.h"

#include "bugincrease.h"

//-----マクロ定義

//-----プロトタイプ宣言
BANNER_BUGFRAME banner_bugframe;
BANNER_BUGGAUGE banner_buggauge;

//-----グローバル変数

//-----初期化処理
HRESULT InitBannerBug(void)
{
	BUG* bug = GetBugIncrease();
	banner_bugframe.size = D3DXVECTOR2(600.0f, 60.0f);
	banner_bugframe.pos = D3DXVECTOR2(1000.f, 0.0f);
	banner_bugframe.texture = LoadTexture("data/TEXTURE/bugframe.png");
	banner_buggauge.size = D3DXVECTOR2(bug->gaugesize.x * 0.5f, 60.0f);
	banner_buggauge.pos = D3DXVECTOR2(1100.f, 0.0f);
	banner_buggauge.texture = LoadTexture("data/TEXTURE/obstacle.png");

	return S_OK;
}

//-----終了処理
void UninitBannerBug(void)
{

}

//-----更新処理
void UpdateBannerBug(void)
{

}

//-----描画処理
void DrawBannerBug(void)
{
	//バナーバグゲージ
	DrawSpriteLeftTop(banner_buggauge.texture, banner_buggauge.pos.x, banner_buggauge.pos.y, banner_buggauge.size.x, banner_buggauge.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
	//バナーバグゲージフレーム
	DrawSpriteLeftTop(banner_bugframe.texture, banner_bugframe.pos.x, banner_bugframe.pos.y, banner_bugframe.size.x, banner_bugframe.size.y,
			0.0f, 0.0f, 1.0f, 1.0f);
}