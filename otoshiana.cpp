//スキル_落とし穴処理 [otoshiana.cpp]
#include "otoshiana.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "time.h"

#include "firewall.h"
#include "slime.h"
#include "bugincrease.h"
#include "player.h"

#include "skillrandom.h"
#include "map_point.h"

//-----マクロ定義
#define otosianatime 600

//-----プロトタイプ宣言
OTOSIANA otosiana;

//-----グローバル変数

//-----初期化処理
HRESULT InitOtosiana(void)
{
	otosiana.size = D3DXVECTOR2(100.0f, 100.0f);
	srand((unsigned int)time(NULL));
	otosiana.xrand = rand() % 10 + 1;
	srand((unsigned int)time(NULL) + 1);
	otosiana.yrand = rand() % 10 + 1;
	otosiana.pos = D3DXVECTOR2(otosiana.xrand * SCREEN_WIDTH * 0.05f + 555.0f + otosiana.size.x, 320.0f + otosiana.yrand * 22 - otosiana.size.y);

	otosiana.use = false;
	otosiana.timeflag = false;
	otosiana.texture = LoadTexture("data/TEXTURE/otosiana.png");
	otosiana.time = 0.0f;
	otosiana.usegauge = 10;

	otosiana.bugincrease = false;
	otosiana.bugdrawnum = 0;

	return S_OK;
}

//-----地雷処理
void _Otosiana(void)
{
	FIREWALL* firewall = GetFireWall();
	SLIME* slime = GetSlime();
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	PLAYER* player = GetPlayer();
	RANDOM* random = GetRandom();
	MAP_PLAYER* map_player = GetMapPlayer();

	//Yキーを押したら落とし穴を設置
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 21 && random[i].active == true && otosiana.use == false)
		{
			//-----バグゲージの上昇
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && otosiana.bugincrease == false)
				{
					for (int j = i; otosiana.bugdrawnum < 4; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						otosiana.bugdrawnum = otosiana.bugdrawnum + 1;
					}
					otosiana.bugincrease = true;
				}
			}
			otosiana.use = true;
		}
	}

	//-----移動を制限させる処理
	if (otosiana.timeflag == true)
	{
		if (map_player->encount == 1)
		{
			if (slime->pos.x + slime->size.x > otosiana.pos.x && slime->pos.x < otosiana.pos.x + otosiana.size.x)
			{

				if (slime->pos.y + slime->size.y > otosiana.pos.y + otosiana.size.y * 0.2f && slime->pos.y < otosiana.pos.y + otosiana.size.y * 0.5)
				{

					if (slime->move.x > 0)
						slime->pos.x -= 2.0f;
					if (slime->move.x < 0)
						slime->pos.x += 2.0f;

					if (slime->move.y > 0)
						slime->pos.y += 2.0f;
					if (slime->move.y < 0)
						slime->pos.y += 2.0f;
				}
			}
		}
		if (map_player->encount == 2)
		{
			if (firewall->pos.x + firewall->size.x > otosiana.pos.x && firewall->pos.x < otosiana.pos.x + otosiana.size.x)
			{

				if (firewall->pos.y + firewall->size.y > otosiana.pos.y + otosiana.size.y * 0.2f && firewall->pos.y < otosiana.pos.y + otosiana.size.y * 0.5)
				{

					if (firewall->move.x > 0)
						firewall->pos.x -= 2.0f;
					if (firewall->move.x < 0)
						firewall->pos.x += 2.0f;

					if (firewall->move.y > 0)
						firewall->pos.y += 2.0f;
					if (firewall->move.y < 0)
						firewall->pos.y += 2.0f;
				}
			}
		}
	}

	//-----スキル使用3s後にもとに戻る
	if (otosiana.timeflag == true)
		otosiana.time = otosiana.time + 1.0f;
	if (otosiana.time > otosianatime)
	{
		otosiana.timeflag = false;
		otosiana.time = 0.0f;
	}
}

void DrawOtosiana(void)
{
	if (otosiana.timeflag == true)
		DrawSpriteLeftTop(otosiana.texture, otosiana.pos.x, otosiana.pos.y, otosiana.size.x, otosiana.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

OTOSIANA* GetOtosiana()
{
	return  &otosiana;
}