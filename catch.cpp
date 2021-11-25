//キャッチ処理 [catch.cpp]
#include "catch.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "enemy.h"
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
	Catch.playerpos = D3DXVECTOR2(0.0f, 0.0f);
	Catch.playerflag = false;
	Catch.playerintervalflag = false;
	Catch.playerintervaltime = 0.0f;
	Catch.playercolflag = false;
	Catch.playercoltime = 0.0f;

	Catch.enemypos = D3DXVECTOR2(0.0f, 0.0f);
	Catch.enemyflag = false;
	Catch.enemyintervalflag = false;
	Catch.enemyintervaltime = 0.0f;
	Catch.enemycolflag = false;
	Catch.enemycoltime = 0.0f;

	Catch.size = D3DXVECTOR2(60.0, 60.0);
	Catch.texture = LoadTexture("data/TEXTURE/catch.png");
	Catch.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);

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
	ENEMY* enemy = GetEnemy();
	BALL* ball = GetBall();

	//-----プレイヤーの向きに応じてキャッチの方向を決める
	if (Catch.playerflag == true)
	{
		if (player->rotate == 0)		//上
			Catch.playerpos = D3DXVECTOR2(player->pos.x + player->size.x * 0.5f, player->pos.y - ball->size.y * 0.5f);
		if (player->rotate == 1)		//下
			Catch.playerpos = D3DXVECTOR2(player->pos.x + player->size.x * 0.5f, player->pos.y + player->size.y + ball->size.y * 0.5f);
		if (player->rotate == 2)	//左
			Catch.playerpos = D3DXVECTOR2(player->pos.x - Catch.size.x * 0.5f, player->pos.y + player->size.y * 0.5f);
		if (player->rotate == 3)		//右
			Catch.playerpos = D3DXVECTOR2(player->pos.x + player->size.x * 1.5f, player->pos.y + player->size.y * 0.5f);
	}

	//-----エネミーの向きに応じてキャッチの方向を決める
	if (Catch.enemyflag == true)
	{
		if (enemy->rotate == 0)		//上
			Catch.enemypos = D3DXVECTOR2(enemy->pos.x + enemy->size.x * 0.5f, enemy->pos.y - ball->size.y * 0.5f);
		if (enemy->rotate == 1)		//下
			Catch.enemypos = D3DXVECTOR2(enemy->pos.x + enemy->size.x * 0.5f, enemy->pos.y + enemy->size.y + ball->size.y * 0.5f);
		if (enemy->rotate == 2)	//左
			Catch.enemypos = D3DXVECTOR2(enemy->pos.x - Catch.size.x * 0.5f, enemy->pos.y + enemy->size.y * 0.5f);
		if (enemy->rotate == 3)		//右
			Catch.enemypos = D3DXVECTOR2(enemy->pos.x + enemy->size.x * 1.5f, enemy->pos.y + enemy->size.y * 0.5f);
	}
}

//-----描画処理
void DrawCatch(void)
{

	if(Catch.playerflag == true)
	DrawSpriteColor(Catch.texture, Catch.playerpos.x, Catch.playerpos.y, Catch.size.x, Catch.size.y, 0.0f, 0.0f, 1.0f, 1.0f, Catch.color);
	if(Catch.enemyflag == true)
		DrawSpriteColor(Catch.texture, Catch.enemypos.x, Catch.enemypos.y, Catch.size.x, Catch.size.y, 0.0f, 0.0f, 1.0f, 1.0f, Catch.color);
}

//-----プレイヤーのキャッチ処理
void P_Catch(void)
{
	BALL* ball = GetBall();

	//-----Jキーでプレイヤーがキャッチ
	if (GetKeyboardTrigger(DIK_J) && Catch.playerintervalflag == false && ball->playerhaveflag == false)
	{
		Catch.playerflag = true;
		Catch.playerintervalflag = true;
	}
	//-----インターバル(1s)
	if (Catch.playerintervalflag == true)
		Catch.playerintervaltime = Catch.playerintervaltime + 1.0f;
	if (Catch.playerintervaltime > catchinterval)
	{
		Catch.playerintervalflag = false;
		Catch.playerintervaltime = 0.0f;
	}
	//-----キャッチの判定時間(0.5s)
	if (Catch.playerflag == true)
		Catch.playercoltime = Catch.playercoltime + 1.0f;
	if (Catch.playercoltime > catchtime)
	{
		Catch.playerflag = false;
		Catch.playercoltime = 0.0f;
	}
	//-----キャッチモーション中にボールがキャッチ判定内に入ったら
	if (Catch.playerflag == true)
	{
		if (Catch.playerpos.x + Catch.size.x > ball->pos.x && Catch.playerpos.x < ball->pos.x + ball->size.x)
		{
			if (Catch.playerpos.y + Catch.size.y > ball->pos.y && Catch.playerpos.y < ball->pos.y + ball->size.y)
			{
				ball->playerhitflag = false;
				ball->playerthrowflag = false;
				ball->throwflag = false;
				ball->playerhaveflag = true;
				ball->move = D3DXVECTOR2(ball->startmove.x, ball->startmove.y);
			}
		}
	}
}

//-----エネミーのキャッチ処理
void M_Catch(void)
{
	BALL* ball = GetBall();

	//-----キャッチ
	if (Catch.enemyintervalflag == false && ball->enemyhaveflag == false)
	{
		Catch.enemyflag = true;
		Catch.enemyintervalflag = true;
	}
	//-----インターバル(1s)
	if (Catch.enemyintervalflag == true)
		Catch.enemyintervaltime = Catch.enemyintervaltime + 1.0f;
	if (Catch.enemyintervaltime > catchinterval)
	{
		Catch.enemyintervalflag = false;
		Catch.enemyintervaltime = 0.0f;
	}
	//-----キャッチの判定時間(0.5s)
	if (Catch.enemyflag == true)
		Catch.enemycoltime = Catch.enemycoltime + 1.0f;
	if (Catch.enemycoltime > catchtime)
	{
		Catch.enemyflag = false;
		Catch.enemycoltime = 0.0f;
	}
	//-----キャッチモーション中にボールがキャッチ判定内に入ったら
	if (Catch.enemyflag == true)
	{
		if (Catch.enemypos.x + Catch.size.x > ball->pos.x && Catch.enemypos.x < ball->pos.x + ball->size.x)
		{
			if (Catch.enemypos.y + Catch.size.y > ball->pos.y && Catch.enemypos.y < ball->pos.y + ball->size.y)
			{
				Catch.enemyintervaltime = 0.0f;
				ball->throwflag = false;
				ball->enemyhaveflag = true;
				ball->move = D3DXVECTOR2(ball->startmove.x, ball->startmove.y);
			}
		}
	}
}

CATCH* GetCatch()
{
	return &Catch;
}