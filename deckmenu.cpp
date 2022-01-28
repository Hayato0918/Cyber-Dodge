//デッキメニュー処理 [deckmenu.cpp]
#include "deckmenu.h"
//システム.h
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "map_player.h"
#include "skillrandom.h"

//-----マクロ定義

#define CARD_SPACE_WIDTH 300.0f
#define CARD_SPACE_HIGHT 300.0f
#define ynum 12
#define xnum 3

//-----プロトタイプ宣言
DECKMENUCARD deckmenu_card[ynum][xnum];
DECKMENU deckmenu;
SELECTION g_Selection;
NUMBER g_number;

//-----グローバル変数
int a, b;
int deckmenutexture;

//-----初期化処理
HRESULT InitDeckMenu(void)
{
	deckmenutexture = LoadTexture("data/TEXTURE/skill/skill.png");

	a = 0;
	b = 0;

	MAP_PLAYER* map_player = GetMapPlayer();

	for (int y = 0; y < ynum; y++)
	{
		for (int x = 0; x < xnum; x++)
		{
			deckmenu_card[y][x].pos = D3DXVECTOR2(120.0f + CARD_SPACE_WIDTH * x, 120.0f + CARD_SPACE_HIGHT * y + CARD_SPACE_HIGHT * y * 0.3f);
			deckmenu_card[y][x].size = D3DXVECTOR2(200.0f, 300.0f);
			deckmenu_card[y][x].drawflag = false;
			deckmenu_card[y][x].nottexture = LoadTexture("data/TEXTURE/deckmenu/notget.png");
		}
	}

	RANDOM* random = GetRandom();
	SKILL* skill = GetSkill();

	for (int i = 0; i < skill->slot; i++)
	{
		if (b == xnum)
		{
			a = a + 1;
			b = 0;
		}


		//割り当てられたcodeに対応したテクスチャを表示
		for (int j = 1; j < 27; j++)
		{
			if (random[i].code == j)
			{
				deckmenu_card[a][b].u = 0.0384615385f * (j - 1);
				deckmenu_card[a][b].drawflag = true;
			}
		}

		b = b + 1;
	}

	deckmenu.pos = D3DXVECTOR2(0.0f, 0.0f);
	deckmenu.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	deckmenu.texture = LoadTexture("data/TEXTURE/deckmenu/bg.png");
	deckmenu.use = false;
	deckmenu.openflag = false;

	g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x, deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
	g_Selection.size = D3DXVECTOR2(200.0f, 300.0f);
	g_Selection.texture = LoadTexture("data/TEXTURE/deckmenu/frame.png");
	g_Selection.use = true;
	g_Selection.LRcount = 0;
	g_Selection.UDcount = 0;

	g_number.pos = D3DXVECTOR2(1415.f, 115.0f);
	g_number.size = D3DXVECTOR2(60.0f, 60.0f);
	g_number.texture = LoadTexture("data/TEXTURE/number.png");
	g_number.u = 0.2f;
	g_number.v = 0.0f;
	g_number.uw = 0.2f;
	g_number.vh = 0.5f;

	return S_OK;
}

//-----終了処理
void UninitDeckMenu(void)
{

}

