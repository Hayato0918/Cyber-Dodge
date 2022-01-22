//スキル_消滅処理 [disappear.cpp]
#include "disappear.h"
#include "input.h"
#include "sprite.h"

#include "bugincrease.h"

#include "skillrandom.h"
#include "otoshiana.h"

//-----マクロ定義

//-----プロトタイプ宣言
DISAPPEAR disappear;

//-----グローバル変数

//-----初期化処理
HRESULT InitDisappear(void)
{

	disappear.use = false;

	disappear.usegauge = 10;

	disappear.bugincrease = false;
	disappear.bugdrawnum = 0;

	return S_OK;
}

//-----消滅処理
void _Disappear(void)
{
	OTOSIANA* otosiana = GetOtosiana();
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();

	//Tキーを押したら障害物を消滅
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 16 && random[i].active == true && disappear.use == false)
		{
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && disappear.bugincrease == false)
				{
					for (int j = i; disappear.bugdrawnum < 3; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						disappear.bugdrawnum = disappear.bugdrawnum + 1;
					}
					disappear.bugincrease = true;
				}
			}
			disappear.use = true;
		}
	}

	if (disappear.use == true)							//落とし穴が消滅する。
	{
		otosiana->timeflag = false;
	}

	if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot)
	{
		disappear.bugincrease = false;
		disappear.bugdrawnum = 0;
		disappear.use = false;
	}

}
