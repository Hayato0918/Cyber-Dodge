//スキル_時間停止処理 [timestop.cpp]
#include "timestop.h"
//-----エネミー.h
#include "firewall.h"

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
	timestop.usegauge = 80;
	timestop.posnow = D3DXVECTOR2(0.0f, 0.0f);

	return S_OK;
}

//-----巨大化処理
void _Timestop(void)
{
	FIREWALL* firewall = GetFireWall();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	CATCH* cattch = GetCatch();

	//ランダムで4が出たら、6s間敵が行動不能になる
	if (random->code == 4 && random->active == true && timestop.use == false)
	{
		timestop.posnow = firewall->pos;
		timestop.timeflag = true;
		bug->gaugesize.x = bug->gaugesize.x + timestop.usegauge * bug->gaugeonce;
		timestop.use = true;
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
		timestop.use = false;
		cattch->enemyflag = 0;
		cattch->enemyintervalflag = 0;
	}
}