//スキルランダム [skillrandom.cpp]
#include "skillrandom.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include <stdlib.h>
#include <time.h>

//-----マクロ定義
// 
//-----プロトタイプ宣言
static RANDOM random[MAX_SLOT];
SKILL skill;

//-----グローバル変数

//-----初期化処理
HRESULT InitRandom(void)
{
	skill.usecount = 0;
	skill.num = 12;

	for (int i = 0; i < MAX_SLOT; i++)
	{
		//skill card position
		random[i].pos = D3DXVECTOR2(100.0f - i * 10, 120.0f - i * 10);
		random[i].size = D3DXVECTOR2(90.0f, 130.0f);
		random[i].drawflag = true;

		random[i].code = (rand() % skill.num) + 1;
		random[i].active = false;
	}

	return S_OK;
}

void UninitRandom(void)
{

}

void UpdateRandom(void)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < MAX_SLOT; i++)
	{
		if (random[i].code == 1)
			random[i].texture = LoadTexture("data/TEXTURE/skill/speedup.png");
		if (random[i].code == 2)
			random[i].texture = LoadTexture("data/TEXTURE/skill/turnaround.png");
		if (random[i].code == 3)
			random[i].texture = LoadTexture("data/TEXTURE/skill/barrier.png");
		if (random[i].code == 4)
			random[i].texture = LoadTexture("data/TEXTURE/skill/baseball.png");
		if (random[i].code == 5)
			random[i].texture = LoadTexture("data/TEXTURE/skill/bigball.png");
		if (random[i].code == 6)
			random[i].texture = LoadTexture("data/TEXTURE/skill/billiards.png");
		if (random[i].code == 7)
			random[i].texture = LoadTexture("data/TEXTURE/skill/buildup.png");
		if (random[i].code == 8)
			random[i].texture = LoadTexture("data/TEXTURE/skill/catchjamming.png");
		if (random[i].code == 9)
			random[i].texture = LoadTexture("data/TEXTURE/skill/invade.png");
		if (random[i].code == 10)
			random[i].texture = LoadTexture("data/TEXTURE/skill/invincible.png");
		if (random[i].code == 11)
			random[i].texture = LoadTexture("data/TEXTURE/skill/slowarea.png");
		if (random[i].code == 12)
			random[i].texture = LoadTexture("data/TEXTURE/skill/smallplayer.png");

		if (GetKeyboardTrigger(DIK_1) && random[skill.usecount].drawflag == true)
		{
			random[skill.usecount].active = true;
			random[skill.usecount].drawflag = false;
		}
		if (random[skill.usecount].drawflag == false)
			random[skill.usecount].usetime = random[skill.usecount].usetime + 1.f;
		if (random[skill.usecount].usetime > 10.f)
			skill.usecount = skill.usecount + 1;
	}
}

void DrawRandom(void)
{
	for (int i = MAX_SLOT - 1; i >= 0; i--)
	{
		if (random[i].drawflag == true)
			DrawSpriteLeftTop(random[i].texture, random[i].pos.x, random[i].pos.y, random[i].size.x, random[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
}

RANDOM* GetRandom()
{
	return &random[0];
}