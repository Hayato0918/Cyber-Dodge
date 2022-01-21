//バナーHP処理 [banner_hp.cpp]
#include "banner_hp.h"
//システム.h
#include "texture.h"
#include "sprite.h"

#include "player_hp.h"
#include "map_player.h"

//-----マクロ定義

//-----プロトタイプ宣言
BANNER_HP banner_hp[3];
BANNER_HPNUM banner_hpnum;

//-----グローバル変数

//-----初期化処理
HRESULT InitBannerHp(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();
	PLAYERHP* player_hp = GetPlayerHp();

	//playerのHPバーサイズから、実数値を割り出す
	banner_hpnum.hp = player_hp->gaugesize.x * 0.3125f;
	if (map_player->UDcount == 0)	//初期値は200
		banner_hpnum.hp = 200;

	//場所、サイズ、uv決め
	for (int i = 0; i < 3; i++)
	{
		banner_hp[i].size = D3DXVECTOR2(30.0f, 50.0f);
		banner_hp[i].pos = D3DXVECTOR2(470.f + i * banner_hp[i].size.x, 5.0f);
		banner_hp[i].drawflag = true;
	}
	banner_hpnum.texture = LoadTexture("data/TEXTURE/number.png");

	return S_OK;
}

//-----終了処理
void UninitBannerHp(void)
{

}

//-----更新処理
void UpdateBannerHp(void)
{
	PLAYERHP* player_hp = GetPlayerHp();
	MAP_PLAYER* map_player = GetMapPlayer();

	//playerのHPバーサイズから、実数値を割り出す
	if(map_player->UDcount > 1)
	banner_hpnum.hp = player_hp->gaugesize.x * 0.3125f;

	banner_hpnum.a = banner_hpnum.hp * 0.01f;
	banner_hpnum.b = (banner_hpnum.hp - banner_hpnum.a * 100) * 0.1f;
	banner_hpnum.c = banner_hpnum.hp - banner_hpnum.a * 100 - banner_hpnum.b * 10;

	//HPの100の位
	if (banner_hpnum.a < 5)
	{
		banner_hp[0].u = 0.2f * banner_hpnum.a;
		banner_hp[0].v = 0.f;
	}
	if (banner_hpnum.a >= 5)
	{
		banner_hp[0].u = 0.2f * banner_hpnum.a;
		banner_hp[0].v = 0.5f;
	}
	if (banner_hpnum.a <= 0)
		banner_hp[0].drawflag = false;
	if (banner_hpnum.a > 0)
		banner_hp[0].drawflag = true;
	//HPの10の位
	if (banner_hpnum.b < 5)
	{
		banner_hp[1].u = 0.2f * banner_hpnum.b;
		banner_hp[1].v = 0.f;
	}
	if (banner_hpnum.b >= 5)
	{
		banner_hp[1].u = 0.2f * banner_hpnum.b;
		banner_hp[1].v = 0.5f;
	}
	if (banner_hpnum.a <= 0 && banner_hpnum.b <= 0)
		banner_hp[1].drawflag = false;
	if (banner_hpnum.b > 0)
		banner_hp[1].drawflag = true;
	//HPの1の位
	if (banner_hpnum.c < 5)
	{
		banner_hp[2].u = 0.2f * banner_hpnum.c;
		banner_hp[2].v = 0.f;
	}
	if (banner_hpnum.c >= 5)
	{
		banner_hp[2].u = 0.2f * banner_hpnum.c;
		banner_hp[2].v = 0.5f;
	}
}

//-----描画処理
void DrawBannerHp(void)
{
	//バナーHP
	for (int i = 0; i < 3; i++)
	{
		if(banner_hp[i].drawflag == true)
		DrawSpriteLeftTop(banner_hpnum.texture, banner_hp[i].pos.x, banner_hp[i].pos.y, banner_hp[i].size.x, banner_hp[i].size.y,
			banner_hp[i].u, banner_hp[i].v, 0.2f, 0.5f);
	}
}