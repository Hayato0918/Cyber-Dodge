//スキル_時間停止処理 [timestop.cpp]
#include "timestop.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"
//-----エネミー.h
#include "firewall.h"
#include "deleter.h"
#include "slime.h"

#include "bugincrease.h"
#include "catch.h"

#include "skillrandom.h"
#include "map_player.h"
#include "enemybreak.h"

//-----マクロ定義
#define timestoptime 360		//6s間

//-----プロトタイプ宣言
TIMESTOP timestop;

//-----グローバル変数

//-----初期化処理
HRESULT InitTimestop(void)
{
	timestop.use = false;
	timestop.timeflag = false;
	timestop.time = 0.0f;
	timestop.posnow = D3DXVECTOR2(0.0f, 0.0f);


	MAP_PLAYER* map_player = GetMapPlayer();
	SLIME* slime = GetSlime();
	DELETER* deleter = GetDeleter();
	FIREWALL* firewall = GetFireWall();

	if (map_player->encount == 1)
		timestop.pos = D3DXVECTOR2(slime->pos.x - 60, slime->pos.y - 30);
	if (map_player->encount == 2)
		timestop.pos = D3DXVECTOR2(deleter->pos.x - 60, deleter->pos.y - 30);
	if (map_player->encount == 3)
		timestop.pos = D3DXVECTOR2(firewall->pos.x - 60, firewall->pos.y - 30);
	timestop.u = 0.f;
	timestop.size = D3DXVECTOR2(250.f, 250.f);
	timestop.texture = LoadTexture("data/TEXTURE/Timestop.png");

	timestop.bugincrease = false;
	timestop.bugdrawnum = 0;

	return S_OK;
}

//-----巨大化処理
void _Timestop(void)
{
	FIREWALL* firewall = GetFireWall();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	SKILL* skill = GetSkill();
	RANDOM* random = GetRandom();
	CATCH* cattch = GetCatch();

	MAP_PLAYER* map_player = GetMapPlayer();
	SLIME* slime = GetSlime();
	DELETER* deleter = GetDeleter();
	ENEMYBREAK* enemybreak = GetEnemyBreak();

	if (map_player->encount == 1)
		timestop.pos = D3DXVECTOR2(slime->pos.x - 30, slime->pos.y - 30);
	if (map_player->encount == 2)
		timestop.pos = D3DXVECTOR2(deleter->pos.x - 30, deleter->pos.y - 30);
	if (map_player->encount == 3)
		timestop.pos = D3DXVECTOR2(firewall->pos.x - 30, firewall->pos.y - 30);

	//ランダムで4が出たら、6s間敵が行動不能になる
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 25 && random[i].active == true && timestop.use == false)
		{
			if (map_player->encount == 1)
				timestop.posnow = slime->pos;
			if (map_player->encount == 2)
				timestop.posnow = deleter->pos;
			if(map_player->encount == 3)
				timestop.posnow = firewall->pos;

			timestop.timeflag = true;
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && timestop.bugincrease == false)
				{
					for (int j = i; timestop.bugdrawnum < 16; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						timestop.bugdrawnum = timestop.bugdrawnum + 1;
					}
					timestop.bugincrease = true;
				}
			}
			timestop.use = true;
		}
	}
	//スキル使用6s後にもとに戻る
	if (timestop.timeflag == true)
	{
		timestop.time = timestop.time + 1.0f;

		if (map_player->encount == 1)
			slime->pos = timestop.posnow;
		if (map_player->encount == 2)
			deleter->pos = timestop.posnow;
		if(map_player->encount == 3)
			firewall->pos = timestop.posnow;
		cattch->enemyflag = 2;
		cattch->enemyintervalflag = 2;
	}

	if (timestop.time > timestoptime)
	{
		timestop.timeflag = false;
		timestop.time = 0.0f;
		cattch->enemyflag = 0;
		cattch->enemyintervalflag = 0;
	}

	//アニメーション
	for (int i = 0; i < 10; i++)
	{
		if (timestop.time >= 36 * i && timestop.time < 36 + 36 * i)
			timestop.u = 0.1f * i;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && timestop.use == true)
		{
			timestop.use = false;
			timestop.timeflag = false;
			timestop.time = 0.0f;
			timestop.posnow = D3DXVECTOR2(0.0f, 0.0f);
			cattch->enemyflag = 0;
			cattch->enemyintervalflag = 0;

			timestop.bugincrease = false;
			timestop.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && timestop.use == true)
		{
			timestop.use = false;
			timestop.timeflag = false;
			timestop.time = 0.0f;
			timestop.posnow = D3DXVECTOR2(0.0f, 0.0f);
			cattch->enemyflag = 0;
			cattch->enemyintervalflag = 0;

			timestop.bugincrease = false;
			timestop.bugdrawnum = 0;
		}
	}

	if (enemybreak->drawflag == true && timestop.use == true)
	{
		timestop.use = false;
		timestop.timeflag = false;
		timestop.time = 0.0f;
		timestop.posnow = D3DXVECTOR2(0.0f, 0.0f);
		cattch->enemyflag = 0;
		cattch->enemyintervalflag = 0;

		timestop.bugincrease = false;
		timestop.bugdrawnum = 0;
	}
}

void DrawTimestop()
{
	if(timestop.timeflag == true)
	DrawSpriteLeftTop(timestop.texture, timestop.pos.x, timestop.pos.y, timestop.size.x, timestop.size.y, timestop.u, 0.f, 0.1f, 1.f);
}