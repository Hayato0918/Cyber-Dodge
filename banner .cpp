//タイトル処理 [title.cpp]
#include "banner.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "player_hp.h"
#include "map_point.h"
#include "bugincrease.h"

//-----マクロ定義

//-----プロトタイプ宣言
BANNER banner;
BANNER_HP banner_hp[4];
BANNER_GOLD banner_gold[5];
BANNER_BUG banner_bug;

//-----グローバル変数

//-----初期化処理
HRESULT InitBanner(void)
{
	banner.bgpos = D3DXVECTOR2(0.0f, 0.0f);
	banner.bgsize = D3DXVECTOR2(SCREEN_WIDTH, 60.0f);
	banner.bgtexture = LoadTexture("data/TEXTURE/banner.png");

	banner.iconpos = D3DXVECTOR2(10.0f, 0.0f);
	banner.iconsize = D3DXVECTOR2(60.0f, 60.0f);
	banner.icontexture = LoadTexture("data/TEXTURE/map_point.png");

	banner.namepos = D3DXVECTOR2(90.0f, 0.0f);
	banner.namesize = D3DXVECTOR2(280.0f, 60.0f);
	banner.nametexture = LoadTexture("data/TEXTURE/playername.png");

	PLAYERHP* player_hp = GetPlayerHp();
	MAP_PLAYER* map_player = GetMapPlayer();
	banner.hp = player_hp->gaugesize.x * 0.3125f;
	if (map_player->UDcount == 0)
		banner.hp = 200;

	banner_hp[0].hppos = D3DXVECTOR2(450.0f, 0.0f);
	banner_hp[0].hpsize = D3DXVECTOR2(90.0f, 60.0f);
	banner_hp[0].u = 0.0f;
	banner_hp[0].uw = 0.21f;
	for (int i = 0; i < 4; i++)
	{
		banner_hp[i].v = 0.0f;
		banner_hp[i].vh = 1.0f;
	}
	for (int i = 1; i < 4; i++)
	{
		banner_hp[i].hpsize = D3DXVECTOR2(33.0f, 60.0f);
		banner_hp[i].hppos = D3DXVECTOR2(banner_hp[i-1].hppos.x + banner_hp[i-1].hpsize.x, 0.0f);
	}

	banner.hptexture = LoadTexture("data/TEXTURE/hpnum.png");

	banner_gold[0].goldpos = D3DXVECTOR2(banner_hp[3].hppos.x + banner_hp[3].hpsize.x + 50.0f, 0.0f);
	banner_gold[0].goldsize = D3DXVECTOR2(120.0f, 60.0f);
	banner_gold[0].u = 0.0f;
	banner_gold[0].uw = 0.34f;
	for (int i = 0; i < 5; i++)
	{
		banner_gold[i].v = 0.0f;
		banner_gold[i].vh = 1.0f;
	}
	for (int i = 1; i < 5; i++)
	{
		banner_gold[i].goldsize = D3DXVECTOR2(33.0f, 60.0f);
		banner_gold[i].goldpos = D3DXVECTOR2(banner_gold[i-1].goldpos.x + banner_gold[i-1].goldsize.x, 0.0f);
	}
	banner_gold[1].u = 0.34f;	//0
	banner_gold[1].uw = 0.07f;
	banner_gold[2].u = 0.41f;	//1
	banner_gold[2].uw = 0.07f;
	banner_gold[3].u = 0.48f;	//2
	banner_gold[3].uw = 0.07f;
	banner_gold[4].u = 0.55f;	//3
	banner_gold[4].uw = 0.058f;
	//banner_gold[1].u = 0.6f;	//4
	//banner_gold[1].uw = 0.07f;
	//banner_gold[2].u = 0.67f;	//5
	//banner_gold[2].uw = 0.07f;
	//banner_gold[3].u = 0.74f;	//6
	//banner_gold[3].uw = 0.07f;
	//banner_gold[4].u = 0.81f;	//7
	//banner_gold[4].uw = 0.068f;
	//banner_gold[1].u = 0.87f;	//8
	//banner_gold[1].uw = 0.07f;
	//banner_gold[2].u = 0.932f;	//9
	//banner_gold[2].uw = 0.068f;
	banner.goldtexture = LoadTexture("data/TEXTURE/goldnum.png");

	BUG* bug = GetBugIncrease();
	banner_bug.bugframesize = D3DXVECTOR2(600.0f, 60.0f);
	banner_bug.bugframepos = D3DXVECTOR2(banner_gold[4].goldpos.x + banner_gold[4].goldsize.x + 30.0f, 0.0f);
	banner_bug.frametexture = LoadTexture("data/TEXTURE/bugframe.png");
	banner_bug.buggaugesize = D3DXVECTOR2(bug->gaugesize.x * 0.5f, 60.0f);
	banner_bug.buggaugepos = D3DXVECTOR2(banner_gold[4].goldpos.x + banner_gold[4].goldsize.x + 30.0f, 0.0f);
	banner_bug.gaugetexture = LoadTexture("data/TEXTURE/obstacle.png");

	return S_OK;
}

//-----終了処理
void UninitBanner(void)
{

}

