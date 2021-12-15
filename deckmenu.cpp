//デッキメニュー処理 [deckmenu.cpp]
#include "deckmenu.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include "skillrandom.h"

//-----マクロ定義

#define CARD_SPACE_WIDTH 300.0f
#define CARD_SPACE_HIGHT 300.0f
#define ynum 9
#define xnum 4

//-----プロトタイプ宣言
DECKMENUCARD deckmenu_card[ynum][xnum];
DECKMENU deckmenu;
SELECTION g_Selection;
NUMBER g_number;

//-----グローバル変数

//-----初期化処理
HRESULT InitDeckMenu(void)
{
	RANDOM* random = GetRandom();

	for (int y = 0; y < ynum; y++)
	{
		for (int x = 0; x < xnum; x++)
		{
			deckmenu_card[y][x].pos = D3DXVECTOR2(120.0f + CARD_SPACE_WIDTH * x, 120.0f + CARD_SPACE_HIGHT * y + CARD_SPACE_HIGHT * y * 0.3f);
			deckmenu_card[y][x].size = D3DXVECTOR2(200.0f, 300.0f);
			for (int i = 0; i < 14; i++)
			{
				//if (random[i].code == 1)
				//	deckmenu_card[y][x].texture = LoadTexture("data/TEXTURE/skill/speedup.png");
				//if (random[i].code == 2)
				//	deckmenu_card[y][x].texture = LoadTexture("data/TEXTURE/skill/turnaround.png");
				//if (random[i].code == 3)
				//	deckmenu_card[y][x].texture = LoadTexture("data/TEXTURE/skill/barrier.png");
				//if (random[i].code == 4)
				//	deckmenu_card[y][x].texture = LoadTexture("data/TEXTURE/skill/baseball.png");
				//if (random[i].code == 5)
				//	deckmenu_card[y][x].texture = LoadTexture("data/TEXTURE/skill/bigball.png");
			}
		}
	}

	deckmenu.pos = D3DXVECTOR2(0.0f, 0.0f);
	deckmenu.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	deckmenu.texture = LoadTexture("data/TEXTURE/deckmenu/bg.png");
	deckmenu.use = false;

	g_Selection.pos = D3DXVECTOR2(deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.x, deckmenu_card[g_Selection.UDcount][g_Selection.LRcount].pos.y);
	g_Selection.size = D3DXVECTOR2(200.0f, 300.0f);
	g_Selection.texture = LoadTexture("data/TEXTURE/deckmenu/frame.png");
	g_Selection.use = true;
	g_Selection.LRcount = 0;
	g_Selection.UDcount = 0;

	g_number.pos = D3DXVECTOR2(1320.0f, 140.0f);
	g_number.size = D3DXVECTOR2(80.0f, 80.0f);
	g_number.texture = LoadTexture("data/TEXTURE/deckmenu/number.jpg");
	g_number.u = 0.0f;
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
	if (g_Selection.UDcount % 2 == 0)
	{
		g_number.u = 0.2 * g_Selection.UDcount * 0.5f;
	}

	if (g_Selection.UDcount % 2 == 1)
	{
		g_number.u = 0.2f * (g_Selection.UDcount - 1) * 0.5f;
	}

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
	if (GetKeyboardTrigger(DIK_S) && g_Selection.UDcount < ynum - 2 && g_Selection.use == true)
	{
		g_Selection.UDcount = g_Selection.UDcount + 1;
		//2段を区切りに、カードの位置を移動
		if (g_Selection.UDcount == 2 || g_Selection.UDcount == 4 || g_Selection.UDcount == 6)
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
		if (g_Selection.UDcount == 1 || g_Selection.UDcount == 3 || g_Selection.UDcount == 5)
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

	//Speceキーを押したら、立ち去るコマンドまで飛ぶ
	if (GetKeyboardTrigger(DIK_SPACE))
	{
		deckmenu.use = true;
		g_Selection.use = false;
		g_Selection.pos = D3DXVECTOR2(SCREEN_WIDTH - 285.0f, 545.0f);
		g_Selection.size = D3DXVECTOR2(185.0f, 315.0f);
		g_Selection.UDcount = 0;
		g_Selection.LRcount = 0;
	}

	//「立ち去る」コマンドの場所でEnterキーを押したらMAPに戻る
	if (GetKeyboardTrigger(DIK_RETURN) && deckmenu.use == true)
	{
		SceneTransition(SCENE_MAP);
		deckmenu.use = false;
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
			DrawSpriteLeftTop(deckmenu_card[y][x].texture, deckmenu_card[y][x].pos.x, deckmenu_card[y][x].pos.y,
								deckmenu_card[y][x].size.x, deckmenu_card[x][y].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
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