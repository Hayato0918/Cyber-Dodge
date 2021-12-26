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

	return S_OK;
}

//-----消滅処理
void _Disappear(void)
{
	OTOSIANA* otosiana = GetOtosiana();
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();

	//Tキーを押したら障害物を消滅
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code = 4 && random[i].active == true && disappear.use == false)
		{
			bug->gaugesize.x = bug->gaugesize.x + disappear.usegauge * bug->gaugeonce;
			disappear.use = true;
		}
	}

	if (disappear.use == true)							//落とし穴が消滅する。
	{
		otosiana->timeflag = false;
	}
}
