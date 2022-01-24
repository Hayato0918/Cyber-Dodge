//スキル_不法侵入処理 [invade.cpp]
#include "invade.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----マクロ定義
#define invadetime 420		//3s間

//-----プロトタイプ宣言
INVADE invade;

//-----グローバル変数

//-----初期化処理
HRESULT InitInvade(void)
{
	invade.use = false;
	invade.timeflag = false;
	invade.time = 0.0f;
	invade.usegauge = 10;

	invade.bugincrease = false;
	invade.bugdrawnum = 0;

	return S_OK;
}

//-----不法侵入処理
void _Invade(void)
{
	PLAYER* player = GetPlayer();
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();

	//ランダムで5が選ばれたら、3秒間敵の陣地に入れる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 9 && random[i].active == true && invade.use == false)
		{
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && invade.bugincrease == false)
				{
					for (int j = i; invade.bugdrawnum < 2; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						invade.bugdrawnum = invade.bugdrawnum + 1;
					}
					invade.bugincrease = true;
				}
			}

			//-----プレイヤーの位置を敵陣までワープさせる
			player->pos.x = (SCREEN_WIDTH / 2) + 5;

			invade.timeflag = true;
			invade.use = true;
		}
	}

	//スキル終了時に敵陣にいた場合、x座標を自陣と敵陣の境界まで戻す
	if (invade.timeflag == true)
		invade.time = invade.time + 1.0f;
	if (invade.time > invadetime)
	{
		invade.timeflag = false;
		invade.time = 0.0f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && invade.use == true)
		{
			invade.use = false;
			invade.timeflag = false;
			invade.time = 0.0f;
			invade.usegauge = 10;

			invade.bugincrease = false;
			invade.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && invade.use == true)
		{
			invade.use = false;
			invade.timeflag = false;
			invade.time = 0.0f;
			invade.usegauge = 10;

			invade.bugincrease = false;
			invade.bugdrawnum = 0;
		}
	}
}

//-----構造体ポインタ取得処理
INVADE* GetInvade(void)
{
	return &invade;
}