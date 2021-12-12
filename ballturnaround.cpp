//スキル_エネミー追跡処理 [ballturnaround.cpp]
#include "ballturnaround.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

#include "enemy.h"
#include "ball.h"
#include "bug.h"

#include "skillrandom.h"

//-----マクロ定義

//-----プロトタイプ宣言
BALLTURNAROUND ballturnaround;

//-----グローバル変数
float DeclBulletMove = 0.01f;	//追跡時の速さ調整

//-----初期化処理
HRESULT InitBallTurnAround(void)
{
	ballturnaround.use = false;
	ballturnaround.usegauge = 30;

	return S_OK;
}

//-----追跡処理
void _BallTurnAround(void)
{
	ENEMY* enemy = GetEnemy();
	BALL* ball = GetBall();
	BUG* bug = GetBug();
	RANDOM* random = GetRandom();

	//-----Cキーを押したら、ボールが敵へ向かっていく
	for (int i = 0; i < 36; i++)
	{
		if (random[i].code == 2 && random[i].active == true && ballturnaround.use == false && ball->playerthrowflag == true)
		{
			if (ball->enemyhitflag == true)
			{
				float X = enemy->pos.x - ball->pos.x;
				float Y = enemy->pos.y - ball->pos.y;

				ball->rad = atan2(Y, X);

				ball->move.x += ball->pos.x * cos(ball->rad) * DeclBulletMove;
				ball->move.y += ball->pos.y * sin(ball->rad) * DeclBulletMove;

				ball->plyer_oldposY = SCREEN_HEIGHT;
			}
			if (ball->enemyhitflag == false)
				ballturnaround.use = true;

			//-----バグゲージの上昇
			bug->gaugesize.x = bug->gaugesize.x + ballturnaround.usegauge * bug->gaugeonce;
			ballturnaround.use = true;
		}
	}
}