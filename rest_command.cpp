//休憩マスコマンド処理 [rest_command.cpp]
#include "rest_command.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"
#include "scene.h"
#include "sound.h"
#include <time.h>
//
#include "rest_select.h"
#include "player_hp.h"
#include "player.h"

#include "map_player.h"
#include "soundvolume_select.h"

REST_HPUP rest_hpup;
REST_STATUSUP rest_statusup;

HRESULT InitRestCommand(void)
{
	SOUNDVOLUME_SELECT * soundvolume_select = GetSoundVolumeSelect();
	PLAYERHP* player_hp = GetPlayerHp();

	rest_hpup.hp_max = player_hp->framesize.x;
	rest_statusup.random = rand() % 2;
	rest_statusup.random = 1;

	//---------- HP回復 ----------//
	rest_hpup.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.30625f, SCREEN_HEIGHT * 0.211111f);
	rest_hpup.size = D3DXVECTOR2(SCREEN_WIDTH * 0.15625f, SCREEN_HEIGHT * 0.277777f);
	rest_hpup.sound = LoadSound("data/SE/heal.wav");
	SetVolume(rest_hpup.sound, soundvolume_select[1].count * 0.1f + 0.5f);

	//---------- ステータス強化 ----------//
	rest_statusup.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5125f, SCREEN_HEIGHT * 0.211111f);
	rest_statusup.size = D3DXVECTOR2(SCREEN_WIDTH * 0.15625f, SCREEN_HEIGHT * 0.277777f);
	rest_statusup.sound = LoadSound("data/SE/powerup.wav");
	SetVolume(rest_statusup.sound, soundvolume_select[1].count * 0.1f + 0.5f);

	return S_OK;
}

void UninitRestCommand(void)
{

}

void UpdateRestCommand(void)
{
	REST_SELECT* rest_select = GetRestSelect();
	PLAYERHP* player_hp = GetPlayerHp();
	PLAYER* player = GetPlayer();
	MAP_PLAYER* map_player = GetMapPlayer();

	srand((unsigned int)time(NULL));

	if (PADUSE == 0)
	{
		if (rest_select->count == 0)	//HP回復
		{
			if (IsButtonTriggered(0, BUTTON_Y))
			{
				PlaySound(rest_hpup.sound, 0.5f);
				player_hp->gaugesize.x = player_hp->gaugesize.x + rest_hpup.hp_max / 3;
				player_hp->pos.x = player_hp->pos.x - rest_hpup.hp_max / 3;

				if (player_hp->gaugesize.x > rest_hpup.hp_max)
					player_hp->gaugesize.x = rest_hpup.hp_max;

				map_player->nextflag = true;
				SceneTransition(SCENE_MAP);
			}
		}

		if (rest_select->count == 1)
		{
			if (IsButtonTriggered(0, BUTTON_Y))
			{
				PlaySound(rest_statusup.sound, 0.5f);
				if (rest_statusup.random == 0)	//atk+10
					player->atk = player->atk + 10;
				if (rest_statusup.random == 1)	//def+10
					player->def = player->def + 10;
				map_player->nextflag = true;
				SceneTransition(SCENE_MAP);
			}
		}

	}

	if (PADUSE == 1)
	{
		if (rest_select->count == 0)	//HP回復
		{
			if (GetKeyboardTrigger(DIK_RETURN))
			{
				PlaySound(rest_hpup.sound, 0.5f);
				player_hp->gaugesize.x = player_hp->gaugesize.x + rest_hpup.hp_max / 3;
				player_hp->pos.x = player_hp->pos.x - rest_hpup.hp_max / 3;

				if (player_hp->gaugesize.x > rest_hpup.hp_max)
					player_hp->gaugesize.x = rest_hpup.hp_max;

				map_player->nextflag = true;
				SceneTransition(SCENE_MAP);
			}
		}

		if (rest_select->count == 1)
		{
			if (GetKeyboardTrigger(DIK_RETURN))
			{
				PlaySound(rest_statusup.sound, 0.5f);
				if (rest_statusup.random == 0)	//atk+10
					player->atk = player->atk + 10;
				if (rest_statusup.random == 1)	//def+10
					player->def = player->def + 10;
				map_player->nextflag = true;
				SceneTransition(SCENE_MAP);
			}
		}
	}


}

void DrawRestCommand(void)
{
	//----------HP回復----------//
	DrawSpriteLeftTop(rest_hpup.texture, rest_hpup.pos.x, rest_hpup.pos.y, rest_hpup.size.x, rest_hpup.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

	//----------ステータス強化----------//
	DrawSpriteLeftTop(rest_statusup.texture, rest_statusup.pos.x, rest_statusup.pos.y, rest_statusup.size.x, rest_statusup.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

REST_HPUP* GetRestCommandHP()
{
	return &rest_hpup;
}
REST_STATUSUP* GetRestCommandStatus()
{
	return &rest_statusup;
}