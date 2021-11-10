//キャッチ処理 [catch.cpp]
#include "catch.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "ball.h"

//-----マクロ定義
#define catchtime 30		//キャッチ判定を出す時間
#define catchinterval 60	//キャッチのインターバル時間

//-----プロトタイプ宣言
CATCH Catch;

//-----グローバル変数

//-----初期化処理
HRESULT InitCatch(void)
{
	Catch.pos = D3DXVECTOR2(0.0f, 0.0f);
	Catch.size = D3DXVECTOR2(60.0, 60.0);
	Catch.texture = LoadTexture("data/TEXTURE/catch.png");
	Catch.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
	Catch.flag = false;
	Catch.intervalflag = false;
	Catch.intervaltime = 0.0f;
	Catch.coltime = 0.0f;
	Catch.colflag = false;

	return S_OK;
}

//-----終了処理
void UninitCatch(void)
{

}

//-----更新処理
void UpdateCatch(void)
{
	PLAYER* player = GetPlayer();
	BALL* ball = GetBall();

	//-----プレイヤーの向きに応じてキャッチの方向を決める
	if(player->rotate == 0)		//上
		Catch.pos = D3DXVECTOR2(player->pos.x + player->size.x * 0.5, player->pos.y - ball->size.y * 0.5);
	if (player->rotate == 1)		//下
		Catch.pos = D3DXVECTOR2(player->pos.x + player->size.x * 0.5, player->pos.y + player->size.y + ball->size.y * 0.5);
	if (player->rotate == 2)	//左
		Catch.pos = D3DXVECTOR2(player->pos.x - Catch.size.x * 0.5, player->pos.y + player->size.y * 0.5);
	if(player->rotate == 3)		//右
		Catch.pos = D3DXVECTOR2(player->pos.x + player->size.x * 1.5, player->pos.y + player->size.y * 0.5);
}

//-----描画処理
void DrawCatch(void)
{
	if(Catch.flag == true)
	DrawSpriteColor(Catch.texture, Catch.pos.x, Catch.pos.y, Catch.size.x, Catch.size.y, 0.0f, 0.0f, 1.0f, 1.0f, Catch.color);
}

//---キャッチ処理
void _Catch(void)
{
	BALL* ball = GetBall();

	//-----Jキーでキャッチ
	if (GetKeyboardTrigger(DIK_J) && Catch.intervalflag == false && ball->playerhaveflag == false)	//
	{
		Catch.flag = true;
		Catch.intervalflag = true;
	}
	//-----インターバル(1s)
	if (Catch.intervalflag == true)
		Catch.intervaltime = Catch.intervaltime + 1.0f;
	if (Catch.intervaltime > catchinterval)
	{
		Catch.intervalflag = false;
		Catch.intervaltime = 0.0f;
	}
	//-----キャッチの判定時間(0.5s)
	if (Catch.flag == true)
		Catch.coltime = Catch.coltime + 1.0f;
	if (Catch.coltime > catchtime)
	{
		Catch.flag = false;
		Catch.coltime = 0.0f;
	}
	//-----キャッチモーション中にボールがキャッチ判定内に入ったら
	if (Catch.flag == true)
	{
		if (Catch.pos.x + Catch.size.x > ball->pos.x && Catch.pos.x < ball->pos.x + ball->size.x)
		{
			if (Catch.pos.y + Catch.size.y > ball->pos.y && Catch.pos.y < ball->pos.y + ball->size.y)
			{
				ball->throwflag = false;
				ball->playerhaveflag = true;
				ball->move = D3DXVECTOR2(15.0f, -3.5f);
			}
		}
	}
}