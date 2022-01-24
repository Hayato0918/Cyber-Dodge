//スキル_時間停止処理 [timestop.cpp]
#include "timestop.h"
#include "input.h"
//-----エネミー.h
#include "firewall.h"
#include "slime.h"

#include "bugincrease.h"
#include "catch.h"

#include "skillrandom.h"

//-----マクロ定義
#define timestoptime 360		//6s間

//-----プロトタイプ宣言
TIMESTOP timestop;

//-----グローバル変数

//-----初期化処理
HRESULT InitTimestop(void)
{
	timestop.use = false;
	timestop.timeflag = false;
	timestop.time = 0.0f;
	timestop.posnow = D3DXVECTOR2(0.0f, 0.0f);

	timestop.bugincrease = false;
	timestop.bugdrawnum = 0;

	return S_OK;
}

//-----巨大化処理
void _Timestop(void)
{
	FIREWALL* firewall = GetFireWall();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();
	RANDOM* random = GetRandom();
	CATCH* cattch = GetCatch();

	//ランダムで4が出たら、6s間敵が行動不能になる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 25 && random[i].active == true && timestop.use == false)
		{
			timestop.posnow = firewall->pos;
			timestop.timeflag = true;
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && timestop.bugincrease == false)
				{
					for (int j = i; timestop.bugdrawnum < 16; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						timestop.bugdrawnum = timestop.bugdrawnum + 1;
					}
					timestop.bugincrease = true;
				}
			}
			timestop.use = true;
		}
	}
	//スキル使用6s後にもとに戻る
	if (timestop.timeflag == true)
	{
		timestop.time = timestop.time + 1.0f;
		firewall->pos = timestop.posnow;
		cattch->enemyflag = 2;
		cattch->enemyintervalflag = 2;
	}

	if (timestop.time > timestoptime)
	{
		timestop.timeflag = false;
		timestop.time = 0.0f;
		cattch->enemyflag = 0;
		cattch->enemyintervalflag = 0;
	}

	if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && timestop.use == true)
	{
		timestop.use = false;
		timestop.timeflag = false;
		timestop.time = 0.0f;
		timestop.posnow = D3DXVECTOR2(0.0f, 0.0f);
		cattch->enemyflag = 0;
		cattch->enemyintervalflag = 0;

		timestop.bugincrease = false;
		timestop.bugdrawnum = 0;
	}
}