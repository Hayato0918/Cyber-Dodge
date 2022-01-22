//ハッキングエフェクト処理 [hackeffect.cpp]
#include "hackeffect.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "map_point.h"

//-----マクロ定義

//-----プロトタイプ宣言
HACKEFFECT hackeffect;

//-----グローバル変数

//-----初期化処理
HRESULT InitHackEffect(void)
{
	hackeffect.pos = D3DXVECTOR2(0.0f, 0.0f);
	hackeffect.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	hackeffect.u = 0.f;
	hackeffect.v = 0.f;
	hackeffect.drawflag = false;
	hackeffect.animetime = 0.f;
	hackeffect.texture = LoadTexture("data/TEXTURE/hackingmenu/effect.png");

	return S_OK;
}

//-----終了処理
void UninitHackEffect(void)
{

}

//-----更新処理
void UpdateHackEffect(void)
{
	MAP_SB* map_sb = GetMapSB();

	if(map_sb->hackflag == true)
		hackeffect.drawflag = true;


	if (hackeffect.drawflag == true)
		hackeffect.animetime = hackeffect.animetime + 1.f;


	if (hackeffect.animetime > 0.f && hackeffect.animetime <= 5.f)
	{
		hackeffect.u = 0.f;
		hackeffect.v = 0.f;
	}
	if (hackeffect.animetime > 5.f && hackeffect.animetime <= 10.f)
		hackeffect.u = 0.125f;
	if (hackeffect.animetime > 10.f && hackeffect.animetime <= 15.f)
		hackeffect.u = 0.25f;
	if (hackeffect.animetime > 15.f && hackeffect.animetime <= 20.f)
		hackeffect.u = 0.375f;
	if (hackeffect.animetime > 20.f && hackeffect.animetime <= 25.f)
		hackeffect.u = 0.5f;
	if (hackeffect.animetime > 25.f && hackeffect.animetime <= 30.f)
		hackeffect.u = 0.625f;
	if (hackeffect.animetime > 30.f && hackeffect.animetime <= 35.f)
		hackeffect.u = 0.75f;
	if (hackeffect.animetime > 35.f && hackeffect.animetime <= 40.f)
		hackeffect.u = 0.875f;

	if (hackeffect.animetime > 40.f && hackeffect.animetime <= 45.f)
	{
		hackeffect.u = 0.f;
		hackeffect.v = 0.0909f;
	}
	if (hackeffect.animetime > 45.f && hackeffect.animetime <= 50.f)
		hackeffect.u = 0.125f;
	if (hackeffect.animetime > 50.f && hackeffect.animetime <= 55.f)
		hackeffect.u = 0.25f;
	if (hackeffect.animetime > 55.f && hackeffect.animetime <= 60.f)
		hackeffect.u = 0.375f;
	if (hackeffect.animetime > 60.f && hackeffect.animetime <= 65.f)
		hackeffect.u = 0.5f;
	if (hackeffect.animetime > 65.f && hackeffect.animetime <= 70.f)
		hackeffect.u = 0.625f;
	if (hackeffect.animetime > 70.f && hackeffect.animetime <= 75.f)
		hackeffect.u = 0.75f;
	if (hackeffect.animetime > 75.f && hackeffect.animetime <= 80.f)
		hackeffect.u = 0.875f;

	if (hackeffect.animetime > 80.f && hackeffect.animetime <= 85.f)
	{
		hackeffect.u = 0.f;
		hackeffect.v = 0.1818f;
	}
	if (hackeffect.animetime > 85.f && hackeffect.animetime <= 90.f)
		hackeffect.u = 0.125f;
	if (hackeffect.animetime > 90.f && hackeffect.animetime <= 95.f)
		hackeffect.u = 0.25f;
	if (hackeffect.animetime > 95.f && hackeffect.animetime <= 100.f)
		hackeffect.u = 0.375f;
	if (hackeffect.animetime > 100.f && hackeffect.animetime <= 105.f)
		hackeffect.u = 0.5f;
	if (hackeffect.animetime > 105.f && hackeffect.animetime <= 110.f)
		hackeffect.u = 0.625f;
	if (hackeffect.animetime > 110.f && hackeffect.animetime <= 115.f)
		hackeffect.u = 0.75f;
	if (hackeffect.animetime > 115.f && hackeffect.animetime <= 120.f)
		hackeffect.u = 0.875f;

	if (hackeffect.animetime > 120.f && hackeffect.animetime <= 125.f)
	{
		hackeffect.u = 0.f;
		hackeffect.v = 0.2727f;
	}
	if (hackeffect.animetime > 125.f && hackeffect.animetime <= 130.f)
		hackeffect.u = 0.125f;
	if (hackeffect.animetime > 130.f && hackeffect.animetime <= 135.f)
		hackeffect.u = 0.25f;
	if (hackeffect.animetime > 135.f && hackeffect.animetime <= 140.f)
		hackeffect.u = 0.375f;
	if (hackeffect.animetime > 140.f && hackeffect.animetime <= 145.f)
		hackeffect.u = 0.5f;
	if (hackeffect.animetime > 145.f && hackeffect.animetime <= 150.f)
		hackeffect.u = 0.625f;
	if (hackeffect.animetime > 150.f && hackeffect.animetime <= 155.f)
		hackeffect.u = 0.75f;
	if (hackeffect.animetime > 155.f && hackeffect.animetime <= 160.f)
		hackeffect.u = 0.875f;

	if (hackeffect.animetime > 160.f && hackeffect.animetime <= 165.f)
	{
		hackeffect.u = 0.f;
		hackeffect.v = 0.3636f;
	}
	if (hackeffect.animetime > 165.f && hackeffect.animetime <= 170.f)
		hackeffect.u = 0.125f;
	if (hackeffect.animetime > 170.f && hackeffect.animetime <= 175.f)
		hackeffect.u = 0.25f;
	if (hackeffect.animetime > 175.f && hackeffect.animetime <= 180.f)
		hackeffect.u = 0.375f;
	if (hackeffect.animetime > 180.f && hackeffect.animetime <= 185.f)
		hackeffect.u = 0.5f;
	if (hackeffect.animetime > 185.f && hackeffect.animetime <= 190.f)
		hackeffect.u = 0.625f;
	if (hackeffect.animetime > 190.f && hackeffect.animetime <= 195.f)
		hackeffect.u = 0.75f;
	if (hackeffect.animetime > 195.f && hackeffect.animetime <= 200.f)
		hackeffect.u = 0.875f;

	if (hackeffect.animetime > 200.f && hackeffect.animetime <= 205.f)
	{
		hackeffect.u = 0.f;
		hackeffect.v = 0.4545f;
	}
	if (hackeffect.animetime > 205.f && hackeffect.animetime <= 210.f)
		hackeffect.u = 0.125f;
	if (hackeffect.animetime > 210.f && hackeffect.animetime <= 215.f)
		hackeffect.u = 0.25f;
	if (hackeffect.animetime > 215.f && hackeffect.animetime <= 220.f)
		hackeffect.u = 0.375f;
	if (hackeffect.animetime > 220.f && hackeffect.animetime <= 225.f)
		hackeffect.u = 0.5f;
	if (hackeffect.animetime > 225.f && hackeffect.animetime <= 230.f)
		hackeffect.u = 0.625f;
	if (hackeffect.animetime > 230.f && hackeffect.animetime <= 235.f)
		hackeffect.u = 0.75f;
	if (hackeffect.animetime > 235.f && hackeffect.animetime <= 240.f)
		hackeffect.u = 0.875f;

	if (hackeffect.animetime > 240.f && hackeffect.animetime <= 245.f)
	{
		hackeffect.u = 0.f;
		hackeffect.v = 0.5454f;
	}
	if (hackeffect.animetime > 245.f && hackeffect.animetime <= 250.f)
		hackeffect.u = 0.125f;
	if (hackeffect.animetime > 250.f && hackeffect.animetime <= 255.f)
		hackeffect.u = 0.25f;
	if (hackeffect.animetime > 255.f && hackeffect.animetime <= 260.f)
		hackeffect.u = 0.375f;
	if (hackeffect.animetime > 260.f && hackeffect.animetime <= 265.f)
		hackeffect.u = 0.5f;
	if (hackeffect.animetime > 265.f && hackeffect.animetime <= 270.f)
		hackeffect.u = 0.625f;
	if (hackeffect.animetime > 270.f && hackeffect.animetime <= 275.f)
		hackeffect.u = 0.75f;
	if (hackeffect.animetime > 275.f && hackeffect.animetime <= 280.f)
		hackeffect.u = 0.875f;

	if (hackeffect.animetime > 280.f && hackeffect.animetime <= 285.f)
	{
		hackeffect.u = 0.f;
		hackeffect.v = 0.6363f;
	}
	if (hackeffect.animetime > 285.f && hackeffect.animetime <= 290.f)
		hackeffect.u = 0.125f;
	if (hackeffect.animetime > 290.f && hackeffect.animetime <= 295.f)
		hackeffect.u = 0.25f;
	if (hackeffect.animetime > 295.f && hackeffect.animetime <= 300.f)
		hackeffect.u = 0.375f;
	if (hackeffect.animetime > 300.f && hackeffect.animetime <= 305.f)
		hackeffect.u = 0.5f;
	if (hackeffect.animetime > 305.f && hackeffect.animetime <= 310.f)
		hackeffect.u = 0.625f;
	if (hackeffect.animetime > 310.f && hackeffect.animetime <= 315.f)
		hackeffect.u = 0.75f;
	if (hackeffect.animetime > 315.f && hackeffect.animetime <= 320.f)
		hackeffect.u = 0.875f;

	if (hackeffect.animetime > 320.f && hackeffect.animetime <= 325.f)
	{
		hackeffect.u = 0.f;
		hackeffect.v = 0.7272f;
	}
	if (hackeffect.animetime > 325.f && hackeffect.animetime <= 330.f)
		hackeffect.u = 0.125f;
	if (hackeffect.animetime > 330.f && hackeffect.animetime <= 335.f)
		hackeffect.u = 0.25f;
	if (hackeffect.animetime > 335.f && hackeffect.animetime <= 340.f)
		hackeffect.u = 0.375f;
	if (hackeffect.animetime > 340.f && hackeffect.animetime <= 345.f)
		hackeffect.u = 0.5f;
	if (hackeffect.animetime > 345.f && hackeffect.animetime <= 350.f)
		hackeffect.u = 0.625f;
	if (hackeffect.animetime > 350.f && hackeffect.animetime <= 355.f)
		hackeffect.u = 0.75f;
	if (hackeffect.animetime > 355.f && hackeffect.animetime <= 360.f)
		hackeffect.u = 0.875f;

	if (hackeffect.animetime > 360.f && hackeffect.animetime <= 365.f)
	{
		hackeffect.u = 0.f;
		hackeffect.v = 0.8181f;
	}
	if (hackeffect.animetime > 365.f && hackeffect.animetime <= 370.f)
		hackeffect.u = 0.125f;
	if (hackeffect.animetime > 370.f && hackeffect.animetime <= 375.f)
		hackeffect.u = 0.25f;
	if (hackeffect.animetime > 375.f && hackeffect.animetime <= 380.f)
		hackeffect.u = 0.375f;
	if (hackeffect.animetime > 380.f && hackeffect.animetime <= 385.f)
		hackeffect.u = 0.5f;
	if (hackeffect.animetime > 385.f && hackeffect.animetime <= 390.f)
		hackeffect.u = 0.625f;
	if (hackeffect.animetime > 390.f && hackeffect.animetime <= 395.f)
		hackeffect.u = 0.75f;
	if (hackeffect.animetime > 395.f && hackeffect.animetime <= 400.f)
		hackeffect.u = 0.875f;

	if (hackeffect.animetime > 400.f && hackeffect.animetime <= 405.f)
	{
		hackeffect.u = 0.f;
		hackeffect.v = 0.909f;
	}
	if (hackeffect.animetime > 405.f && hackeffect.animetime <= 410.f)
		hackeffect.u = 0.125f;
	if (hackeffect.animetime > 410.f && hackeffect.animetime <= 415.f)
		hackeffect.u = 0.25f;
	if (hackeffect.animetime > 415.f && hackeffect.animetime <= 420.f)
		hackeffect.u = 0.375f;
	if (hackeffect.animetime > 420.f && hackeffect.animetime <= 425.f)
		hackeffect.u = 0.5f;
	if (hackeffect.animetime > 425.f && hackeffect.animetime <= 430.f)
		hackeffect.u = 0.625f;
	if (hackeffect.animetime > 430.f && hackeffect.animetime <= 435.f)
		hackeffect.u = 0.75f;
	if (hackeffect.animetime > 435.f && hackeffect.animetime <= 440.f)
		hackeffect.u = 0.875f;

	if (hackeffect.animetime > 420.f)
	{
		map_sb->hackflag = false;
		hackeffect.drawflag = false;
		hackeffect.animetime = 0.f;
	}
}

//-----描画処理
void DrawHackEffect(void)
{
	if(hackeffect.drawflag == true)
	DrawSpriteLeftTop(hackeffect.texture, hackeffect.pos.x, hackeffect.pos.y, hackeffect.size.x, hackeffect.size.y,
		hackeffect.u, hackeffect.v, 0.125f, 0.0909f);
}

HACKEFFECT* GetHackEffect()
{
	return &hackeffect;
}