//エネミー撃破処理[enemy.cpp]
#include "enemybreak.h"
//システム.h
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "texture.h"
#include "sprite.h"
#include <time.h>
//slime.h
#include "slime.h"
//deleter.h
#include "deleter.h"
//firewall.h
#include "firewall.h"

#include "skillrandom.h"
#include "map_player.h"
#include "player.h"
#include "bugincrease.h"

ENEMYBREAK enemybreak;
GETSKILL getskill;
GETGOLD getgold[4];
GETGOLDNUM getgoldnum;
GETSCORE getscore;

int enemybreaktexture;

HRESULT InitEnemyBreak(void)
{
	enemybreaktexture = LoadTexture("data/TEXTURE/skill/skill.png");

	MAP_PLAYER* map_player = GetMapPlayer();

	//-----背景
	enemybreak.pos = D3DXVECTOR2(300.f, 100.f);
	enemybreak.size = D3DXVECTOR2(1000.f, 700.f);
	enemybreak.texture = LoadTexture("data/TEXTURE/result.png");
	enemybreak.drawflag = false;

	//-----スキル
	getskill.pos = D3DXVECTOR2(420.f, 380.f);
	getskill.size = D3DXVECTOR2(200.f, 300.f);
	getskill.skillcode = 0;

	//-----ゴールド
	for (int i = 0; i < 4; i++)
	{
		getgold[i].pos = D3DXVECTOR2(680.f + i * 100, 360.f);
		getgold[i].size = D3DXVECTOR2(100.f, 100.f);
		getgold[i].u = 0.f;
		getgold[i].v = 0.f;
		getgold[i].drawflag = true;
	}
	getgoldnum.texture = LoadTexture("data/TEXTURE/number.png");

	if (map_player->encount == 1)
	{
		getgoldnum.gold = 30 + (rand() % 50);
		getscore.score = 30 + (rand() % 50);
	}
	if (map_player->encount == 2)
	{
		getgoldnum.gold = (30 + (rand() % 50)) * 2;
		getscore.score = (30 + (rand() % 50)) * 2;
	}
	if (map_player->encount == 3)
	{
		getgoldnum.gold = (30 + (rand() % 50)) * 4;
		getscore.score = (30 + (rand() % 50)) * 4;
	}
	return S_OK;
}

void UninitEnemyBreak(void)
{

}

void UpdateEnemyBreak(void)
{
	SKILL* skill = GetSkill();
	RANDOM* random = GetRandom();
	PLAYER* player = GetPlayer();
	MAP_PLAYER* map_player = GetMapPlayer();
	BUG* bug = GetBugIncrease();

	srand((unsigned int)time(NULL));

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_Y) && enemybreak.drawflag == true)
		{
			player->gold = player->gold + getgoldnum.gold;
			player->score = player->score + getscore.score;
			SceneTransition(SCENE_MAP);
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_RETURN) && enemybreak.drawflag == true)
		{
			player->gold = player->gold + getgoldnum.gold;
			player->score = player->score + getscore.score;
			SceneTransition(SCENE_MAP);
		}
	}

	//-----スキル獲得
	if (enemybreak.drawflag == true)
	{
		getskill.skillcode = random[skill->slot - 1].code;
		bug->breakflag = false;
		StopSoundAll();
	}

	//割り当てられたcodeに対応したテクスチャを表示
	for (int j = 1; j < 27; j++)
	{
		if (getskill.skillcode == j)
				getskill.u = 0.0384615385f * (j - 1);
	}


	//-----ゴールド獲得
	getgoldnum.a = getgoldnum.gold * 0.001f;
	getgoldnum.b = (getgoldnum.gold - getgoldnum.a * 1000) * 0.01f;
	getgoldnum.c = (getgoldnum.gold - getgoldnum.a * 1000 - getgoldnum.b * 100) * 0.1f;
	getgoldnum.d = getgoldnum.gold - getgoldnum.a * 1000 - getgoldnum.b * 100 - getgoldnum.c * 10;

	//goldの1000の位
	if (getgoldnum.a < 5)
	{
		getgold[0].u = 0.2f * getgoldnum.a;
		getgold[0].v = 0.f;
	}
	if (getgoldnum.a >= 5)
	{
		getgold[0].u = 0.2f * getgoldnum.a;
		getgold[0].v = 0.5f;
	}
	if (getgoldnum.a <= 0)
		getgold[0].drawflag = false;
	if (getgoldnum.a > 0)
		getgold[0].drawflag = true;
	//goldの100の位
	if (getgoldnum.b < 5)
	{
		getgold[1].u = 0.2f * getgoldnum.b;
		getgold[1].v = 0.f;
	}
	if (getgoldnum.b >= 5)
	{
		getgold[1].u = 0.2f * getgoldnum.b;
		getgold[1].v = 0.5f;
	}
	if (getgoldnum.b >= 0)
		getgold[1].drawflag = true;
	if (getgoldnum.a <= 0 && getgoldnum.b <= 0)
		getgold[1].drawflag = false;
	//goldの10の位
	if (getgoldnum.c < 5)
	{
		getgold[2].u = 0.2f * getgoldnum.c;
		getgold[2].v = 0.f;
	}
	if (getgoldnum.c >= 5)
	{
		getgold[2].u = 0.2f * getgoldnum.c;
		getgold[2].v = 0.5f;
	}
	if (getgoldnum.c >= 0)
		getgold[2].drawflag = true;
	if (getgoldnum.a <= 0 && getgoldnum.b <= 0 && getgoldnum.c <= 0)
		getgold[2].drawflag = false;
	//goldの1の位
	if (getgoldnum.d < 5)
	{
		getgold[3].u = 0.2f * getgoldnum.d;
		getgold[3].v = 0.f;
	}
	if (getgoldnum.d >= 5)
	{
		getgold[3].u = 0.2f * getgoldnum.d;
		getgold[3].v = 0.5f;
	}


}

void DrawEnemyBreak(void)
{
	if (enemybreak.drawflag == true)
	{
		DrawSpriteLeftTop(enemybreak.texture, enemybreak.pos.x, enemybreak.pos.y, enemybreak.size.x, enemybreak.size.y, 0.f, 0.f, 1.f, 1.f);

		DrawSpriteLeftTop(enemybreaktexture, getskill.pos.x, getskill.pos.y, getskill.size.x, getskill.size.y, getskill.u, 0.f, 0.0384615385f, 1.f);

		for (int i = 0; i < 4; i++)
		{
			if(getgold[i].drawflag == true)
			DrawSpriteLeftTop(getgoldnum.texture, getgold[i].pos.x, getgold[i].pos.y, getgold[i].size.x, getgold[i].size.y, getgold[i].u, getgold[i].v, 0.2f, 0.5f);
		}
	}
}

ENEMYBREAK* GetEnemyBreak(void)
{
	return &enemybreak;
}