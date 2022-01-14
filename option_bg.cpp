//設定_背景処理 [option_bg.cpp]
#include "option_bg.h"
//
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

//-----マクロ定義

//-----プロトタイプ宣言
OPTION_BG option_bg;

//-----グローバル変数

//-----初期化処理
HRESULT InitOptionBG(void)
{
	option_bg.pos = D3DXVECTOR2(0.f, 0.f);
	option_bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	option_bg.texture = LoadTexture("data/TEXTURE/option/option_bg.png");


	return S_OK;
}

//-----終了処理
void UninitOptionBG(void)
{

}

//-----更新処理
void UpdateOptionBG(void)
{

}

//-----描画処理
void DrawOptionBG(void)
{
	DrawSpriteLeftTop(option_bg.texture, option_bg.pos.x, option_bg.pos.y, option_bg.size.x, option_bg.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
}