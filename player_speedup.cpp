//スキル_スピードアップ処理 [player_speedup.cpp]
#include "player_speedup.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----マクロ定義
#define speeduptime 600		//10s間

//-----プロトタイプ宣言
SPEEDUP speedup;

//-----グローバル変数

//-----初期化処理
HRESULT InitSpeedUp(void)
{
	speedup.use = false;
	speedup.timeflag = false;
	speedup.time = 0.0f;
	speedup.usegauge = 20;

	return S_OK;
}

//-----巨大化処理
void _SpeedUp(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();

	//ランダムで4が出たら、10s間キャラのスピードが2倍になる
	if (random->code == 4 && random->active == true && speedup.use == false)
	{
		player->move *= 2;
		speedup.timeflag = true;
		bug->gaugesize.x = bug->gaugesize.x + speedup.usegauge * bug->gaugeonce;
		speedup.use = true;
	}
	//スキル使用10s後にもとのスピードに戻る
	if (speedup.timeflag == true)
		speedup.time = speedup.time + 1.0f;
	if (speedup.time > speeduptime)
	{
		speedup.timeflag = false;
		player->move /= 2;
		speedup.time = 0.0f;
	}
}