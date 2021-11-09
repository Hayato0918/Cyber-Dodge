//背景処理 [bg.cpp]
#include "bg.h"
#include "texture.h"
#include "sprite.h"

//-----マクロ定義

//-----プロトタイプ宣言
BG bg;

//-----グローバル変数

//-----初期化処理
HRESULT InitBG(void)
{
	bg.pos = D3DXVECTOR2(0.0f, SCREEN_HEIGHT - 360.0f);
	bg.size = D3DXVECTOR2(960.0f, 360.0f);
	bg.texture = LoadTexture("data/TEXTURE/gym.png");

	return S_OK;
}

//-----終了処理
void UninitBG(void)
{

}

//-----更新処理
void UpdateBG(void)
{

}

//-----描画処理
void DrawBG(void)
{
	DrawSpriteLeftTop(bg.texture, bg.pos.x, bg.pos.y, bg.size.x, bg.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}