//-----更新処理
void UpdateBanner(void)
{
	banner.a = banner.hp * 0.01f;
	banner.b = (banner.hp - banner.a * 100) * 0.1f;
	banner.c = banner.hp - banner.a * 100 - banner.b * 10;

	//HPの100の位
	if (banner.a == 1)
	{
		banner_hp[1].u = 0.3f;
		banner_hp[1].uw = 0.07f;
	}
	if (banner.a == 2)
	{
		banner_hp[1].u = 0.37f;
		banner_hp[1].uw = 0.07f;
	}
	if (banner.a == 3)
	{
		banner_hp[1].u = 0.44f;
		banner_hp[1].uw = 0.08f;
	}
	if (banner.a == 4)
	{
		banner_hp[1].u = 0.52f;
		banner_hp[1].uw = 0.08f;
	}
	if (banner.a == 5)
	{
		banner_hp[1].u = 0.6f;
		banner_hp[1].uw = 0.075f;
	}
	if (banner.a == 6)
	{
		banner_hp[1].u = 0.675f;
		banner_hp[1].uw = 0.08f;
	}
	if (banner.a == 7)
	{
		banner_hp[1].u = 0.755f;
		banner_hp[1].uw = 0.08f;
	}
	if (banner.a == 8)
	{
		banner_hp[1].u = 0.835f;
		banner_hp[1].uw = 0.08f;
	}
	if (banner.a == 9)
	{
		banner_hp[1].u = 0.915f;
		banner_hp[1].uw = 0.08f;
	}
	//HPの10の位
	if (banner.b == 0)
	{
		banner_hp[2].u = 0.22f;
		banner_hp[2].uw = 0.08f;
	}
	if (banner.b == 1)
	{
		banner_hp[2].u = 0.3f;
		banner_hp[2].uw = 0.07f;
	}
	if (banner.b == 2)
	{
		banner_hp[2].u = 0.37f;
		banner_hp[2].uw = 0.07f;
	}
	if (banner.b == 3)
	{
		banner_hp[2].u = 0.44f;
		banner_hp[2].uw = 0.08f;
	}
	if (banner.b == 4)
	{
		banner_hp[2].u = 0.52f;
		banner_hp[2].uw = 0.08f;
	}
	if (banner.b == 5)
	{
		banner_hp[2].u = 0.6f;
		banner_hp[2].uw = 0.075f;
	}
	if (banner.b == 6)
	{
		banner_hp[2].u = 0.675f;
		banner_hp[2].uw = 0.08f;
	}
	if (banner.b == 7)
	{
		banner_hp[2].u = 0.755f;
		banner_hp[2].uw = 0.08f;
	}
	if (banner.b == 8)
	{
		banner_hp[2].u = 0.835f;
		banner_hp[2].uw = 0.08f;
	}
	if (banner.b == 9)
	{
		banner_hp[2].u = 0.915f;
		banner_hp[2].uw = 0.08f;
	}
	//HPの1の位
	if (banner.c == 0)
	{
		banner_hp[3].u = 0.22f;
		banner_hp[3].uw = 0.08f;
	}
	if (banner.c == 1)
	{
		banner_hp[3].u = 0.3f;
		banner_hp[3].uw = 0.07f;
	}
	if (banner.c == 2)
	{
		banner_hp[3].u = 0.37f;
		banner_hp[3].uw = 0.07f;
	}
	if (banner.c == 3)
	{
		banner_hp[3].u = 0.44f;
		banner_hp[3].uw = 0.08f;
	}
	if (banner.c == 4)
	{
		banner_hp[3].u = 0.52f;
		banner_hp[3].uw = 0.08f;
	}
	if (banner.c == 5)
	{
		banner_hp[3].u = 0.6f;
		banner_hp[3].uw = 0.075f;
	}
	if (banner.c == 6)
	{
		banner_hp[3].u = 0.675f;
		banner_hp[3].uw = 0.08f;
	}
	if (banner.c == 7)
	{
		banner_hp[3].u = 0.755f;
		banner_hp[3].uw = 0.08f;
	}
	if (banner.c == 8)
	{
		banner_hp[3].u = 0.835f;
		banner_hp[3].uw = 0.08f;
	}
	if (banner.c == 9)
	{
		banner_hp[3].u = 0.915f;
		banner_hp[3].uw = 0.08f;
	}
}

//-----描画処理
void DrawBanner(void)
{
	//バナー背景
	DrawSpriteLeftTop(banner.bgtexture, banner.bgpos.x, banner.bgpos.y, banner.bgsize.x, banner.bgsize.y, 0.0f, 0.0f, 1.0f, 1.0f);
	//バナーアイコン
	DrawSpriteLeftTop(banner.icontexture, banner.iconpos.x, banner.iconpos.y, banner.iconsize.x, banner.iconsize.y, 0.0f, 0.0f, 0.166f, 1.0f);
	//バナーネーム
	DrawSpriteLeftTop(banner.nametexture, banner.namepos.x, banner.namepos.y, banner.namesize.x, banner.namesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
	//バナーHP
	for(int i = 0; i < 4; i++)
	DrawSpriteLeftTop(banner.hptexture, banner_hp[i].hppos.x, banner_hp[i].hppos.y, banner_hp[i].hpsize.x, banner_hp[i].hpsize.y,
						banner_hp[i].u, banner_hp[i].v, banner_hp[i].uw, banner_hp[i].vh);
	//バナーGOLD
	for (int i = 0; i < 5; i++)
		DrawSpriteLeftTop(banner.goldtexture, banner_gold[i].goldpos.x, banner_gold[i].goldpos.y, banner_gold[i].goldsize.x, banner_gold[i].goldsize.y,
			banner_gold[i].u, banner_gold[i].v, banner_gold[i].uw, banner_gold[i].vh);
	//バナーバグゲージ
	DrawSpriteLeftTop(banner_bug.gaugetexture, banner_bug.buggaugepos.x, banner_bug.buggaugepos.y, banner_bug.buggaugesize.x, banner_bug.buggaugesize.y,
		0.0f, 0.0f, 1.0f, 1.0f);
	//バナーバグゲージフレーム
	DrawSpriteLeftTop(banner_bug.frametexture, banner_bug.bugframepos.x, banner_bug.bugframepos.y, banner_bug.bugframesize.x, banner_bug.bugframesize.y,
			0.0f, 0.0f, 1.0f, 1.0f);
}