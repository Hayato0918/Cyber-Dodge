//スキル_自動キャッチ処理 [autocatch.cpp]
#include "autocatch.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"
#include "catch.h"

#include "skillrandom.h"

//-----マクロ定義
#define auto_ctime 600		//10s間

//-----プロトタイプ宣言
AUTO auto_c;

//-----グローバル変数

//-----初期化処理
HRESULT InitAuto_c(void)
{
	auto_c.use = false;
	auto_c.timeflag = false;
	auto_c.time = 0.0f;
	auto_c.usegauge = 50;
	auto_c.auto_catch = false;
	auto_c.auto_catchflag = false;

	return S_OK;
}

//-----自動キャッチ処理
void _Auto_c(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	CATCH* Catch = GetCatch();

	//ランダムで4が出たら、10s間キャラの攻撃力が2倍になる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 4 && random[i].active == true && auto_c.use == false)
		{
			Catch->playerpos.y -= Catch->playersize.y;
			Catch->playersize.y *= 4;
			auto_c.auto_catch = true;
			auto_c.auto_catchflag = true;
			auto_c.timeflag = true;
			bug->gaugesize.x = bug->gaugesize.x + auto_c.usegauge * bug->gaugeonce;
			auto_c.use = true;
		}
	}
	//スキル使用10s後にもとの状態戻る
	if (auto_c.timeflag == true)
		auto_c.time = auto_c.time + 1.0f;
	if (auto_c.time > auto_ctime)
	{
		Catch->playerpos.y += Catch->playersize.y;
		Catch->playersize.y /= 4;
		auto_c.timeflag = false;
		auto_c.auto_catch = false;
		auto_c.time = 0.0f;
		auto_c.use = false;
	}
}

AUTO* GetAuto()
{
	return &auto_c;
}