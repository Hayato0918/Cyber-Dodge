//スキル_ベースボール処理 [baseball.cpp]
#include "baseball.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "player.h"
#include "ball.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----マクロ定義
#define swingtime	1200					//バットの判定時間
#define PI 3.1415926535897932f				//円周率


//-----グローバル変数
BASEBALL baseball;

HRESULT InitBaseball(void)
{
	baseball.pos = D3DXVECTOR2(0.0f, 0.0f);
	baseball.size = D3DXVECTOR2(20.0f, 120.0f);
	baseball.use = false;
	baseball.timeflag = false;
	baseball.time = 0.0f;
	baseball.usegauge = 20;

	baseball.bugincrease = false;
	baseball.bugdrawnum = 0;

	baseball.texture = LoadTexture("data/TEXTURE/bat.png");

	return S_OK;
}

void _Baseball(void)
{
	//5キーが押されたら処理を開始。
	//玉を持っていない間バットを一定時間表示、その間玉を一定の速度で打ち出すような処理を行います。

	BALL* ball = GetBall();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();

	//スキルが使えるかの判断
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 4 && random[i].active == true && baseball.use == false && ball->playerhaveflag == false)
		{
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && baseball.bugincrease == false)
				{
					for (int j = i; baseball.bugdrawnum < 4; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						baseball.bugdrawnum = baseball.bugdrawnum + 1;
					}
					baseball.bugincrease = true;
				}
			}
			baseball.timeflag = true;
			baseball.use = true;
		}
	}

	PLAYER* player = GetPlayer();

	//バットを振っている最中の処理
	if (baseball.timeflag == true)
	{
		if (player->rotate == 3) // 右向き
		{
			baseball.pos = D3DXVECTOR2(player->pos.x + player->size.x, player->pos.y);// バットの描画位置
		}
		if (player->rotate == 2) // 左向き
		{
			baseball.pos = D3DXVECTOR2(player->pos.x - baseball.size.x, player->pos.y);// バットの描画位置
		}

		//当たり判定処理
		if (baseball.pos.x + baseball.size.x > ball->pos.x && baseball.pos.x < ball->pos.x + ball->size.x)
		{
			if (baseball.pos.y + baseball.size.y > ball->pos.y && baseball.pos.y < ball->pos.y + ball->size.y)
			{
				float n = (rand() % 90 - 45) * 0.01f;//方向をランダムで選出

				if (player->rotate == 3) // 右向き
				{
					AddBallMove(10.0f, PI * (n + 1), player->pos.y, player->size.y);//ボールを打ち出している
				}
				if (player->rotate == 2) // 左向き
				{
					AddBallMove(10.0f, PI * n, player->pos.y, player->size.y);
				}
			}
		}

		baseball.time = baseball.time + 1.0f;
	}

	//バットを振り切ったかの判断
	if (baseball.time > swingtime)
	{
		baseball.timeflag = false;
		baseball.time = 0.0f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && baseball.use == true)
		{
			baseball.pos = D3DXVECTOR2(0.0f, 0.0f);
			baseball.size = D3DXVECTOR2(20.0f, 120.0f);
			baseball.use = false;
			baseball.timeflag = false;
			baseball.time = 0.0f;
			baseball.usegauge = 20;

			baseball.bugincrease = false;
			baseball.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && baseball.use == true)
		{
			baseball.pos = D3DXVECTOR2(0.0f, 0.0f);
			baseball.size = D3DXVECTOR2(20.0f, 120.0f);
			baseball.use = false;
			baseball.timeflag = false;
			baseball.time = 0.0f;
			baseball.usegauge = 20;

			baseball.bugincrease = false;
			baseball.bugdrawnum = 0;
		}
	}

}

void DrawBaseball(void)
{
	if (baseball.timeflag == true)
		//描画処理
		DrawSpriteLeftTop(baseball.texture, baseball.pos.x, baseball.pos.y, baseball.size.x, baseball.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}