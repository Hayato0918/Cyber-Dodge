//ゲームオーバースコア処理 [gameover_score.cpp]
#include "gameover_score.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "player.h"

//-----マクロ定義

//-----プロトタイプ宣言
GAMEOVER_SCORENUM gameover_Score[4];
GAMEOVER_SCORE gameover_score;

//-----グローバル変数

//-----初期化処理
HRESULT InitGameOverScore(void)
{
	for (int i = 0; i < 4; i++)
	{
		gameover_Score[i].pos = D3DXVECTOR2(800.f + i * 50.f, 370.f);
		gameover_Score[i].size = D3DXVECTOR2(65.f, 65.f);
		gameover_Score[i].texture = LoadTexture("data/TEXTURE/number.png");
		gameover_Score[i].u = 0.f;
		gameover_Score[i].v = 0.f;
		gameover_Score[i].drawflag = false;
	}

	gameover_score.a = 0;
	gameover_score.b = 0;
	gameover_score.c = 0;
	gameover_score.d = 0;

	PLAYER* player = GetPlayer();
	gameover_score.gold = player->score;

	return S_OK;
}

//-----終了処理
void UninitGameOverScore(void)
{

}

//-----更新処理
void UpdateGameOverScore(void)
{
	gameover_score.a = gameover_score.gold * 0.001f;
	gameover_score.b = (gameover_score.gold - gameover_score.a * 1000) * 0.01f;
	gameover_score.c = (gameover_score.gold - gameover_score.a * 1000 - gameover_score.b * 100) * 0.1f;
	gameover_score.d = gameover_score.gold - gameover_score.a * 1000 - gameover_score.b * 100 - gameover_score.c * 10;

	//goldの1000の位
	if (gameover_score.a < 5)
	{
		gameover_Score[0].u = 0.2f * gameover_score.a;
		gameover_Score[0].v = 0.f;
	}
	if (gameover_score.a >= 5)
	{
		gameover_Score[0].u = 0.2f * gameover_score.a;
		gameover_Score[0].v = 0.5f;
	}
	if (gameover_score.a <= 0)
		gameover_Score[0].drawflag = false;
	if (gameover_score.a > 0)
		gameover_Score[0].drawflag = true;
	//goldの100の位
	if (gameover_score.b < 5)
	{
		gameover_Score[1].u = 0.2f * gameover_score.b;
		gameover_Score[1].v = 0.f;
	}
	if (gameover_score.b >= 5)
	{
		gameover_Score[1].u = 0.2f * gameover_score.b;
		gameover_Score[1].v = 0.5f;
	}
	if (gameover_score.b >= 0)
		gameover_Score[1].drawflag = true;
	if (gameover_score.a <= 0 && gameover_score.b <= 0)
		gameover_Score[1].drawflag = false;
	//goldの10の位
	if (gameover_score.c < 5)
	{
		gameover_Score[2].u = 0.2f * gameover_score.c;
		gameover_Score[2].v = 0.f;
	}
	if (gameover_score.c >= 5)
	{
		gameover_Score[2].u = 0.2f * gameover_score.c;
		gameover_Score[2].v = 0.5f;
	}
	if (gameover_score.c >= 0)
		gameover_Score[2].drawflag = true;
	if (gameover_score.a <= 0 && gameover_score.b <= 0 && gameover_score.c <= 0)
		gameover_Score[2].drawflag = false;
	//goldの1の位
	if (gameover_score.d < 5)
	{
		gameover_Score[3].u = 0.2f * gameover_score.d;
		gameover_Score[3].v = 0.f;
		gameover_Score[3].drawflag = true;
	}
	if (gameover_score.d >= 5)
	{
		gameover_Score[3].u = 0.2f * gameover_score.d;
		gameover_Score[3].v = 0.5f;
		gameover_Score[3].drawflag = true;
	}
}

//-----描画処理
void DrawGameOverScore(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (gameover_Score[i].drawflag == true)
			DrawSpriteLeftTop(gameover_Score[i].texture, gameover_Score[i].pos.x, gameover_Score[i].pos.y, gameover_Score[i].size.x, gameover_Score[i].size.y,
				gameover_Score[i].u, gameover_Score[i].v, 0.2f, 0.5f);
	}
}