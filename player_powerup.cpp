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

	powerup.bugincrease = false;
	powerup.bugdrawnum = 0;

	return S_OK;
}

//-----巨大化処理
void _PowerUp(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	RANDOM* random = GetRandom();

	//ランダムで4が出たら、10s間キャラのパワーが+50になる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 22 && random[i].active == true && powerup.use == false)
		{
			player->atk += 50;
			powerup.timeflag = true;
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && powerup.bugincrease == false)
				{
					for (int j = i; powerup.bugdrawnum < 4; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						powerup.bugdrawnum = powerup.bugdrawnum + 1;
					}
					powerup.bugincrease = true;
				}
			}
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