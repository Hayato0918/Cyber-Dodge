//スキル_ビリヤード処理 [billiards.cpp]
#include "billiards.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "ball.h"
#include "bugincrease.h"

#include "skillrandom.h"
#include "enemybreak.h"

//-----マクロ定義
#define swingtime	1200					//キュースティックの判定時間
#define PI 3.1415926535897932f				//円周率

//-----グローバル変数
BILLIARDS billiards;

HRESULT InitBilliards(void)
{
	billiards.pos = D3DXVECTOR2(0.0f, 0.0f);
	billiards.size = D3DXVECTOR2(120.0f, 5.0f);
	billiards.use = false;
	billiards.timeflag = false;
	billiards.time = 0.0f;
	billiards.usegauge = 20;

	billiards.bugincrease = false;
	billiards.bugdrawnum = 0;

	billiards.texture = LoadTexture("data/TEXTURE/cuestick.png");

	return S_OK;
}

void _Billiards(void)
{
	//6キーが押されたら処理を開始。
		//玉を持っていない間キュースティックを一定時間表示、その間玉を一定の速度で打ち出すような処理を行います。

	BALL* ball = GetBall();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();
	ENEMYBREAK* enemybreak = GetEnemyBreak();

	//スキルが使えるかの判断
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 6 && random[i].active == true && billiards.use == false && ball->playerhaveflag == false)
		{
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && billiards.bugincrease == false)
				{
					for (int j = i; billiards.bugdrawnum < 4; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						billiards.bugdrawnum = billiards.bugdrawnum + 1;
					}
					billiards.bugincrease = true;
				}
			}
			billiards.timeflag = true;
			billiards.use = true;
		}
	}

	PLAYER* player = GetPlayer();

	//キュースティックを振っている最中の処理
	if (billiards.timeflag == true)
	{
		if (player->rotate == 3) // 右向き
		{
			billiards.pos = D3DXVECTOR2(player->pos.x + player->size.x, player->pos.y + player->size.y * 0.5f);// キュースティックの描画位置
		}
		if (player->rotate == 2) // 左向き
		{
			billiards.pos = D3DXVECTOR2(player->pos.x - billiards.size.x, player->pos.y + player->size.y * 0.5f);// キュースティックの描画位置
		}

		//当たり判定処理
		if (billiards.pos.x + billiards.size.x > ball->pos.x && billiards.pos.x < ball->pos.x + ball->size.x)
		{
			if (billiards.pos.y + billiards.size.y > ball->pos.y && billiards.pos.y < ball->pos.y + ball->size.y)
			{
				if (player->rotate == 3) // 右向き
				{
					AddBallMove(10.0f, PI * 0.95f, player->pos.y, player->size.y);
				}
				if (player->rotate == 2) // 左向き
				{
					AddBallMove(10.0f, PI * 0.05f, player->pos.y, player->size.y);
				}
			}
		}

		billiards.time = billiards.time + 1.0f;
	}

	//キュースティックを振り切ったかの判断
	if (billiards.time > swingtime)
	{
		billiards.timeflag = false;
		billiards.time = 0.0f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && billiards.use == true)
		{
			billiards.pos = D3DXVECTOR2(0.0f, 0.0f);
			billiards.size = D3DXVECTOR2(120.0f, 5.0f);
			billiards.use = false;
			billiards.timeflag = false;
			billiards.time = 0.0f;
			billiards.usegauge = 20;

			billiards.bugincrease = false;
			billiards.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && billiards.use == true)
		{
			billiards.pos = D3DXVECTOR2(0.0f, 0.0f);
			billiards.size = D3DXVECTOR2(120.0f, 5.0f);
			billiards.use = false;
			billiards.timeflag = false;
			billiards.time = 0.0f;
			billiards.usegauge = 20;

			billiards.bugincrease = false;
			billiards.bugdrawnum = 0;
		}
	}

	if (enemybreak->drawflag == true && billiards.use == true)
	{
		billiards.pos = D3DXVECTOR2(0.0f, 0.0f);
		billiards.size = D3DXVECTOR2(120.0f, 5.0f);
		billiards.use = false;
		billiards.timeflag = false;
		billiards.time = 0.0f;
		billiards.usegauge = 20;

		billiards.bugincrease = false;
		billiards.bugdrawnum = 0;
	}
}

void DrawBilliards(void)
{
	if (billiards.timeflag == true)
		DrawSpriteLeftTop(billiards.texture, billiards.pos.x, billiards.pos.y, billiards.size.x, billiards.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}