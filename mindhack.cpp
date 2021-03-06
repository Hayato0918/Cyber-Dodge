//スキル_マインドハック処理 [mindhack.cpp]
#include "mindhack.h"
//システム.h
#include "input.h"
//エネミー.h
#include "firewall.h"
#include "slime.h"

#include "player.h"
#include "bugincrease.h"
#include "catch.h"
#include "reverse.h"

#include "skillrandom.h"
#include "map_player.h"

//-----マクロ定義
#define mindhacktime 360		//6s間

//-----プロトタイプ宣言
MINDHACK mindhack;

//-----グローバル変数

//-----初期化処理
HRESULT InitMindhack(void)
{
	mindhack.use = false;
	mindhack.timeflag = false;
	mindhack.time = 0.0f;

	mindhack.bugincrease = false;
	mindhack.bugdrawnum = 0;

	return S_OK;
}

//-----マインドハック処理
void _Mindhack(void)
{
	PLAYER* player = GetPlayer();
	FIREWALL* firewall = GetFireWall();
	SLIME* slime = GetSlime();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();
	RANDOM* random = GetRandom();
	REVERSE* reverse = GetReverse();
	MAP_PLAYER* map_player = GetMapPlayer();

	//ランダムで4が出たら、6s間敵が行動不能になる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 20 && random[i].active == true && mindhack.use == false)
		{
			mindhack.timeflag = true;
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && mindhack.bugincrease == false)
				{
					for (int j = i; mindhack.bugdrawnum < 8; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						mindhack.bugdrawnum = mindhack.bugdrawnum + 1;
					}
					mindhack.bugincrease = true;
				}
			}
			mindhack.use = true;
		}
	}
	//スキル使用6s後にもとに戻る
	if (mindhack.timeflag == true)
	{
		mindhack.time = mindhack.time + 1.0f;

		if (PADUSE == 0)
		{
			if (IsButtonTriggered(0, BUTTON_UP))	//上
			{
				if (map_player->encount == 1)
				{
					if (reverse->use == false)
						slime->pos.y -= player->move.y;
					if (reverse->use == true)
						slime->pos.y += player->move.y;
				}
				if (map_player->encount == 2)
				{
					if (reverse->use == false)
						firewall->pos.y -= player->move.y;
					if (reverse->use == true)
						firewall->pos.y += player->move.y;
				}
			}
			if (IsButtonTriggered(0, BUTTON_DOWN))	//下
			{
				if (map_player->encount == 1)
				{
					if (reverse->use == false)
						slime->pos.y += player->move.y;
					if (reverse->use == true)
						slime->pos.y -= player->move.y;
				}
				if (map_player->encount == 2)
				{
					if (reverse->use == false)
						firewall->pos.y += player->move.y;
					if (reverse->use == true)
						firewall->pos.y -= player->move.y;
				}
			}
			if (IsButtonTriggered(0, BUTTON_LEFT))	//左
			{
				if (map_player->encount == 1)
				{
					if (reverse->use == false)
						slime->pos.x -= player->move.x;
					if (reverse->use == true)
						slime->pos.x += player->move.x;

					slime->rotate = 2;		//左向きに更新
				}
				if (map_player->encount == 2)
				{
					if (reverse->use == false)
						firewall->pos.x -= player->move.x;
					if (reverse->use == true)
						firewall->pos.x += player->move.x;

					firewall->rotate = 2;		//左向きに更新
					firewall->walktextureflag = true;		//テクスチャの切り替え
				}
			}
			if (IsButtonTriggered(0, BUTTON_RIGHT))	//右
			{
				if (map_player->encount == 1)
				{
					if (reverse->use == false)
						slime->pos.x += player->move.x;
					if (reverse->use == true)
						slime->pos.x -= player->move.x;

					slime->rotate = 3;		//右向きに更新
				}
				if (map_player->encount == 2)
				{
					if (reverse->use == false)
						firewall->pos.x += player->move.x;
					if (reverse->use == true)
						firewall->pos.x -= player->move.x;

					firewall->rotate = 3;		//右向きに更新
					firewall->walktextureflag = true;		//テクスチャの切り替え
				}
			}
		}

		if (PADUSE == 1)
		{
			if (GetKeyboardPress(DIK_W))	//上
			{
				if (map_player->encount == 1)
				{
					if (reverse->use == false)
						slime->pos.y -= player->move.y;
					if (reverse->use == true)
						slime->pos.y += player->move.y;
				}
				if (map_player->encount == 2)
				{
					if (reverse->use == false)
						firewall->pos.y -= player->move.y;
					if (reverse->use == true)
						firewall->pos.y += player->move.y;
				}
			}
			if (GetKeyboardPress(DIK_S))	//下
			{
				if (map_player->encount == 1)
				{
					if (reverse->use == false)
						slime->pos.y += player->move.y;
					if (reverse->use == true)
						slime->pos.y -= player->move.y;
				}
				if (map_player->encount == 2)
				{
					if (reverse->use == false)
						firewall->pos.y += player->move.y;
					if (reverse->use == true)
						firewall->pos.y -= player->move.y;
				}
			}
			if (GetKeyboardPress(DIK_A))	//左
			{
				if (map_player->encount == 1)
				{
					if (reverse->use == false)
						slime->pos.x -= player->move.x;
					if (reverse->use == true)
						slime->pos.x += player->move.x;

					slime->rotate = 2;		//左向きに更新
				}
				if (map_player->encount == 2)
				{
					if (reverse->use == false)
						firewall->pos.x -= player->move.x;
					if (reverse->use == true)
						firewall->pos.x += player->move.x;

					firewall->rotate = 2;		//左向きに更新
					firewall->walktextureflag = true;		//テクスチャの切り替え
				}
			}
			if (GetKeyboardPress(DIK_D))	//右
			{
				if (map_player->encount == 1)
				{
					if (reverse->use == false)
						slime->pos.x += player->move.x;
					if (reverse->use == true)
						slime->pos.x -= player->move.x;

					slime->rotate = 3;		//右向きに更新
				}
				if (map_player->encount == 2)
				{
					if (reverse->use == false)
						firewall->pos.x += player->move.x;
					if (reverse->use == true)
						firewall->pos.x -= player->move.x;

					firewall->rotate = 3;		//右向きに更新
					firewall->walktextureflag = true;		//テクスチャの切り替え
				}
			}
		}
	}

	if (mindhack.time > mindhacktime)
	{
		mindhack.timeflag = false;
		mindhack.time = 0.0f;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && mindhack.use == true)
		{
			mindhack.use = false;
			mindhack.timeflag = false;
			mindhack.time = 0.0f;

			mindhack.bugincrease = false;
			mindhack.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && mindhack.use == true)
		{
			mindhack.use = false;
			mindhack.timeflag = false;
			mindhack.time = 0.0f;

			mindhack.bugincrease = false;
			mindhack.bugdrawnum = 0;
		}
	}
}