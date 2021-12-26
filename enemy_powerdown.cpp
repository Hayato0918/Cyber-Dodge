//スキル_パワーダウン処理 [enemy_powerdown.cpp]
#include "enemy_powerdown.h"
//エネミー.h
#include "firewall.h"
#include "slime.h"

#include "bugincrease.h"

#include "skillrandom.h"

#include "map_point.h"

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
	FIREWALL* firewall = GetFireWall();
	SLIME* slime = GetSlime();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	MAP_PLAYER* map_player = GetMapPlayer();

	//ランダムで4が出たら、10s間敵のパワーが-50になる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 4 && random[i].active == true && powerdown.use == false)
		{
			if (map_player->encount == 1)
				slime->atk = slime->atk - 50;
			if(map_player->encount == 2)
			firewall->atk = firewall->atk - 50;
			powerdown.timeflag = true;
			bug->gaugesize.x = bug->gaugesize.x + powerdown.usegauge * bug->gaugeonce;
			powerdown.use = true;
		}
	}
	//スキル使用10s後にもとの強さに戻る
	if (powerdown.timeflag == true)
		powerdown.time = powerdown.time + 1.0f;
	if (powerdown.time > powerdowntime)
	{
		powerdown.timeflag = false;
		firewall->atk = firewall->atk + 50;
		powerdown.time = 0.0f;
	}
}