//敵AI処理 [enemyAI.cpp]
#include "enemyAI.h"
#include "texture.h"
#include "sprite.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "enemy.h"
#include "catch.h"
#include "ball.h"
#include "player.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
float throwtime;
float x, y;
int num;

//-----敵行動パターン
void enemyAI()
{
	ENEMY* enemy = GetEnemy();
	BALL* ball = GetBall();
	CATCH* Catch = GetCatch();
	PLAYER* player = GetPlayer();


	//-----ボールを持っていないとき
		//-----ボールの方を向く
	if (ball->enemyhaveflag == false)
	{
		if (ball->pos.x > enemy->pos.x)
			enemy->rotate = 3;
		if (ball->pos.x < enemy->pos.x)
			enemy->rotate = 2;
	}

		//-----ボールがプレイヤーの陣地にある場合、上下左右に動く
	if (ball->enemyhaveflag== false && ball->pos.x < SCREEN_WIDTH * 0.5)
	{
		if (player->pos.x > SCREEN_WIDTH * 0.25)
			enemy->pos.x += 1;
		if (player->pos.x < SCREEN_WIDTH * 0.25)
			enemy->pos.x -= 1;
		if (player->pos.y + player->size.y > SCREEN_HEIGHT * 0.7)
			enemy->pos.y += 1;
		if (player->pos.y + player->size.y < SCREEN_HEIGHT * 0.7)
			enemy->pos.y -= 1;
	}


	x = (ball->pos.x - enemy->pos.x + enemy->size.x * 0.5) * 0.01;
	y = (ball->pos.y - enemy->pos.y - enemy->size.y * 0.5) * 0.01;

		//-----ボールが敵陣の地面にある場合、ボールの場所まで行く
	if (ball->enemyhaveflag == false && ball->pos.x > SCREEN_WIDTH * 0.5 && ball->enemyhitflag == false)
	{
		enemy->pos.x += x;
		enemy->pos.y += y;
	}

		//-----落ちているボールまでたどり着いたら、キャッチする
	if (ball->enemyhitflag == false)
	{
		if (enemy->pos.x + enemy->size.x > ball->pos.x && enemy->pos.x < ball->pos.x + ball->size.x)
		{
			if (enemy->pos.y < ball->pos.y + ball->size.y && enemy->pos.y + enemy->size.y > ball->pos.y)
			{
				M_Catch();
			}
		}
	}




	//-----ボールを持っているとき
		//-----プレイヤーの方向を向く
	if (ball->enemyhaveflag == true)
	{
		if (player->pos.x > enemy->pos.x)
			enemy->rotate = 3;
		if (player->pos.x < enemy->pos.x)
			enemy->rotate = 2;
	}

		//-----投げるまでの間、プレイヤーのy座標を目指して移動する
	if (ball->enemyhaveflag == true && throwtime < 60)
	{
		enemy->pos.y += y * 3;
	}

		//-----ボールを2秒持ったら投げる
	if (ball->enemyhaveflag == true)
		throwtime = throwtime + 1.0f;
	if (throwtime > 60)
	{
		E_Throw();
		throwtime = 0.0f;
	}
}