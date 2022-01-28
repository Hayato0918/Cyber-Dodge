//スキル_プレイヤーが小さくなる処理 [SmallPlayer.cpp] 
#include "smallplayer.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "catch.h"
#include "bugincrease.h"

#include "skillrandom.h"
#include "enemybreak.h"

//-----マクロ定義
#define smallplayertime 420		//3s間

//-----プロトタイプ宣言
SMALLPLAYER smallplayer;

//-----グローバル変数

//-----初期化処理
HRESULT InitSmallPlayer(void)
{
	smallplayer.use = false;
	smallplayer.timeflag = false;
	smallplayer.time = 0.0f;
	smallplayer.usegauge = 10;

	smallplayer.bugincrease = false;
	smallplayer.bugdrawnum = 0;

	return S_OK;
}

//-----プレイヤー縮小処理
void _SmallPlayer(void)
{
	PLAYER* player = GetPlayer();
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	CATCH* Catch = GetCatch();
	SKILL* skill = GetSkill();
	ENEMYBREAK* enemybreak = GetEnemyBreak();

	//ランダムで7が選ばれたら、3s間キャラのサイズが0.5倍小さくなるになる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 14 && random[i].active == true && smallplayer.use == false)
		{
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && smallplayer.bugincrease == false)
				{
					for (int j = i; smallplayer.bugdrawnum < 2; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						smallplayer.bugdrawnum = smallplayer.bugdrawnum + 1;
					}
					smallplayer.bugincrease = true;
				}
			}
			player->size = D3DXVECTOR2(player->size.x * 0.5f, player->size.y * 0.5f);
			Catch->playersize = D3DXVECTOR2(Catch->playersize.x / 2, Catch->playersize.y / 2);
			smallplayer.timeflag = true;
			smallplayer.use = true;
		}
	}
	//スキル使用3s後にもとの大きさに戻る
	if (smallplayer.timeflag == true)
		smallplayer.time = smallplayer.time + 1.0f;
	if (smallplayer.time > smallplayertime)
	{
		smallplayer.timeflag = false;
		player->size = D3DXVECTOR2(player->size.x * 2, player->size.y * 2);
		Catch->playersize = D3DXVECTOR2(Catch->playersize.x * 2, Catch->playersize.y * 2);
		smallplayer.time = 0.0f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && smallplayer.use == true)
		{
			if (smallplayer.time < smallplayertime && smallplayer.timeflag == true)
			{
				player->size = D3DXVECTOR2(player->size.x * 2, player->size.y * 2);
				Catch->playersize = D3DXVECTOR2(Catch->playersize.x * 2, Catch->playersize.y * 2);
			}

			smallplayer.use = false;
			smallplayer.timeflag = false;
			smallplayer.time = 0.0f;
			smallplayer.usegauge = 10;

			smallplayer.bugincrease = false;
			smallplayer.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && smallplayer.use == true)
		{
			if (smallplayer.time < smallplayertime && smallplayer.timeflag == true)
			{
				player->size = D3DXVECTOR2(player->size.x * 2, player->size.y * 2);
				Catch->playersize = D3DXVECTOR2(Catch->playersize.x * 2, Catch->playersize.y * 2);
			}

			smallplayer.use = false;
			smallplayer.timeflag = false;
			smallplayer.time = 0.0f;
			smallplayer.usegauge = 10;

			smallplayer.bugincrease = false;
			smallplayer.bugdrawnum = 0;
		}
	}

	if (enemybreak->drawflag == true && smallplayer.use == true)
	{
		if (smallplayer.time < smallplayertime && smallplayer.timeflag == true)
		{
			player->size = D3DXVECTOR2(player->size.x * 2, player->size.y * 2);
			Catch->playersize = D3DXVECTOR2(Catch->playersize.x * 2, Catch->playersize.y * 2);
		}

		smallplayer.use = false;
		smallplayer.timeflag = false;
		smallplayer.time = 0.0f;
		smallplayer.usegauge = 10;

		smallplayer.bugincrease = false;
		smallplayer.bugdrawnum = 0;
	}

}