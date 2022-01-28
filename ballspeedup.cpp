//スキル_ボールスピードアップ処理 [ballspeedup.cpp]	//修正済み
#include "ballspeedup.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "ball.h"
#include "catch.h"
#include "bugincrease.h"

#include "skillrandom.h"
#include "enemybreak.h"

//-----マクロ定義

//-----プロトタイプ宣言
BALLSPEEDUP ballspeedup;

//-----グローバル変数

//-----初期化処理
HRESULT InitBallSpeedUp(void)
{
	ballspeedup.move = 5.0f;
	ballspeedup.beforemove = 0.0f;
	ballspeedup.use = false;
	ballspeedup.usegauge = 20;
	ballspeedup.timeflag = false;
	ballspeedup.useflag = false;

	ballspeedup.bugincrease = false;
	ballspeedup.bugdrawnum = 0;

	return S_OK;
}

//-----ボールスピードアップ処理
void _BallSpeedUp(void)
{
	BALL* ball = GetBall();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	BUGGAUGE* buggauge = GetBugGauge();
	ENEMYBREAK* enemybreak = GetEnemyBreak();

	//------ボールの速さを1.5倍する
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 1 && random[i].active == true && ballspeedup.use == false)
		{
			//------速さをもとに戻すときに使う
			ballspeedup.beforemove = ball->move.x;

			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && ballspeedup.bugincrease == false)
				{
					for (int j = i; ballspeedup.bugdrawnum < 4; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						ballspeedup.bugdrawnum = ballspeedup.bugdrawnum + 1;
					}
					ballspeedup.bugincrease = true;
				}
			}

			//-----効果の適用させるよ
			ballspeedup.timeflag = true;

			//-----スキルを使用したよ
			ballspeedup.use = true;
		}
	}

	if (ballspeedup.timeflag == true)
	{
		//ボールの加速処理
		if (ballspeedup.useflag == false)
		{
			ball->move.x = ball->move.x * 1.5f;
			ballspeedup.useflag = true;
		}

		//エネミーヒットフラグがfalseになったら適用を終了する
		if (ball->enemyhitflag == false)
		{
			ball->move.x = ballspeedup.beforemove;
			ballspeedup.timeflag = false;
		}
	}

	if (enemybreak->drawflag == true && ballspeedup.use == true)
	{
		ball->move.x = ballspeedup.beforemove;
		ballspeedup.timeflag = false;
	}
}