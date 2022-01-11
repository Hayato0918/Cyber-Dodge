//スライムHP処理 [slime_hp.cpp]
#include "slime_hp.h"
#include "texture.h"
#include "sprite.h"

//-----マクロ定義

//-----プロトタイプ宣言
SLIMEHP slimehp;

//-----グローバル変数

//-----初期化処理
HRESULT InitSlimeHp(void)
{
	slimehp.gaugeonce = 8;

	slimehp.framepos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 + 60.f, SCREEN_HEIGHT - 100.0f);
	slimehp.framesize = D3DXVECTOR2(80.f * slimehp.gaugeonce, 60.0f); //slimehpバーフレームサイズ
	slimehp.frametexture = LoadTexture("data/TEXTURE/bugframe.png");

	slimehp.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5 + 60.f, SCREEN_HEIGHT - 100.0f);
	slimehp.gaugesize = D3DXVECTOR2(slimehp.framesize.x, slimehp.framesize.y); //残っているslimehpの量
	slimehp.gaugegreentexture = LoadTexture("data/TEXTURE/hp_green.png");
	slimehp.gaugeredtexture = LoadTexture("data/TEXTURE/obstacle.png");

	slimehp.hpsize = slimehp.gaugesize.x;
	slimehp.colorcangeflag = false;

	return S_OK;
}

//-----終了処理
void UninitSlimeHp(void)
{

}

//-----更新処理
void UpdateSlimeHp(void)
{
	if (slimehp.gaugesize.x <= slimehp.hpsize * 0.2f)
		slimehp.colorcangeflag = true;
	if (slimehp.gaugesize.x > slimehp.hpsize * 0.2f)
		slimehp.colorcangeflag = false;

	//HP上限の設定
	if (slimehp.gaugesize.x > 640.0f)
		slimehp.gaugesize.x = 640.0f;
}

//-----描画処理
void DrawSlimeHp(void)
{
	//-----HPゲージの描画
	if (slimehp.colorcangeflag == false)
		DrawSpriteLeftTop(slimehp.gaugegreentexture, slimehp.pos.x, slimehp.pos.y,
			slimehp.gaugesize.x, slimehp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
	if (slimehp.colorcangeflag == true)
		DrawSpriteLeftTop(slimehp.gaugeredtexture, slimehp.pos.x, slimehp.pos.y,
			slimehp.gaugesize.x, slimehp.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);

	//-----HPゲージの枠の描画
	DrawSpriteLeftTop(slimehp.frametexture, slimehp.pos.x, slimehp.pos.y,
			slimehp.framesize.x, slimehp.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----構造体ポインタ取得処理
SLIMEHP* GetSlimeHp()
{
	return &slimehp;
}