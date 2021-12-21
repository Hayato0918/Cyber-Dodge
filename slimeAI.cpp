//スライムAI処理 [slimeAI.cpp]
#include "slimeAI.h"
//システム.h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "slime.h"
#include "catch.h"
#include "ball.h"
#include "player.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
float slime_throwtime;
float slime_x, slime_y;

//-----敵行動パターン
void SlimeAI()
{
	SLIME* slime = GetSlime();
	BALL* ball = GetBall();
	CATCH* Catch = GetCatch();
	PLAYER* player = GetPlayer();


	//-----ボールを持っていないとき
		//-----ボールの方を向く
	if (ball->enemyhaveflag == false)
	{
		if (ball->pos.x > slime->pos.x + 50.0f)
			slime->rotate = 3;
		if (ball->pos.x < slime->pos.x + 50.0f)
			slime->rotate = 2;
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
	slime_x = (ball->pos.x - slime->pos.x - slime->size.x * 0.5f - ball->size.x) * 0.01f;
	slime_y = (ball->pos.y - slime->pos.y - slime->size.y * 0.5f + ball->size.y) * 0.01f;

	//-----ボールが敵陣の地面にある場合、ボールの場所まで行く
	if (ball->enemyhaveflag == false && ball->pos.x > SCREEN_WIDTH * 0.5f && ball->enemyhitflag == false)
	{
		slime->pos.x += slime_x;
		slime->pos.y += slime_y;
	}

	//-----落ちているボールまでたどり着いたら、キャッチする
	if (ball->enemyhitflag == false)
	{
		if (slime->pos.x + slime->size.x > ball->pos.x && slime->pos.x < ball->pos.x + ball->size.x)
		{
			if (slime->pos.y < ball->pos.y + ball->size.y && slime->pos.y + slime->size.y > ball->pos.y)
			{
				M_Catch();
			}
		}
	}

	//-----ボールを持っているとき
		//-----プレイヤーの方向を向く
	if (ball->enemyhaveflag == true)
	{
		if (player->pos.x > slime->pos.x)
			slime->rotate = 3;
		if (player->pos.x < slime->pos.x)
			slime->rotate = 2;
	}

	//-----投げるまでの間、プレイヤーのy座標を目指して移動する
	if (ball->enemyhaveflag == true && slime_throwtime < 60)
	{
		//-----yをプレイヤーとエネミーのy座標の差に変更
		slime_y = (player->pos.y - slime->pos.y) * 0.01f;

		slime->pos.y += slime_y;
	}

	//-----ボールを1秒持ったら投げる
	if (ball->enemyhaveflag == true)
		slime_throwtime = slime_throwtime + 1.0f;
	if (slime_throwtime > 60)
	{
		E_Throw();
		slime_throwtime = 0.0f;
	}
}