//背景処理 [bg.cpp]
#include "bg.h"
#include "texture.h"
#include "sprite.h"
#include "areaChange.h"

//-----マクロ定義

//-----プロトタイプ宣言
BG bg;

//-----グローバル変数

//-----初期化処理
HRESULT InitBG(void)
{
	bg.pos = D3DXVECTOR2(0.0f, 0.0f);
	bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	bg.texture = LoadTexture("data/TEXTURE/gym.jpg");

	bg.clPos = D3DXVECTOR2(bg.size.x / 2, bg.pos.y + bg.size.y / 2);
	bg.clSize = D3DXVECTOR2(10.0f, bg.size.y);
	//bg.clTexture = LoadTexture("data/TEXTURE/gym_centerline.png");

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
	DrawSpriteColor(bg.clTexture, bg.clPos.x, bg.clPos.y, bg.clSize.x, bg.clSize.y, 0.0f, 0.0f, 1.0f, 1.0f,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
}

BG* GetBG(void)
{
	return &bg;
}

void SetCenterLine(float x)
{
	bg.clPos.x = x;
}