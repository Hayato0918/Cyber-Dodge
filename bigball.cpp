//スキル_ボール巨大化処理 [BigBall.cpp]
#include "bigball.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "ball.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----マクロ定義
#define bigballtime 180		//3s間

//-----プロトタイプ宣言
BIGBALL bigball;

//-----グローバル変数

//-----初期化処理
HRESULT InitBigBall(void)
{
	bigball.use = false;
	bigball.timeflag = false;
	bigball.time = 0.0f;
	bigball.bugincrease = false;
	bigball.bugdrawnum = 0;

	return S_OK;
}

//-----ボール巨大化処理
void _BigBall(void)
{
	BALL* ball = GetBall();
	RANDOM* random = GetRandom();
	SKILL* skill = GetSkill();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();

	//ランダムで選ばれたら、3s間ボールのサイズが大きくなる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 5 && random[i].active == true && bigball.use == false)
		{
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && bigball.bugincrease == false)
				{
					for (int j = i; bigball.bugdrawnum < 5; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						bigball.bugdrawnum = bigball.bugdrawnum + 1;
					}
					bigball.bugincrease = true;
				}
			}
			ball->size = D3DXVECTOR2(ball->size.x * 2, ball->size.y * 2);
			bigball.timeflag = true;
			bigball.use = true;
		}
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && bigball.use == true)
		{
			if (bigball.timeflag == true)
				ball->size = D3DXVECTOR2(ball->size.x * 0.5f, ball->size.y * 0.5f);

			bigball.timeflag = false;
			bigball.bugincrease = false;
			bigball.bugdrawnum = 0;
			bigball.time = 0.0f;
			bigball.use = false;
		}

	}
	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && bigball.use == true)
		{
			if (bigball.timeflag == true)
				ball->size = D3DXVECTOR2(ball->size.x * 0.5f, ball->size.y * 0.5f);

			bigball.timeflag = false;
			bigball.bugincrease = false;
			bigball.bugdrawnum = 0;
			bigball.time = 0.0f;
			bigball.use = false;
		}
	}

	//スキル使用3s後にもとの大きさに戻る
	if (bigball.timeflag == true)
		bigball.time = bigball.time + 1.0f;
	if (bigball.time > bigballtime)
	{
		bigball.timeflag = false;
		ball->size = D3DXVECTOR2(ball->size.x * 0.5f, ball->size.y * 0.5f);
		bigball.bugincrease = false;
		bigball.bugdrawnum = 0;
		bigball.time = 0.0f;
	}


}
