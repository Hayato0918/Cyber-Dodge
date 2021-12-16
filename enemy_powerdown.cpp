//スキル_パワーダウン処理 [enemy_powerdown.cpp]
#include "enemy_powerdown.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "enemy.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----マクロ定義
#define powerdowntime 600		//10s間

//-----プロトタイプ宣言
POWERDOWN powerdown;

//-----グローバル変数

//-----初期化処理
HRESULT InitPowerDown(void)
{
	powerdown.use = false;
	powerdown.timeflag = false;
	powerdown.time = 0.0f;
	powerdown.usegauge = 30;

	return S_OK;
}

//-----巨大化処理
void _PowerDown(void)
{
	ENEMY* enemy = GetEnemy();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();

	//ランダムで4が出たら、10s間敵のパワーが-50になる
	if (random->code == 4 && random->active == true && powerdown.use == false)
	{
		enemy->atk = enemy->atk - 50;
		powerdown.timeflag = true;
		bug->gaugesize.x = bug->gaugesize.x + powerdown.usegauge * bug->gaugeonce;
		powerdown.use = true;
	}
	//スキル使用10s後にもとの強さに戻る
	if (powerdown.timeflag == true)
		powerdown.time = powerdown.time + 1.0f;
	if (powerdown.time > powerdowntime)
	{
		powerdown.timeflag = false;
		enemy->atk = enemy->atk + 50;
		powerdown.time = 0.0f;
	}
}