//スキル_貫通 [kantsuu.cpp]
#include "penetration.h"
#include "input.h"
#include "bugincrease.h"
#include "skillrandom.h"
#include "rockcreate.h"
#include "enemybreak.h"

//-----マクロ定義
#define kantsuutime 180	//3s間

//-----プロトタイプ宣言
KANTSUU kantsuu;

//-----グローバル変数

//-----初期化処理
HRESULT InitKantsuu(void)
{
	kantsuu.use = false;
	kantsuu.timeflag = false;
	kantsuu.time = 0.0f;
	kantsuu.usegauge = 10;

	kantsuu.bugincrease = false;
	kantsuu.bugdrawnum = 0;

	return S_OK;
}

//-----不法侵入処理
void _Kantsuu(void)
{
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();
	ENEMYBREAK* enemybreak = GetEnemyBreak();

	//-----発動から3秒間、ボールが障害物の判定を貫通するようになる。
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 11 && random[i].active == true && kantsuu.use == false)
		{
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && kantsuu.bugincrease == false)
				{
					for (int j = i; kantsuu.bugdrawnum < 2; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						kantsuu.bugdrawnum = kantsuu.bugdrawnum + 1;
					}
					kantsuu.bugincrease = true;
				}
			}
			kantsuu.timeflag = true;
			kantsuu.use = true;
		}
	}

	//-----
	if (kantsuu.timeflag == true)
		kantsuu.time = kantsuu.time + 1.0f;

	if (kantsuu.time > kantsuutime)
	{
		kantsuu.timeflag = false;
		kantsuu.time = 0.0f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && kantsuu.use == true)
		{
			kantsuu.use = false;
			kantsuu.timeflag = false;
			kantsuu.time = 0.0f;
			kantsuu.usegauge = 10;

			kantsuu.bugincrease = false;
			kantsuu.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && kantsuu.use == true)
		{
			kantsuu.use = false;
			kantsuu.timeflag = false;
			kantsuu.time = 0.0f;
			kantsuu.usegauge = 10;

			kantsuu.bugincrease = false;
			kantsuu.bugdrawnum = 0;
		}
	}

	if (enemybreak->drawflag == true && kantsuu.use == true)
	{
		kantsuu.use = false;
		kantsuu.timeflag = false;
		kantsuu.time = 0.0f;
		kantsuu.usegauge = 10;

		kantsuu.bugincrease = false;
		kantsuu.bugdrawnum = 0;
	}
}

//-----構造体ポインタ取得処理
KANTSUU* GetKantsuu(void)
{
	return &kantsuu;
}