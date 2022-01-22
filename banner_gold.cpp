//バナーお金処理 [banner_gold.cpp]
#include "banner_gold.h"
//システム.h
#include "texture.h"
#include "sprite.h"

//-----マクロ定義

//-----プロトタイプ宣言
BANNER_GOLD banner_gold[4];
BANNER_GOLDNUM banner_goldnum;

//-----グローバル変数

//-----初期化処理
HRESULT InitBannerGold(void)
{
	//場所、サイズ、uv決め
	for (int i = 0; i < 4; i++)
	{
		banner_gold[i].size = D3DXVECTOR2(SCREEN_WIDTH * 0.01875f, SCREEN_HEIGHT * 0.055555f);
		banner_gold[i].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5375f + i * banner_gold[i].size.x, SCREEN_HEIGHT * 0.0055555f);
		banner_gold[i].drawflag = true;
	}
	banner_goldnum.texture = LoadTexture("data/TEXTURE/number.png");

	return S_OK;
}

//-----終了処理
void UninitBannerGold(void)
{

}

//-----更新処理
void UpdateBannerGold(void)
{

}

//-----描画処理
void DrawBannerGold(void)
{
	//バナーGOLD
	for (int i = 0; i < 4; i++)
	{
		if(banner_gold[i].drawflag == true)
		DrawSpriteLeftTop(banner_goldnum.texture, banner_gold[i].pos.x, banner_gold[i].pos.y, banner_gold[i].size.x, banner_gold[i].size.y,
			banner_gold[i].u, banner_gold[i].v, 0.2f, 0.5f);
	}
}