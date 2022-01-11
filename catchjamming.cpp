//スキル_キャッチ妨害処理 [cacthjamming.cpp]
#include "catchjamming.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "bugincrease.h"

#include "skillrandom.h"

//-----マクロ定義
#define catchjammingtime 180		//3s間

//-----プロトタイプ宣言
CATCHJAMMING catchjamming;

HRESULT InitCatchJamming(void)
{
	catchjamming.use = false;
	catchjamming.timeflag = false;
	catchjamming.time = 0.0f;
	catchjamming.usegauge = 100;

	catchjamming.bugincrease = false;
	catchjamming.bugdrawnum = 0;

	return S_OK;
}

void _CatchJamming(void)
{
	BUG* bug = GetBugIncrease();;
	RANDOM* random = GetRandom();
	BUGGAUGE* buggauge = GetBugGauge();

	//Iキーを押したら、3秒間キャッチが出来なくなる。
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 8 && random[i].active == true && catchjamming.use == false)
		{
			catchjamming.timeflag = true;
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && catchjamming.bugincrease == false)
				{
					for (int j = i; catchjamming.bugdrawnum < 12; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						catchjamming.bugdrawnum = catchjamming.bugdrawnum + 1;
					}
					catchjamming.bugincrease = true;
				}
			}
			catchjamming.use = true;
		}
	}
	//スキル使用3秒後にもとに戻る
	if (catchjamming.timeflag == true)
		catchjamming.time = catchjamming.time + 1.0f;
	if (catchjamming.time > catchjammingtime)
	{
		catchjamming.timeflag = false;
		catchjamming.time = 0.0f;
	}
}

CATCHJAMMING* GetCatchJamming()
{
	return &catchjamming;
}