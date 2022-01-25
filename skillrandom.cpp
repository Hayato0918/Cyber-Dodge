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

//-----初期化処理
HRESULT InitRandom(void)
{
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

	for (int i = 0; i < skill.slot; i++)
	{
		//割り当てられたcodeに対応したテクスチャを表示
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
			random[i].texture = LoadTexture("data/TEXTURE/skill/penetration.png");
		if (random[i].code == 12)
			random[i].texture = LoadTexture("data/TEXTURE/skill/rockcreate.png");
		if (random[i].code == 13)
			random[i].texture = LoadTexture("data/TEXTURE/skill/slowarea.png");
		if (random[i].code == 14)
			random[i].texture = LoadTexture("data/TEXTURE/skill/smallplayer.png");
		//if (random[i].code == 15)
		//	random[i].texture = LoadTexture("data/TEXTURE/skill/autocatch.png");
		if (random[i].code == 16)
			random[i].texture = LoadTexture("data/TEXTURE/skill/disappear.png");
		if (random[i].code == 17)
			random[i].texture = LoadTexture("data/TEXTURE/skill/doubleattack.png");
		if (random[i].code == 18)
			random[i].texture = LoadTexture("data/TEXTURE/skill/enemy_powerdown.png");
		if (random[i].code == 19)
			random[i].texture = LoadTexture("data/TEXTURE/skill/landmine.png");
		if (random[i].code == 20)
			random[i].texture = LoadTexture("data/TEXTURE/skill/mindhack.png");
		if (random[i].code == 21)
			random[i].texture = LoadTexture("data/TEXTURE/skill/otoshiana.png");
		if (random[i].code == 22)
			random[i].texture = LoadTexture("data/TEXTURE/skill/player_powerup.png");
		if (random[i].code == 23)
			random[i].texture = LoadTexture("data/TEXTURE/skill/player_regen.png");
		if (random[i].code == 24)
			random[i].texture = LoadTexture("data/TEXTURE/skill/player_speedup.png");
		if (random[i].code == 25)
			random[i].texture = LoadTexture("data/TEXTURE/skill/timestop.png");
		if (random[i].code == 26)
			random[i].texture = LoadTexture("data/TEXTURE/skill/warp.png");
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

	for (int i = 0; i < skill.slot; i++)
	{
		//割り当てられたcodeに対応したテクスチャを表示
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
			random[i].texture = LoadTexture("data/TEXTURE/skill/penetration.png");
		if (random[i].code == 12)
			random[i].texture = LoadTexture("data/TEXTURE/skill/rockcreate.png");
		if (random[i].code == 13)
			random[i].texture = LoadTexture("data/TEXTURE/skill/slowarea.png");
		if (random[i].code == 14)
			random[i].texture = LoadTexture("data/TEXTURE/skill/smallplayer.png");
		//if (random[i].code == 15)
		//	random[i].texture = LoadTexture("data/TEXTURE/skill/autocatch.png");
		if (random[i].code == 16)
			random[i].texture = LoadTexture("data/TEXTURE/skill/disappear.png");
		if (random[i].code == 17)
			random[i].texture = LoadTexture("data/TEXTURE/skill/doubleattack.png");
		if (random[i].code == 18)
			random[i].texture = LoadTexture("data/TEXTURE/skill/enemy_powerdown.png");
		if (random[i].code == 19)
			random[i].texture = LoadTexture("data/TEXTURE/skill/landmine.png");
		if (random[i].code == 20)
			random[i].texture = LoadTexture("data/TEXTURE/skill/mindhack.png");
		if (random[i].code == 21)
			random[i].texture = LoadTexture("data/TEXTURE/skill/otoshiana.png");
		if (random[i].code == 22)
			random[i].texture = LoadTexture("data/TEXTURE/skill/player_powerup.png");
		if (random[i].code == 23)
			random[i].texture = LoadTexture("data/TEXTURE/skill/player_regen.png");
		if (random[i].code == 24)
			random[i].texture = LoadTexture("data/TEXTURE/skill/player_speedup.png");
		if (random[i].code == 25)
			random[i].texture = LoadTexture("data/TEXTURE/skill/timestop.png");
		if (random[i].code == 26)
			random[i].texture = LoadTexture("data/TEXTURE/skill/warp.png");
	}

}

void DrawRandom(void)
{
	for (int i = skill.slot - 1; i >= 0; i--)
	{
		if (random[i].drawflag == true)
			DrawSpriteLeftTop(random[i].texture, random[i].pos.x, random[i].pos.y, random[i].size.x, random[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
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