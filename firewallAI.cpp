//敵AI処理 [enemyAI.cpp]
#include "firewallAI.h"
//システム.h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "firewall.h"
#include "catch.h"
#include "ball.h"
#include "player.h"
#include "catchjamming.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
float throwtime;
float x, y;
int num;

//-----敵行動パターン
void FireWallAI()
{
	FIREWALL* firewall = GetFireWall();
	BALL* ball = GetBall();
	CATCH* Catch = GetCatch();
	PLAYER* player = GetPlayer();


	//-----ボールを持っていないとき
		//-----ボールの方を向く
	if (ball->enemyhaveflag == false)
	{
		if (ball->pos.x > firewall->pos.x + SCREEN_WIDTH * 0.03125f)
			firewall->rotate = 3;
		if (ball->pos.x < firewall->pos.x + SCREEN_WIDTH * 0.03125f)
			firewall->rotate = 2;
	}

	//-----ボールがプレイヤーの陣地にある場合、上下左右に動く
	//if (ball->enemyhaveflag== false && ball->pos.x < SCREEN_WIDTH * 0.5)
	//{
	//	if (player->pos.x > SCREEN_WIDTH * 0.25)
	//		enemy->pos.x += 3;
	//	if (player->pos.x < SCREEN_WIDTH * 0.25)
	//		enemy->pos.x -= 3;
	//	if (player->pos.y + player->size.y > SCREEN_HEIGHT * 0.6)
	//		enemy->pos.y += 3;
	//	if (player->pos.y + player->size.y < SCREEN_HEIGHT * 0.6)
	//		enemy->pos.y -= 3;
	//}

	//-----ボールとエネミーの位置を計算し、エネミーがボールを追うようにする
	x = (ball->pos.x - firewall->pos.x - firewall->size.x * 0.5f - ball->size.x) * 0.01f;
	y = (ball->pos.y - firewall->pos.y - firewall->size.y * 0.5f + ball->size.y) * 0.01f;

		//-----ボールが敵陣の地面にある場合、ボールの場所まで行く
	if (ball->enemyhaveflag == false && ball->pos.x > SCREEN_WIDTH * 0.5f && ball->enemyhitflag == false)
	{
		firewall->pos.x += x;
		firewall->pos.y += y;
	}

		//-----落ちているボールまでたどり着いたら、キャッチする
	if (ball->enemyhitflag == false)
	{
		if (firewall->pos.x + firewall->size.x + Catch->enemysize.x > ball->pos.x && firewall->pos.x - Catch->enemysize.x < ball->pos.x + ball->size.x)
		{
			if (firewall->pos.y < ball->pos.y + ball->size.y && firewall->pos.y + firewall->size.y > ball->pos.y)
			{
				M_Catch();
				
			}
		}
	}
	//-----ボールが地面に落ちた状態で自陣にあり、ファイアーウォールの体に接触していたら、キャッチする
	if (ball->enemyhaveflag == false && ball->fallflag == true && ball->pos.x > SCREEN_WIDTH * 0.5f)
	{
		if (firewall->pos.x + firewall->size.x > ball->pos.x && firewall->pos.x < ball->pos.x + ball->size.x)
		{
			if (firewall->pos.y < ball->pos.y + ball->size.y && firewall->pos.y + firewall->size.y > ball->pos.y)
			{
				Catch->enemyintervaltime = 0.0f;
				ball->throwflag = false;
				ball->enemyhaveflag = true;
				ball->move = D3DXVECTOR2(ball->startmove.x, ball->startmove.y);
				firewall->catchtextureflag = true;
			}
		}
	}

	//-----ボールを持っているとき
		//-----プレイヤーの方向を向く
	if (ball->enemyhaveflag == true)
	{
		if (player->pos.x > firewall->pos.x)
			firewall->rotate = 3;
		if (player->pos.x < firewall->pos.x)
			firewall->rotate = 2;
	}

		//-----投げるまでの間、プレイヤーのy座標を目指して移動する
	if (ball->enemyhaveflag == true && throwtime < 60)
	{
		//-----yをプレイヤーとエネミーのy座標の差に変更
		y = (player->pos.y - firewall->pos.y) * 0.01f;

		firewall->pos.y += y;
	}

		//-----ボールを1秒持ったら投げる
	if (ball->enemyhaveflag == true)
		throwtime = throwtime + 1.0f;
	if (throwtime > 60)
	{
		E_Throw();
		throwtime = 0.0f;
	}
}