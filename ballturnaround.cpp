//スキル_エネミー追跡処理 [ballturnaround.cpp]
#include "ballturnaround.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
//エネミー.h
#include "firewall.h"
#include "ball.h"
#include "player.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----マクロ定義

//-----プロトタイプ宣言
BALLTURNAROUND ballturnaround;

//-----グローバル変数
float DeclBulletMove = 0.01f;	//追跡時の速さ調整

//-----初期化処理
HRESULT InitBallTurnAround(void)
{
	ballturnaround.use = 0;

	ballturnaround.b_x = 0.0f;
	ballturnaround.b_y = 0.0f;
	ballturnaround.f_x = 0.0f;
	ballturnaround.f_y = 0.0f;
	ballturnaround.a = 0.0f;
	ballturnaround.n = 0;
	ballturnaround.n_flag = false;
	ballturnaround.n_flag_2 = false;

	ballturnaround.usegauge = 30;

	ballturnaround.bugincrease = false;
	ballturnaround.bugdrawnum = 0;

	return S_OK;
}

//-----追跡処理
void _BallTurnAround(void)
{
	//FIREWALL* firewall = GetFireWall();
	BALL* ball = GetBall();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	RANDOM* random = GetRandom();

	//-----ボールが敵へ向かっていく
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 2 && random[i].active == true && ballturnaround.use == 0)
		{
			ballturnaround.use = 1;
			ballturnaround.b_x = 0.0f;
			ballturnaround.b_y = 0.0f;
			ballturnaround.f_x = 0.0f;
			ballturnaround.f_y = 0.0f;
			ballturnaround.a = 0.0f;
			ballturnaround.n = 0;
			ballturnaround.n_flag = false;
			ballturnaround.n_flag_2 = false;

			random[i].active = false;

			//if (ball->enemyhitflag == true)
			//{
			//	float X = firewall->pos.x - ball->pos.x;
			//	float Y = firewall->pos.y - ball->pos.y;

			//	ball->rad = atan2(Y, X);

			//	ball->move.x += ball->pos.x * cos(ball->rad) * DeclBulletMove;
			//	ball->move.y += ball->pos.y * sin(ball->rad) * DeclBulletMove;

			//	ball->plyer_oldposY = SCREEN_HEIGHT;
			//}
			//if (ball->enemyhitflag == false)
			//	ballturnaround.use = true;

			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && ballturnaround.bugincrease == false)
				{
					for (int j = i; ballturnaround.bugdrawnum < 6; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						ballturnaround.bugdrawnum = ballturnaround.bugdrawnum + 1;
					}
					ballturnaround.bugincrease = true;
				}
			}
		}
	}
}

BALLTURNAROUND* GetBallTurnAround(void)
{
	return &ballturnaround;
}

void SetBallTurnAround(void)
{
	FIREWALL* fw = GetFireWall();
	PLAYER* pl = GetPlayer();
	BALL* ball = GetBall();

	ballturnaround.n_flag = false;
	ballturnaround.n = 0;

	ballturnaround.b_x = pl->pos.x + pl->size.x / 2;
	ballturnaround.b_y = pl->pos.y + pl->size.y / 2;
	ballturnaround.f_x = fw->pos.x + fw->size.x / 2;
	ballturnaround.f_y = fw->pos.y + fw->size.y / 2;
	if (ballturnaround.b_y - ballturnaround.f_y < 0)
	{
		ballturnaround.n_flag_2 = true;
		ballturnaround.f_y -= 100.0f + fw->size.y / 2;
	}
	else
	{
		ballturnaround.f_y += 100.0f + fw->size.y / 2;
	}
	ballturnaround.a = ballturnaround.f_x - ballturnaround.b_x; // x
	ballturnaround.a *= ballturnaround.a; // x2乗 (マイナスは打ち消せる)
	float n = ballturnaround.b_y - ballturnaround.f_y;
	if (n < 0)
	{
		//プレイヤーが上
		n *= -1;
	}
	else
	{
		ballturnaround.n_flag = true;
	}

	ballturnaround.a = n / ballturnaround.a; // y / x2乗 = a
}

void SetBallTurnAround_2(void)
{
	FIREWALL* fw = GetFireWall();

	ballturnaround.b_x = ballturnaround.f_x + 250.0f;
	if (ballturnaround.n_flag_2)
	{
		ballturnaround.b_y = ballturnaround.f_y + 50.0f;
	}
	else
	{
		ballturnaround.b_y = ballturnaround.f_y - 50.0f;
	}

	ballturnaround.n_flag = false;
	ballturnaround.n = 0;

	ballturnaround.a = ballturnaround.f_x - ballturnaround.b_x; // x
	ballturnaround.a *= ballturnaround.a; // x2乗 (マイナスは打ち消せる)
	float n = ballturnaround.b_y - ballturnaround.f_y;
	if (n < 0)
	{
		//プレイヤーが上
		n *= -1;
	}
	else
	{
		ballturnaround.n_flag = true;
	}

	ballturnaround.a = n / ballturnaround.a; // y / x2乗 = a
}

void SetBallTurnAround_3(void)
{
	FIREWALL* fw = GetFireWall();

	ballturnaround.n_flag = false;
	ballturnaround.n = 0;

	ballturnaround.f_x = fw->pos.x + fw->size.x / 2;
	ballturnaround.f_y = fw->pos.y + fw->size.y / 2;

	ballturnaround.a = ballturnaround.f_x - ballturnaround.b_x; // x
	ballturnaround.a *= ballturnaround.a; // x2乗 (マイナスは打ち消せる)
	float n = ballturnaround.b_y - ballturnaround.f_y;
	if (n < 0)
	{
		//プレイヤーが上
		n *= -1;
	}
	else
	{
		ballturnaround.n_flag = true;
	}

	ballturnaround.a = n / ballturnaround.a; // y / x2乗 = a
}
