//スキル_スロウエリア処理 [slowarea.cpp]
#include "slowarea.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "time.h"

#include "player.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----マクロ定義
#define slowareatime 180		//3s間

//-----プロトタイプ宣言
SLOWAREA slowarea;

//-----グローバル変数

//-----初期化処理
HRESULT InitSlowArea(void)
{
	slowarea.size = D3DXVECTOR2(160.0f, 160.0f);
	srand((unsigned int)time(NULL));
	slowarea.xrand = rand() % 10 + 1;
	srand((unsigned int)time(NULL) + 1);
	slowarea.yrand = rand() % 10 + 1;
	slowarea.pos = D3DXVECTOR2(slowarea.xrand * SCREEN_WIDTH * 0.05f - slowarea.size.x, 320.0f + slowarea.yrand * 22 - slowarea.size.y);
	slowarea.use = false;
	slowarea.timeflag = false;
	slowarea.time = 0.0f;
	slowarea.usegauge = 30;

	slowarea.u = 0.f;

	slowarea.bugincrease = false;
	slowarea.bugdrawnum = 0;

	return S_OK;
}

//-----スロー処理
void _SlowArea(void)
{
	srand((unsigned int)time(NULL));

	PLAYER* player = GetPlayer();
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();

	//-----ランダムで6が選ばれたら、3s間足がおそくなるエリアができる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 13 && random[i].active == true && slowarea.use == false)
		{
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && slowarea.bugincrease == false)
				{
					for (int j = i; slowarea.bugdrawnum < 4; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						slowarea.bugdrawnum = slowarea.bugdrawnum + 1;
					}
					slowarea.bugincrease = true;
				}
			}
			slowarea.timeflag = true;
			slowarea.use = true;
		}
	}

	//-----エリアの上にいたら足が遅くなる
	if (slowarea.timeflag == true)
	{
		if (player->pos.x + player->size.x > slowarea.pos.x && player->pos.x < slowarea.pos.x + slowarea.size.x)
		{
			if (player->pos.y + player->size.y > slowarea.pos.y && player->pos.y < slowarea.pos.y + slowarea.size.y)
				player->move = D3DXVECTOR2(2.0f, 2.0f);
			else
				player->move = D3DXVECTOR2(4.0f, 4.0f);
		}
		else
			player->move = D3DXVECTOR2(4.0f, 4.0f);
	}

	//-----スキル使用3s後にもとに戻る
	if (slowarea.timeflag == true)
		slowarea.time = slowarea.time + 1.0f;
	if (slowarea.time > slowareatime)
	{
		slowarea.timeflag = false;
		player->move = D3DXVECTOR2(4, 4);
		slowarea.time = 0.0f;
		srand((unsigned int)time(NULL));
		slowarea.xrand = rand() % 10 + 1;
		srand((unsigned int)time(NULL) + 1);
		slowarea.yrand = rand() % 10 + 1;
		slowarea.pos = D3DXVECTOR2(slowarea.xrand * SCREEN_WIDTH * 0.05f - slowarea.size.x, 320.0f + slowarea.yrand * 22 - slowarea.size.y);
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && slowarea.use == true)
		{
			if (slowarea.timeflag == true)
				player->move = D3DXVECTOR2(4, 4);
			slowarea.use = false;
			slowarea.timeflag = false;
			slowarea.time = 0.0f;
			srand((unsigned int)time(NULL));
			slowarea.xrand = rand() % 10 + 1;
			srand((unsigned int)time(NULL) + 1);
			slowarea.yrand = rand() % 10 + 1;
			slowarea.pos = D3DXVECTOR2(slowarea.xrand * SCREEN_WIDTH * 0.05f - slowarea.size.x, 320.0f + slowarea.yrand * 22 - slowarea.size.y);

			slowarea.bugincrease = false;
			slowarea.bugdrawnum = 0;
		}
	}



	//アニメーション
	for (int i = 0; i < 20; i++)
	{
		if (slowarea.time >= i * 9.f && slowarea.time < 9.f + i * 9.f)
			slowarea.u = 0.05f * i;
	}
}

//-----描画処理
void DrawSlowArea(void)
{
	if (slowarea.timeflag == true)
		DrawSpriteLeftTop(slowarea.texture, slowarea.pos.x, slowarea.pos.y, slowarea.size.x, slowarea.size.y, slowarea.u, 0.f, 0.05f, 1.0f);
}

SLOWAREA* GetSlowarea()
{
	return &slowarea;
}