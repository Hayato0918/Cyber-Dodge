//スキル_地雷処理 [landmines.cpp]
#include "landmines.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "time.h"

#include "firewall.h"
#include "deleter.h"
#include "slime.h"
#include "bugincrease.h"
#include "map_player.h"

#include "skillrandom.h"

//-----マクロ定義
#define landminestime 180

//-----プロトタイプ宣言
LANDMINES landmines;

//-----グローバル変数

//-----初期化処理
HRESULT InitLandMines(void)
{

	landmines.size = D3DXVECTOR2(80.0f, 20.0f);
	srand((unsigned int)time(NULL));
	landmines.xrand = rand() % 10 + 1;
	srand((unsigned int)time(NULL) + 1);
	landmines.yrand = rand() % 10 + 1;
	landmines.pos = D3DXVECTOR2(landmines.xrand * SCREEN_WIDTH * 0.05f + 555.0f + landmines.size.x, 320.0f + landmines.yrand * 22 - landmines.size.y);

	landmines.texture = LoadTexture("data/TEXTURE/landmines.png");
	landmines.use = false;
	landmines.timeflag = false;
	landmines.possesion = 4;
	landmines.time = 0.0f;
	landmines.usegauge = 10;

	landmines.bugincrease = false;
	landmines.bugdrawnum = 0;

	return S_OK;
}

//-----地雷処理
void _LandMines(void)
{
	srand((unsigned int)time(NULL));

	SLIME* slime = GetSlime();
	DELETER* deleter = GetDeleter();
	FIREWALL* firewall = GetFireWall();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	RANDOM* random = GetRandom();
	MAP_PLAYER* map_player = GetMapPlayer();
	SKILL* skill = GetSkill();

	//Uキーを押したら地雷を設置
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 19 && random[i].active == true && landmines.use == false && landmines.possesion > 0)
		{
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && landmines.bugincrease == false)
				{
					for (int j = i; landmines.bugdrawnum < 8; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						landmines.bugdrawnum = landmines.bugdrawnum + 1;
					}
					landmines.bugincrease = true;
				}
			}
			landmines.use = true;
		}
	}

	//-----地雷エリアの上にいたら敵が動けなくなる
	if (landmines.use == true)
	{
		if (map_player->encount == 1)
		{
			if (slime->pos.x + slime->size.x > (landmines.pos.x + 70.0f) && (slime->pos.x + 70.0f) < landmines.pos.x + landmines.size.x)
			{
				landmines.timeflag = true;
				if (slime->pos.y + slime->size.y > (landmines.pos.y + 160.0f) && (slime->pos.y + 160.0f) < landmines.pos.y + landmines.size.y)
				{
					landmines.timeflag = true;
				}
			}
		}
		if (map_player->encount == 2)
		{
			if (deleter->pos.x + deleter->size.x > (landmines.pos.x + 70.0f) && (deleter->pos.x + 70.0f) < landmines.pos.x + landmines.size.x)
			{
				landmines.timeflag = true;
				if (deleter->pos.y + deleter->size.y > (landmines.pos.y + 160.0f) && (deleter->pos.y + 160.0f) < landmines.pos.y + landmines.size.y)
				{
					landmines.timeflag = true;
				}
			}
		}
		if (map_player->encount == 3)
		{
			if (firewall->pos.x + firewall->size.x > (landmines.pos.x + 70.0f) && (firewall->pos.x + 70.0f) < landmines.pos.x + landmines.size.x)
			{
				landmines.timeflag = true;
				if (firewall->pos.y + firewall->size.y > (landmines.pos.y + 160.0f) && (firewall->pos.y + 160.0f) < landmines.pos.y + landmines.size.y)
				{
					landmines.timeflag = true;
				}
			}
		}
	}

	//-----2秒経ったら消える
	if (landmines.timeflag == true)
		landmines.time = landmines.time + 1.0f;
	if (landmines.time > landminestime)
	{
		landmines.timeflag = false;
		landmines.time = 0.0f;
		landmines.possesion -= 1;
	}

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L2) && skill->usecount == skill->slot && landmines.use == true)
		{
			landmines.use = false;
			landmines.timeflag = false;
			landmines.possesion = 4;
			landmines.time = 0.0f;
			landmines.usegauge = 10;

			landmines.bugincrease = false;
			landmines.bugdrawnum = 0;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_2) && skill->usecount == skill->slot && landmines.use == true)
		{
			landmines.use = false;
			landmines.timeflag = false;
			landmines.possesion = 4;
			landmines.time = 0.0f;
			landmines.usegauge = 10;

			landmines.bugincrease = false;
			landmines.bugdrawnum = 0;
		}
	}
}

void DrawLandMines(void)
{
	if (landmines.use == true)
		DrawSpriteLeftTop(landmines.texture, landmines.pos.x, landmines.pos.y, landmines.size.x, landmines.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

LANDMINES* GetLandMines()
{
	return  &landmines;
}