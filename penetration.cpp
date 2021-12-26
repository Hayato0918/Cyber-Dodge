//スキル_貫通 [kantsuu.cpp]
#include "penetration.h"
#include "input.h"
#include "bugincrease.h"
#include "skillrandom.h"
#include "rockcreate.h"

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

	return S_OK;
}

//-----不法侵入処理
void _Kantsuu(void)
{
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();;

	//-----発動から3秒間、ボールが障害物の判定を貫通するようになる。
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 11 && random[i].active == true && kantsuu.use == false)
		{
			bug->gaugesize.x = bug->gaugesize.x + kantsuu.usegauge * bug->gaugeonce;
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
}

//-----構造体ポインタ取得処理
KANTSUU* GetKantsuu(void)
{
	return &kantsuu;
}