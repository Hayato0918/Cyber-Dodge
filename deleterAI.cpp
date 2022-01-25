//デリーターAI処理 [deleterAI.cpp]
#include "slimeAI.h"
//システム.h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "deleter.h"
#include "catch.h"
#include "ball.h"
#include "player.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
float deleter_throwtime;
float deleter_x, deleter_y;

//-----敵行動パターン
void DeleterAI()
{
	DELETER* deleter = GetDeleter();
	BALL* ball = GetBall();
	CATCH* Catch = GetCatch();
	PLAYER* player = GetPlayer();


	//-----ボールを持っていないとき
		//-----ボールの方を向く
	if (ball->enemyhaveflag == false)
	{
		deleter->walktextureflag = false;
		if (ball->pos.x > deleter->pos.x + SCREEN_WIDTH * 0.03125f)
			deleter->rotate = 3;
		if (ball->pos.x < deleter->pos.x + SCREEN_WIDTH * 0.03125f)
			deleter->rotate = 2;
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
	deleter_x = (ball->pos.x - deleter->pos.x - deleter->size.x * 0.5f - ball->size.x) * 0.01f;
	deleter_y = (ball->pos.y - deleter->pos.y - deleter->size.y * 0.5f + ball->size.y) * 0.01f;

	//-----ボールが敵陣の地面にある場合、ボールの場所まで行く
	if (ball->enemyhaveflag == false && ball->pos.x > SCREEN_WIDTH * 0.5f && ball->enemyhitflag == false)
	{
		deleter->walktextureflag = true;
		deleter->pos.x += deleter_x;
		deleter->pos.y += deleter_y;
	}

	//-----落ちているボールまでたどり着いたら、キャッチする
	if (ball->enemyhitflag == false)
	{
		if (deleter->pos.x + deleter->size.x > ball->pos.x && deleter->pos.x < ball->pos.x + ball->size.x)
		{
			if (deleter->pos.y < ball->pos.y + ball->size.y && deleter->pos.y + deleter->size.y > ball->pos.y)
			{
				deleter->walktextureflag = false;
				M_Catch();
				if (ball->enemyhaveflag == true && deleter->catchtextureflag_2 == false)
				{
					deleter->catchtextureflag = true;
				}
			}
		}
	}

	//-----ボールを持っているとき
		//-----プレイヤーの方向を向く
	if (ball->enemyhaveflag == true)
	{
		deleter->walktextureflag = false;
		if (player->pos.x > deleter->pos.x)
			deleter->rotate = 3;
		if (player->pos.x < deleter->pos.x)
			deleter->rotate = 2;
	}

	//-----投げるまでの間、プレイヤーのy座標を目指して移動する
	if (ball->enemyhaveflag == true && deleter_throwtime < 60)
	{
		//-----yをプレイヤーとエネミーのy座標の差に変更
		deleter_y = (player->pos.y - deleter->pos.y) * 0.01f;
		deleter->pos.y += deleter_y;
		deleter->walktextureflag = true;
	}

	//-----ボールを1秒持ったら投げる
	if (ball->enemyhaveflag == true)
		deleter_throwtime = deleter_throwtime + 1.0f;
	if (deleter_throwtime > 60)
	{
		deleter->walktextureflag = false;
		deleter->throwtextureflag = true;
		E_Throw();
		deleter_throwtime = 0.0f;
	}
}