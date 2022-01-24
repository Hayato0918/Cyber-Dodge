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

	auto_c.bugincrease = false;
	auto_c.bugdrawnum = 0;

	return S_OK;
}

//-----自動キャッチ処理
void _Auto_c(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	SKILL* skill = GetSkill();
	CATCH* Catch = GetCatch();
	BUGGAUGE* buggauge = GetBugGauge();

	//ランダムで15が出たら、10s間キャラの攻撃力が2倍になる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 15 && random[i].active == true && auto_c.use == false)
		{
			Catch->playerpos.y -= Catch->playersize.y;
			Catch->playersize.y *= 4;
			auto_c.auto_catch = true;
			auto_c.auto_catchflag = true;
			auto_c.timeflag = true;

			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && auto_c.bugincrease == false)
				{
					for (int j = i; auto_c.bugdrawnum < 10; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						auto_c.bugdrawnum = auto_c.bugdrawnum + 1;
					}
					auto_c.bugincrease = true;
				}
			}

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
		auto_c.auto_catchflag = false;
		auto_c.bugdrawnum = 0;
		auto_c.bugincrease = false;
		auto_c.time = 0.0f;
	}
	if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && auto_c.use == true)
	{
		if (auto_c.timeflag == true)
		{
			Catch->playerpos.y += Catch->playersize.y;
			Catch->playersize.y /= 4;
		}
		auto_c.timeflag = false;
		auto_c.auto_catch = false;
		auto_c.auto_catchflag = false;
		auto_c.bugdrawnum = 0;
		auto_c.bugincrease = false;
		auto_c.time = 0.0f;
		auto_c.use = false;
	}
}

AUTO* GetAuto()
{
	return &auto_c;
}