//バナーお金処理 [banner_gold.cpp]
#include "banner_gold.h"
//システム.h
#include "texture.h"
#include "sprite.h"

//-----マクロ定義

//-----プロトタイプ宣言
BANNER_GOLD banner_gold[5];
BANNER_GOLDNUM banner_goldnum;

//-----グローバル変数

//-----初期化処理
HRESULT InitBannerGold(void)
{
	banner_gold[0].pos = D3DXVECTOR2(670.f, 0.0f);
	banner_gold[0].size = D3DXVECTOR2(120.0f, 60.0f);
	banner_gold[0].u = 0.0f;
	banner_gold[0].uw = 0.34f;
	banner_gold[0].v = 0.0f;
	banner_gold[0].vh = 1.0f;
	for (int i = 1; i < 5; i++)
	{
		banner_gold[i].v = 0.0f;
		banner_gold[i].vh = 1.0f;
		banner_gold[i].size = D3DXVECTOR2(33.0f, 60.0f);
		banner_gold[i].pos = D3DXVECTOR2(banner_gold[i - 1].pos.x + banner_gold[i - 1].size.x, 0.0f);
	}
	banner_gold[1].u = 0.34f;	//0
	banner_gold[1].uw = 0.07f;
	banner_gold[2].u = 0.41f;	//1
	banner_gold[2].uw = 0.07f;
	banner_gold[3].u = 0.48f;	//2
	banner_gold[3].uw = 0.07f;
	banner_gold[4].u = 0.55f;	//3
	banner_gold[4].uw = 0.058f;
	//banner_gold[1].u = 0.6f;	//4
	//banner_gold[1].uw = 0.07f;
	//banner_gold[2].u = 0.67f;	//5
	//banner_gold[2].uw = 0.07f;
	//banner_gold[3].u = 0.74f;	//6
	//banner_gold[3].uw = 0.07f;
	//banner_gold[4].u = 0.81f;	//7
	//banner_gold[4].uw = 0.068f;
	//banner_gold[1].u = 0.87f;	//8
	//banner_gold[1].uw = 0.07f;
	//banner_gold[2].u = 0.932f;	//9
	//banner_gold[2].uw = 0.068f;
	banner_goldnum.texture = LoadTexture("data/TEXTURE/goldnum.png");

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
	for (int i = 0; i < 5; i++)
		DrawSpriteLeftTop(banner_goldnum.texture, banner_gold[i].pos.x, banner_gold[i].pos.y, banner_gold[i].size.x, banner_gold[i].size.y,
			banner_gold[i].u, banner_gold[i].v, banner_gold[i].uw, banner_gold[i].vh);
}