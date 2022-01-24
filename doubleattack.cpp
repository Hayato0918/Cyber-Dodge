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

	dable.bugincrease = false;
	dable.bugdrawnum = 0;

	return S_OK;
}

//-----ダブルアタック処理
void _Double(void)
{
	PLAYER* player = GetPlayer();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();

	//ランダムで4が出たら、10s間キャラの攻撃力が2倍になる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 17 && random[i].active == true && dable.use == false)
		{
			player->atk *= 2;
			dable.timeflag = true;
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && dable.bugincrease == false)
				{
					for (int j = i; dable.bugdrawnum < 6; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						dable.bugdrawnum = dable.bugdrawnum + 1;
					}
					dable.bugincrease = true;
				}
			}
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
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && dable.use == true)
		{
			if (dable.timeflag == true)
				player->atk /= 2;

			dable.use = false;
			dable.timeflag = false;
			dable.time = 0.0f;
			dable.usegauge = 30;

			dable.bugincrease = false;
			dable.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && dable.use == true)
		{
			if (dable.timeflag == true)
				player->atk /= 2;

			dable.use = false;
			dable.timeflag = false;
			dable.time = 0.0f;
			dable.usegauge = 30;

			dable.bugincrease = false;
			dable.bugdrawnum = 0;
		}
	}
}