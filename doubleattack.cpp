//スキル_ダブルアタック処理 [double_attack.cpp]
#include "doubleattack.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----マクロ定義
#define doubletime 600		//10s間

//-----プロトタイプ宣言
DABLE dable;

//-----グローバル変数

//-----初期化処理
HRESULT InitDouble(void)
{
	dable.use = false;
	dable.timeflag = false;
	dable.time = 0.0f;
	dable.usegauge = 30;

	return S_OK;
}

//-----ダブルアタック処理
void _Double(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();

	//ランダムで4が出たら、10s間キャラの攻撃力が2倍になる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 4 && random[i].active == true && dable.use == false)
		{
			player->atk *= 2;
			dable.timeflag = true;
			bug->gaugesize.x = bug->gaugesize.x + dable.usegauge * bug->gaugeonce;
			dable.use = true;
		}
	}
	//スキル使用10s後にもとの攻撃力に戻る
	if (dable.timeflag == true)
		dable.time = dable.time + 1.0f;
	if (dable.time > doubletime)
	{
		dable.timeflag = false;
		player->atk /= 2;
		dable.time = 0.0f;
		dable.use = false;
	}
}