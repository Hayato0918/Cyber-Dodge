//スキル_キャッチ妨害処理 [cacthjamming.cpp]
#include "catchjamming.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "bug.h"

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

	return S_OK;
}

void _CatchJamming(void)
{
	BUG* bug = GetBug();
	RANDOM* random = GetRandom();

	//Iキーを押したら、3秒間キャッチが出来なくなる。
	for (int i = 0; i < 5; i++)
	{
		if (random[i].code == 8 && random[i].active == true && catchjamming.use == false)
		{
			catchjamming.timeflag = true;
			bug->gaugesize.x = bug->gaugesize.x + catchjamming.usegauge * bug->gaugeonce;
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