//-----更新処理
void UpdateDeckMenu(void)
{
	// ページ数切り替え処理
	if (g_Selection.UDcount == 0)
	{
		g_number.u = 0.2f;
		g_number.v = 0.0f;
	}
	if (g_Selection.UDcount == 2)
	{
		g_number.u = 0.4f;
		g_number.v = 0.0f;
	}
	if (g_Selection.UDcount == 4)
	{
		g_number.u = 0.6f;
		g_number.v = 0.0f;
	}
	if (g_Selection.UDcount == 6)
	{
		g_number.u = 0.8f;
		g_number.v = 0.0f;
	}
	if (g_Selection.UDcount == 8)
	{
		g_number.u = 0.0f;
		g_number.v = 0.5f;
	}
	if (g_Selection.UDcount == 10)
	{
		g_number.u = 0.2f;
		g_number.v = 0.5f;
	}
	if (g_Selection.UDcount == 12)
	{
		g_number.u = 0.4f;
		g_number.v = 0.5f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_RIGHT) && g_Selection.LRcount >= xnum - 1 && g_Selection.use == true)
		{
			g_Selection.pos = D3DXVECTOR2(1100.f, 690.f);
			g_Selection.size = D3DXVECTOR2(460.f, 170.f);
		}

		//右移動
		if (IsButtonTriggered(0, BUTTON_RIGHT) && g_Selection.LRcount < xnum - 1 && g_Selection.use == true)
		{
			g_Selection.LRcount = g_Selection.LRcount + 1;
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
		}
		//左移動
		if (IsButtonTriggered(0, BUTTON_LEFT) && g_Selection.LRcount > 0 && g_Selection.use == true)
		{
			g_Selection.LRcount = g_Selection.LRcount - 1;
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
			g_Selection.size = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].size.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].size.y);
		}
		//下移動
		if (IsButtonTriggered(0, BUTTON_DOWN) && g_Selection.UDcount < ynum - 1 && g_Selection.use == true)
		{
			g_Selection.UDcount = g_Selection.UDcount + 1;
			//2段を区切りに、カードの位置を移動
			if (g_Selection.UDcount == 2 || g_Selection.UDcount == 4 || g_Selection.UDcount == 6 || g_Selection.UDcount == 8 || g_Selection.UDcount == 10 || g_Selection.UDcount == 12)
			{
				for (int y = 0; y < ynum; y++)
				{
					for (int x = 0; x < xnum; x++)
						deckmenu_card[y][x].pos.y = deckmenu_card[y][x].pos.y - 360.0f - CARD_SPACE_HIGHT * 2 + CARD_SPACE_HIGHT * 2 * 0.3f;
				}
			}
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
		}

		if (IsButtonTriggered(0, BUTTON_UP) && g_Selection.UDcount > 0 && g_Selection.use == true)
		{
			g_Selection.UDcount = g_Selection.UDcount - 1;
			//2段を区切りに、カードの位置を移動
			if (g_Selection.UDcount == 1 || g_Selection.UDcount == 3 || g_Selection.UDcount == 5 || g_Selection.UDcount == 7
				|| g_Selection.UDcount == 9 || g_Selection.UDcount == 11)
			{
				for (int y = 0; y < ynum; y++)
				{
					for (int x = 0; x < xnum; x++)
						deckmenu_card[y][x].pos.y = deckmenu_card[y][x].pos.y + 360.0f + CARD_SPACE_HIGHT * 2 - CARD_SPACE_HIGHT * 2 * 0.3f;
				}
			}
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
		}

		//「立ち去る」コマンドの場所でEnterキーを押したらMAPに戻る
		if (IsButtonTriggered(0, BUTTON_Y) && g_Selection.pos == D3DXVECTOR2(1100.f, 690.f))
		{
			deckmenu.openflag = true;
			SceneTransition(SCENE_MAP);
			deckmenu.use = false;
		}
	}

	if (PADUSE == 1)
	{
		//右移動
		if (GetKeyboardRelease(DIK_D) && g_Selection.LRcount < xnum - 1 && g_Selection.use == true)
		{
			g_Selection.LRcount = g_Selection.LRcount + 1;
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
		}
		//左移動
		if (GetKeyboardRelease(DIK_A) && g_Selection.LRcount > 0 && g_Selection.use == true)
		{
			g_Selection.LRcount = g_Selection.LRcount - 1;
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
		}
		//下移動
		if (GetKeyboardTrigger(DIK_S) && g_Selection.UDcount < ynum - 1 && g_Selection.use == true)
		{
			g_Selection.UDcount = g_Selection.UDcount + 1;
			//2段を区切りに、カードの位置を移動
			if (g_Selection.UDcount == 2 || g_Selection.UDcount == 4 || g_Selection.UDcount == 6 || g_Selection.UDcount == 8 || g_Selection.UDcount == 10 || g_Selection.UDcount == 12)
			{
				for (int y = 0; y < ynum; y++)
				{
					for (int x = 0; x < xnum; x++)
						deckmenu_card[y][x].pos.y = deckmenu_card[y][x].pos.y - 360.0f - CARD_SPACE_HIGHT * 2 + CARD_SPACE_HIGHT * 2 * 0.3f;
				}
			}
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
		}

		if (GetKeyboardTrigger(DIK_W) && g_Selection.UDcount > 0 && g_Selection.use == true)
		{
			g_Selection.UDcount = g_Selection.UDcount - 1;
			//2段を区切りに、カードの位置を移動
			if (g_Selection.UDcount == 1 || g_Selection.UDcount == 3 || g_Selection.UDcount == 5 || g_Selection.UDcount == 7
				|| g_Selection.UDcount == 9 || g_Selection.UDcount == 11)
			{
				for (int y = 0; y < ynum; y++)
				{
					for (int x = 0; x < xnum; x++)
						deckmenu_card[y][x].pos.y = deckmenu_card[y][x].pos.y + 360.0f + CARD_SPACE_HIGHT * 2 - CARD_SPACE_HIGHT * 2 * 0.3f;
				}
			}
			g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
				deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
		}

		//「立ち去る」コマンドの場所でEnterキーを押したらMAPに戻る
		if (GetKeyboardTrigger(DIK_RETURN) && g_Selection.pos == D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x,
			deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y))
		{
			deckmenu.openflag = true;
			SceneTransition(SCENE_MAP);
			deckmenu.use = false;
		}
	}
}

//-----描画処理
void DrawDeckMenu(void)
{
	//メニュー背景の描画
	DrawSpriteLeftTop(deckmenu.texture, deckmenu.pos.x, deckmenu.pos.y, deckmenu.size.x, deckmenu.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	//スキルカード描画
	for (int y = 0; y < ynum; y++)
	{
		for (int x = 0; x < xnum; x++)
		{
			if(deckmenu_card[y][x].drawflag == true)
			DrawSpriteLeftTop(deckmenutexture, deckmenu_card[y][x].pos.x, deckmenu_card[y][x].pos.y,
				deckmenu_card[y][x].size.x, deckmenu_card[x][y].size.y, deckmenu_card[x][y].u, 0.0f, 0.0384615385f, 1.0f);

			if (deckmenu_card[y][x].drawflag == false)
				DrawSpriteLeftTop(deckmenu_card[y][x].nottexture, deckmenu_card[y][x].pos.x, deckmenu_card[y][x].pos.y,
					deckmenu_card[y][x].size.x, deckmenu_card[x][y].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		}
	}
	//セレクトフレーム描画
	DrawSpriteLeftTop(g_Selection.texture, g_Selection.pos.x, g_Selection.pos.y, g_Selection.size.x, g_Selection.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	//現在のページ数描画
	DrawSpriteLeftTop(g_number.texture, g_number.pos.x, g_number.pos.y, g_number.size.x, g_number.size.y, g_number.u, g_number.v, g_number.uw, g_number.vh);
}

//-----構造体ポインタ取得処理
SELECTION* GetSelection(void)
{
	return &g_Selection;
}

DECKMENU* GetDeckmenu(void)
{
	return &deckmenu;
}