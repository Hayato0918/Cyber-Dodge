//スキル_パワーアップ処理 [player_powerup.cpp]
#include "player_powerup.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----マクロ定義
#define poweruptime 600		//10s間

//-----プロトタイプ宣言
POWERUP powerup;

//-----グローバル変数

//-----初期化処理
HRESULT InitPowerUp(void)
{
	powerup.use = false;
	powerup.timeflag = false;
	powerup.time = 0.0f;
	powerup.usegauge = 20;

	return S_OK;
}

//-----巨大化処理
void _PowerUp(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();

	//ランダムで4が出たら、10s間キャラのパワーが+50になる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 4 && random[i].active == true && powerup.use == false)
		{
			player->atk += 50;
			powerup.timeflag = true;
			bug->gaugesize.x = bug->gaugesize.x + powerup.usegauge * bug->gaugeonce;
			powerup.use = true;
		}
	}
	//スキル使用10s後にもとの強さに戻る
	if (powerup.timeflag == true)
		powerup.time = powerup.time + 1.0f;
	if (powerup.time > poweruptime)
	{
		powerup.timeflag = false;
		player->atk -= 50;
		powerup.time = 0.0f;
	}
}