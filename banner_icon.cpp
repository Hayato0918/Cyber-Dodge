//バナーアイコン処理 [banner_icon.cpp]
#include "banner_icon.h"
//システム.h
#include "texture.h"
#include "sprite.h"

//-----マクロ定義

//-----プロトタイプ宣言
BANNER_ICON banner_icon;

//-----グローバル変数

//-----初期化処理
HRESULT InitBannerIcon(void)
{
	banner_icon.pos = D3DXVECTOR2(10.0f, 0.0f);
	banner_icon.size = D3DXVECTOR2(60.0f, 60.0f);
	banner_icon.texture = LoadTexture("data/TEXTURE/map_point.png");

	return S_OK;
}

//-----終了処理
void UninitBannerIcon(void)
{

}

//-----更新処理
void UpdateBannerIcon(void)
{

}

//-----描画処理
void DrawBannerIcon(void)
{
	//バナーアイコン
	DrawSpriteLeftTop(banner_icon.texture, banner_icon.pos.x, banner_icon.pos.y, banner_icon.size.x, banner_icon.size.y, 0.0f, 0.0f, 0.166f, 1.0f);
}