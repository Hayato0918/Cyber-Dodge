/*------------------------------------------
[ 暗転 [ notCatch.cpp ] ]
-------------------------------------------*/
#include "notCatch.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"

#include "bugincrease.h"
#include "bugrandom.h"

//-----マクロ定義
#define notCatchtime	1800		//バグの効果時間。30秒間。

//-----プロトタイプ宣言
NOTCATCH notCatch;

HRESULT InitNotCatch(void)
{
	notCatch.use = false;
	notCatch.timeflag = false;
	notCatch.time = 0.0f;
	notCatch.usegauge = 100;

	return S_OK;
}

void _NotCatch(void)
{
	BUG* bug = GetBugIncrease();
	BUGRANDOM* bugrandom = GetBugRandom();

	//バグゲージが溜まると、30秒間キャッチが出来なくなる。
	if (bugrandom->code == 5 && bug->breakflag == true && notCatch.use == false)
	{
		notCatch.time = 0.0f;
		if (notCatch.use == false)
		{
			notCatch.timeflag = true;
			notCatch.use = true;
		}
	}

	//30秒後にもとに戻る
	if (notCatch.timeflag == true)
		notCatch.time = notCatch.time + 1.0f;
	if (bug->breakflag == false && notCatch.use == true)
	{
		notCatch.timeflag = false;
		notCatch.time = 0.0f;

		notCatch.use = false;
	}
}

NOTCATCH* GetNotCatch()
{
	return &notCatch;
}