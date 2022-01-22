//ウィンドウサイズ_背景処理 [windowsize_bg.cpp]
#include "windowsize_bg.h"
//
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

//-----マクロ定義

//-----プロトタイプ宣言
WINDOWSIZE_BG widowsize_bg;

//-----グローバル変数

//-----初期化処理
HRESULT InitWindowSizeBG(void)
{
	widowsize_bg.pos = D3DXVECTOR2(400.f, 300.f);
	widowsize_bg.size = D3DXVECTOR2(800.f, 500.f);
	widowsize_bg.texture = LoadTexture("data/TEXTURE/option/windowsize.png");


	return S_OK;
}

//-----終了処理
void UninitWindowSizeBG(void)
{

}

//-----更新処理
void UpdateWindowSizeBG(void)
{

}

//-----描画処理
void DrawWindowSizeBG(void)
{
	DrawSpriteLeftTop(widowsize_bg.texture, widowsize_bg.pos.x, widowsize_bg.pos.y, widowsize_bg.size.x, widowsize_bg.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
}