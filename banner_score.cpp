//バナースコア処理 [banner_score.cpp]
#include "banner_score.h"
//システム.h
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "map_player.h"

//-----マクロ定義

//-----プロトタイプ宣言
BANNER_SCORE banner_score[4];
BANNER_SCORENUM banner_scorenum;

//-----グローバル変数

//-----初期化処理
HRESULT InitBannerScore(void)
{
	PLAYER* player = GetPlayer();
	MAP_PLAYER* map_player = GetMapPlayer();

	banner_scorenum.gold = player->gold;

	if (map_player->UDcount == 0)	//初期値は0
		banner_scorenum.gold = 1000;

	//場所、サイズ、uv決め
	for (int i = 0; i < 4; i++)
	{
		banner_score[i].size = D3DXVECTOR2(SCREEN_WIDTH * 0.01875f, SCREEN_HEIGHT * 0.055555f);
		banner_score[i].pos = D3DXVECTOR2(1420.f + i * banner_score[i].size.x, SCREEN_HEIGHT * 0.0055555f);
		banner_score[i].drawflag = true;
	}
	banner_scorenum.texture = LoadTexture("data/TEXTURE/number.png");

	return S_OK;
}

//-----終了処理
void UninitBannerScore(void)
{

}

//-----更新処理
void UpdateBannerScore(void)
{
	PLAYER* player = GetPlayer();
	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->UDcount > 0)
		banner_scorenum.gold = player->gold;

	banner_scorenum.a = banner_scorenum.gold * 0.001f;
	banner_scorenum.b = (banner_scorenum.gold - banner_scorenum.a * 1000) * 0.01f;
	banner_scorenum.c = (banner_scorenum.gold - banner_scorenum.a * 1000 - banner_scorenum.b * 100) * 0.1f;
	banner_scorenum.d = banner_scorenum.gold - banner_scorenum.a * 1000 - banner_scorenum.b * 100 - banner_scorenum.c * 10;

	//goldの1000の位
	if (banner_scorenum.a < 5)
	{
		banner_score[0].u = 0.2f * banner_scorenum.a;
		banner_score[0].v = 0.f;
	}
	if (banner_scorenum.a >= 5)
	{
		banner_score[0].u = 0.2f * banner_scorenum.a;
		banner_score[0].v = 0.5f;
	}
	if (banner_scorenum.a <= 0)
		banner_score[0].drawflag = false;
	if (banner_scorenum.a > 0)
		banner_score[0].drawflag = true;
	//goldの100の位
	if (banner_scorenum.b < 5)
	{
		banner_score[1].u = 0.2f * banner_scorenum.b;
		banner_score[1].v = 0.f;
	}
	if (banner_scorenum.b >= 5)
	{
		banner_score[1].u = 0.2f * banner_scorenum.b;
		banner_score[1].v = 0.5f;
	}
	if (banner_scorenum.b >= 0)
		banner_score[1].drawflag = true;
	if (banner_scorenum.a <= 0 && banner_scorenum.b <= 0)
		banner_score[1].drawflag = false;
	//goldの10の位
	if (banner_scorenum.c < 5)
	{
		banner_score[2].u = 0.2f * banner_scorenum.c;
		banner_score[2].v = 0.f;
	}
	if (banner_scorenum.c >= 5)
	{
		banner_score[2].u = 0.2f * banner_scorenum.c;
		banner_score[2].v = 0.5f;
	}
	if (banner_scorenum.c >= 0)
		banner_score[2].drawflag = true;
	if (banner_scorenum.a <= 0 && banner_scorenum.b <= 0 && banner_scorenum.c <= 0)
		banner_score[2].drawflag = false;
	//goldの1の位
	if (banner_scorenum.d < 5)
	{
		banner_score[3].u = 0.2f * banner_scorenum.d;
		banner_score[3].v = 0.f;
	}
	if (banner_scorenum.d >= 5)
	{
		banner_score[3].u = 0.2f * banner_scorenum.d;
		banner_score[3].v = 0.5f;
	}
}

//-----描画処理
void DrawBannerScore(void)
{
	//バナーGOLD
	for (int i = 0; i < 4; i++)
	{
		if (banner_score[i].drawflag == true)
			DrawSpriteLeftTop(banner_scorenum.texture, banner_score[i].pos.x, banner_score[i].pos.y, banner_score[i].size.x, banner_score[i].size.y,
				banner_score[i].u, banner_score[i].v, 0.2f, 0.5f);
	}
}