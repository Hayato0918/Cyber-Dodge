//スキルランダム [skillrandom.cpp]
#include "skillrandom.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "player.h"
#include "map_player.h"
#include "sound.h"
#include "soundvolume_select.h"


#include <stdlib.h>
#include <time.h>

//-----マクロ定義
// 
//-----プロトタイプ宣言
SKILL skill;
RANDOM random[SKILL_NUM];

//-----グローバル変数
int t;
int skillrandomtexture;

//-----初期化処理
HRESULT InitRandom(void)
{
	skillrandomtexture = LoadTexture("data/TEXTURE/skill/skill.png");

	MAP_PLAYER* map_player = GetMapPlayer();
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	skill.sound = LoadSound("data/SE/useskill.wav");
	SetVolume(skill.sound, soundvolume_select[1].count * 0.1f + 0.5f);

	skill.usecount = 0;	//今選択されてるスキル
	skill.num = 26;		//作成済みスキルの総数

	if (map_player->UDcount == 0)
		skill.firstnum = true;
	if (map_player->UDcount > 0)
		skill.firstnum = false;

	if (skill.firstnum == true)
		skill.slot = 3;

	for (int i = 0; i < skill.num; i++)
	{
		random[i].drawflag = false;
		random[i].haveflag = false;
	}

	for (int i = 0; i < skill.slot; i++)
	{
		random[i].pos = D3DXVECTOR2(100.0f - i * 10, 120.0f - i * 10);
		random[i].size = D3DXVECTOR2(90.0f, 130.0f);
		random[i].u = 0.f;
		random[i].drawflag = true;
		random[i].active = false;
		random[i].haveflag = true;
	}

	if(skill.slot == 3)
	{
		for (int i = 0; i < skill.num; i++)
		{
			do   //重複チェック
			{
				random[i].code = (rand() % skill.num) + 1;
				for (t = 0; t < i; t++)
				{
					if (random[i].code == random[t].code)	//被りがあったらもう一度codeを割り振る
						break;
				}
			} while (i != t);
		}
	}

	random[0].code = 22;

	for (int i = 0; i < skill.slot; i++)
	{
		for (int j = 1; j < 27; j++)
		{
			if (random[i].code == j)
			{
				random[i].u = 0.0384615385f * (j - 1);
				random[i].drawflag = true;
			}
		}
	}

	return S_OK;
}

void UninitRandom(void)
{

}

void UpdateRandom(void)
{
	srand((unsigned int)time(NULL));

	PLAYER* player = GetPlayer();

	//「1」をおしたらスキル発動
	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_L) && random[skill.usecount].drawflag == true && player->skilltexturetime == 0.0f)
		{
			for (int i = 0; i < skill.slot; i++)
			{
				random[i].pos.x = random[i].pos.x + 10;
				random[i].pos.y = random[i].pos.y + 10;
			}
			PlaySound(skill.sound, 0.5f);
			random[skill.usecount].active = true;
			player->skilluseflag = true;
			random[skill.usecount].drawflag = false;
			skill.usecount = skill.usecount + 1;
		}
		//スキルを全部使い切ったら、「2」をおしてスキル復活
		if (IsButtonTriggered(0, BUTTON_L2) && skill.usecount == skill.slot)
		{
			for (int i = 0; i < skill.slot; i++)
			{
				random[i].pos = D3DXVECTOR2(100.0f - i * 10, 120.0f - i * 10);
				random[i].drawflag = true;
				random[i].active = false;
			}
			skill.usecount = 0;
		}
	}
	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_1) && random[skill.usecount].drawflag == true && player->skilltexturetime == 0.0f)
		{
			for (int i = 0; i < skill.slot; i++)
			{
				random[i].pos.x = random[i].pos.x + 10;
				random[i].pos.y = random[i].pos.y + 10;
			}
			PlaySound(skill.sound, 0.5f);
			random[skill.usecount].active = true;
			player->skilluseflag = true;
			random[skill.usecount].drawflag = false;
			skill.usecount = skill.usecount + 1;
		}
		//スキルを全部使い切ったら、「2」をおしてスキル復活
		if (GetKeyboardTrigger(DIK_2) && skill.usecount == skill.slot)
		{
			for (int i = 0; i < skill.slot; i++)
			{
				random[i].pos = D3DXVECTOR2(100.0f - i * 10, 120.0f - i * 10);
				random[i].drawflag = true;
				random[i].active = false;
			}
			skill.usecount = 0;
		}
	}



}

void DrawRandom(void)
{
	for (int i = skill.slot - 1; i >= 0; i--)
	{
		if (random[i].drawflag == true)
			DrawSpriteLeftTop(skillrandomtexture, random[i].pos.x, random[i].pos.y, random[i].size.x, random[i].size.y, random[i].u, 0.0f, 0.0384615385f, 1.0f);
	}
}

RANDOM* GetRandom()
{
	return &random[0];
}
SKILL* GetSkill()
{
	return &skill;
}