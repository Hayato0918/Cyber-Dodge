//名前決め_背景処理 [name_bg.cpp]
#include "name_bg.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "Texture.h"
#include "sprite.h"
#include "sound.h"

//-----定数定義

//-----構造体宣言

//-----プロトタイプ宣言
NAME_BG name_bg;

//-----グローバル変数の定義


//-----初期化関数
HRESULT InitNameBG(void)
{
	name_bg.pos = D3DXVECTOR2(0.f, 0.f);
	name_bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	name_bg.texture = LoadTexture("data/TEXTURE/name/bg.png");

	return S_OK;
}

//-----終了処理関数
void UninitNameBG(void)
{

}

//-----更新処理をする関数
void UpdateNameBG(void)
{

}

//-----描画処理関数
void DrawNameBG(void)
{
	DrawSpriteLeftTop(name_bg.texture, name_bg.pos.x, name_bg.pos.y, name_bg.size.x, name_bg.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}