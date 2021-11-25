//スキル_スピードアップ処理 [ballspeedup.cpp]
#include "ballspeedup.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "ball.h"
#include "catch.h"
#include "bug.h"

#include "skillrandom.h"

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
	ballspeedup.usegauge = 100;

	return S_OK;
}

//-----巨大化処理
void _BallSpeedUp(void)
{
	BALL* ball = GetBall();
	BUG* bug = GetBug();
	RANDOM* random = GetRandom();

	//------プレイヤーがボールを持っている間、0キーを押したら、ボールの速さが+5される
	if (random->code == 1 && random->active == true && ballspeedup.use == false && ball->playerhaveflag == true)
	{
		//------速さをもとに戻すときに使う
		ballspeedup.beforemove = ball->move.x;

		//今向いてる方向に応じて加速するベクトルを変える
		if (ball->move.x > 0)
			ball->move.x = ball->move.x + 5;
		if (ball->move.x < 0)
			ball->move.x = ball->move.x - 5;

		//-----バグゲージの上昇
		bug->gaugesize.x = bug->gaugesize.x + ballspeedup.usegauge * bug->gaugeonce;
		ballspeedup.use = true;
	}
}