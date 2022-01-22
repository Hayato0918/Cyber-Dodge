//スキル_パワーダウン処理 [enemy_powerdown.cpp]
#include "enemy_powerdown.h"
//エネミー.h
#include "firewall.h"
#include "slime.h"
#include "deleter.h"
#include "input.h"

#include "bugincrease.h"

#include "skillrandom.h"

#include "map_point.h"
#include "map_player.h"

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

	powerdown.bugincrease = false;
	powerdown.bugdrawnum = 0;

	return S_OK;
}

//-----巨大化処理
void _PowerDown(void)
{
	FIREWALL* firewall = GetFireWall();
	SLIME* slime = GetSlime();
	DELETER* deleter = GetDeleter();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	RANDOM* random = GetRandom();
	MAP_PLAYER* map_player = GetMapPlayer();
	SKILL* skill = GetSkill();

	//ランダムで4が出たら、10s間敵のパワーが-50になる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 18 && random[i].active == true && powerdown.use == false)
		{
			if (map_player->encount == 1)
				slime->atk = slime->atk - 50;
			if (map_player->encount == 2)
				deleter->atk = deleter->atk - 50;
			if (map_player->encount == 3)
				firewall->atk = firewall->atk - 50;
			powerdown.timeflag = true;
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && powerdown.bugincrease == false)
				{
					for (int j = i; powerdown.bugdrawnum < 6; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						powerdown.bugdrawnum = powerdown.bugdrawnum + 1;
					}
					powerdown.bugincrease = true;
				}
			}
			powerdown.use = true;
		}
	}
	//スキル使用10s後にもとの強さに戻る
	if (powerdown.timeflag == true)
		powerdown.time = powerdown.time + 1.0f;
	if (powerdown.time > powerdowntime)
	{
		powerdown.timeflag = false;
		if (map_player->encount == 1)
			slime->atk = slime->atk + 50;
		if (map_player->encount == 2)
			deleter->atk = deleter->atk + 50;
		if (map_player->encount == 3)
			firewall->atk = firewall->atk + 50;
		powerdown.time = 0.0f;
	}

	if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot)
	{
		if (powerdown.time < powerdowntime)
		{
			if (map_player->encount == 1)
				slime->atk = slime->atk - 50;
			if (map_player->encount == 2)
				deleter->atk = deleter->atk - 50;
			if (map_player->encount == 3)
				firewall->atk = firewall->atk - 50;
		}
		powerdown.timeflag = false;
		powerdown.bugdrawnum = 0;
		powerdown.bugincrease = false;
		powerdown.time = 0.0f;
		powerdown.use = false;
	}


}