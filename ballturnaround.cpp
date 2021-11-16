//スキル_エネミー追跡処理 [ballturnaround.cpp]
#include "ballturnaround.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

#include "enemy.h"
#include "ball.h"

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

	//-----Cキーを押したら、ボールが敵へ向かっていく
	if (GetKeyboardTrigger(DIK_C) && ballturnaround.use == false)
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
	}
}