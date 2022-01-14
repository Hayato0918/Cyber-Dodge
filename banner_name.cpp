//バナー名前処理 [banner_name.cpp]
#include "banner_name.h"
//システム.h
#include "texture.h"
#include "sprite.h"

#include "name_input.h"

//-----マクロ定義

//-----プロトタイプ宣言
BANNER_NAME banner_name[8];
//-----グローバル変数
int banner_nametexture;

//-----初期化処理
HRESULT InitBannerName(void)
{
	NAME_INPUTWARD* name_inputward = GetNameInputWard();

	float bannerwardx = 0.f;
	for (int i = 0; i < 8; i++)
	{
		banner_name[i].pos = D3DXVECTOR2(90.0f + bannerwardx, 0.0f);
		banner_name[i].size = D3DXVECTOR2(35.0f, 60.0f);
		banner_name[i].u = name_inputward[i].u;
		bannerwardx = bannerwardx + 35.f;
	}

	banner_nametexture = LoadTexture("data/TEXTURE/name/ward.png");

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
	NAME_INPUTWARD* name_inputward = GetNameInputWard();

	//バナーネーム
	for (int i = 0; i < 8; i++)
	{
		if(name_inputward[i].drawflag == true)
		DrawSpriteLeftTop(banner_nametexture, banner_name[i].pos.x, banner_name[i].pos.y, banner_name[i].size.x, banner_name[i].size.y,
			banner_name[i].u, 0.0f, 0.037037037f, 1.0f);
	}
}