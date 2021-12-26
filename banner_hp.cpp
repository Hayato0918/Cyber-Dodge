//バナーHP処理 [banner_hp.cpp]
#include "banner_hp.h"
//システム.h
#include "texture.h"
#include "sprite.h"

#include "player_hp.h"
#include "map_point.h"

//-----マクロ定義

//-----プロトタイプ宣言
BANNER_HP banner_hp[4];
BANNER_HPNUM banner_hpnum;

//-----グローバル変数

//-----初期化処理
HRESULT InitBannerHp(void)
{
	PLAYERHP* player_hp = GetPlayerHp();
	MAP_PLAYER* map_player = GetMapPlayer();

	//playerのHPバーサイズから、実数値を割り出す
	banner_hpnum.hp = player_hp->gaugesize.x * 0.3125f;
	if (map_player->UDcount == 0)	//初期値は200
		banner_hpnum.hp = 200;

	//場所、サイズ、uv決め
	//「HP:」の部分
	banner_hp[0].pos = D3DXVECTOR2(460.0f, 0.0f);
	banner_hp[0].size = D3DXVECTOR2(90.0f, 60.0f);
	banner_hp[0].u = 0.0f;
	banner_hp[0].uw = 0.21f;
	banner_hp[0].v = 0.0f;
	banner_hp[0].vh = 1.0f;
	//ここから数字
	for (int i = 1; i < 4; i++)
	{
		banner_hp[i].v = 0.0f;
		banner_hp[i].vh = 1.0f;
		banner_hp[i].size = D3DXVECTOR2(33.0f, 60.0f);
		banner_hp[i].pos = D3DXVECTOR2(banner_hp[i - 1].pos.x + banner_hp[i - 1].size.x, 0.0f);
	}
	banner_hpnum.texture = LoadTexture("data/TEXTURE/hpnum.png");

	return S_OK;
}

//-----終了処理
void UninitBannerHp(void)
{

}

//-----更新処理
void UpdateBannerHp(void)
{
	banner_hpnum.a = banner_hpnum.hp * 0.01f;
	banner_hpnum.b = (banner_hpnum.hp - banner_hpnum.a * 100) * 0.1f;
	banner_hpnum.c = banner_hpnum.hp - banner_hpnum.a * 100 - banner_hpnum.b * 10;

	//HPの100の位
	if (banner_hpnum.a == 1)
	{
		banner_hp[1].u = 0.3f;
		banner_hp[1].uw = 0.07f;
	}
	if (banner_hpnum.a == 2)
	{
		banner_hp[1].u = 0.37f;
		banner_hp[1].uw = 0.07f;
	}
	if (banner_hpnum.a == 3)
	{
		banner_hp[1].u = 0.44f;
		banner_hp[1].uw = 0.08f;
	}
	if (banner_hpnum.a == 4)
	{
		banner_hp[1].u = 0.52f;
		banner_hp[1].uw = 0.08f;
	}
	if (banner_hpnum.a == 5)
	{
		banner_hp[1].u = 0.6f;
		banner_hp[1].uw = 0.075f;
	}
	if (banner_hpnum.a == 6)
	{
		banner_hp[1].u = 0.675f;
		banner_hp[1].uw = 0.08f;
	}
	if (banner_hpnum.a == 7)
	{
		banner_hp[1].u = 0.755f;
		banner_hp[1].uw = 0.08f;
	}
	if (banner_hpnum.a == 8)
	{
		banner_hp[1].u = 0.835f;
		banner_hp[1].uw = 0.08f;
	}
	if (banner_hpnum.a == 9)
	{
		banner_hp[1].u = 0.915f;
		banner_hp[1].uw = 0.08f;
	}
	//HPの10の位
	if (banner_hpnum.b == 0)
	{
		banner_hp[2].u = 0.22f;
		banner_hp[2].uw = 0.08f;
	}
	if (banner_hpnum.b == 1)
	{
		banner_hp[2].u = 0.3f;
		banner_hp[2].uw = 0.07f;
	}
	if (banner_hpnum.b == 2)
	{
		banner_hp[2].u = 0.37f;
		banner_hp[2].uw = 0.07f;
	}
	if (banner_hpnum.b == 3)
	{
		banner_hp[2].u = 0.44f;
		banner_hp[2].uw = 0.08f;
	}
	if (banner_hpnum.b == 4)
	{
		banner_hp[2].u = 0.52f;
		banner_hp[2].uw = 0.08f;
	}
	if (banner_hpnum.b == 5)
	{
		banner_hp[2].u = 0.6f;
		banner_hp[2].uw = 0.075f;
	}
	if (banner_hpnum.b == 6)
	{
		banner_hp[2].u = 0.675f;
		banner_hp[2].uw = 0.08f;
	}
	if (banner_hpnum.b == 7)
	{
		banner_hp[2].u = 0.755f;
		banner_hp[2].uw = 0.08f;
	}
	if (banner_hpnum.b == 8)
	{
		banner_hp[2].u = 0.835f;
		banner_hp[2].uw = 0.08f;
	}
	if (banner_hpnum.b == 9)
	{
		banner_hp[2].u = 0.915f;
		banner_hp[2].uw = 0.08f;
	}
	//HPの1の位
	if (banner_hpnum.c == 0)
	{
		banner_hp[3].u = 0.22f;
		banner_hp[3].uw = 0.08f;
	}
	if (banner_hpnum.c == 1)
	{
		banner_hp[3].u = 0.3f;
		banner_hp[3].uw = 0.07f;
	}
	if (banner_hpnum.c == 2)
	{
		banner_hp[3].u = 0.37f;
		banner_hp[3].uw = 0.07f;
	}
	if (banner_hpnum.c == 3)
	{
		banner_hp[3].u = 0.44f;
		banner_hp[3].uw = 0.08f;
	}
	if (banner_hpnum.c == 4)
	{
		banner_hp[3].u = 0.52f;
		banner_hp[3].uw = 0.08f;
	}
	if (banner_hpnum.c == 5)
	{
		banner_hp[3].u = 0.6f;
		banner_hp[3].uw = 0.075f;
	}
	if (banner_hpnum.c == 6)
	{
		banner_hp[3].u = 0.675f;
		banner_hp[3].uw = 0.08f;
	}
	if (banner_hpnum.c == 7)
	{
		banner_hp[3].u = 0.755f;
		banner_hp[3].uw = 0.08f;
	}
	if (banner_hpnum.c == 8)
	{
		banner_hp[3].u = 0.835f;
		banner_hp[3].uw = 0.08f;
	}
	if (banner_hpnum.c == 9)
	{
		banner_hp[3].u = 0.915f;
		banner_hp[3].uw = 0.08f;
	}
}

//-----描画処理
void DrawBannerHp(void)
{
	//バナーHP
	for (int i = 0; i < 4; i++)
		DrawSpriteLeftTop(banner_hpnum.texture, banner_hp[i].pos.x, banner_hp[i].pos.y, banner_hp[i].size.x, banner_hp[i].size.y,
			banner_hp[i].u, banner_hp[i].v, banner_hp[i].uw, banner_hp[i].vh);
}