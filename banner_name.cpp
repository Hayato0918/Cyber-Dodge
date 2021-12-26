//バナー名前処理 [banner_name.cpp]
#include "banner_name.h"
//システム.h
#include "texture.h"
#include "sprite.h"

//-----マクロ定義

//-----プロトタイプ宣言
BANNER_NAME banner_name;
//-----グローバル変数

//-----初期化処理
HRESULT InitBannerName(void)
{
	banner_name.pos = D3DXVECTOR2(90.0f, 0.0f);
	banner_name.size = D3DXVECTOR2(280.0f, 60.0f);
	banner_name.texture = LoadTexture("data/TEXTURE/playername.png");

	return S_OK;
}

//-----終了処理
void UninitBannerName(void)
{

}

//-----更新処理
void UpdateBannerName(void)
{

}

//-----描画処理
void DrawBannerName(void)
{
	//バナーネーム
	DrawSpriteLeftTop(banner_name.texture, banner_name.pos.x, banner_name.pos.y, banner_name.size.x, banner_name.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}