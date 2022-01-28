//�A�o�^�[�̎c�[���� [avatar.cpp]

#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "soundvolume_select.h" 

#include "avatar.h"
#include "player_hp.h"
#include "player.h"

#include "map_player.h"

AVATAR avatar;
AVATARPOINT avatarpoint;

void InitAvatar(void)
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();
	avatar.sound = LoadSound("data/SE/cursormove.wav");
	SetVolume(avatar.sound, soundvolume_select[1].count * 0.1f + 0.5f);

	avatar.pos = D3DXVECTOR2(0.0f, 0.0f);
	avatar.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

	avatarpoint.pos = D3DXVECTOR2(825.0f, 560.0f);
	avatarpoint.size = D3DXVECTOR2(690.0f, 90.0f);
	avatarpoint.count = 0;
	avatarpoint.minus = 103;
}

void UninitAvatar(void)
{

}

void UpdateAvatar(void)
{
	PLAYERHP* player_hp = GetPlayerHp();
	PLAYER* player = GetPlayer();
	MAP_PLAYER* map_player = GetMapPlayer();

	if (PADUSE == 0)
	{
		//�I�����̑I��
		if (IsButtonTriggered(0, BUTTON_UP) && avatarpoint.count > 0)
		{
			PlaySound(avatar.sound, 0.5f);
			avatarpoint.pos.y -= avatarpoint.minus;
			avatarpoint.count -= 1;
		}
		if (IsButtonTriggered(0, BUTTON_DOWN) && avatarpoint.count < 2)
		{
			PlaySound(avatar.sound, 0.5f);
			avatarpoint.pos.y += avatarpoint.minus;
			avatarpoint.count += 1;
		}
		//�I���������̌���
		if (IsButtonTriggered(0, BUTTON_Y) && avatarpoint.count == 0)
		{
			player_hp->framesize.x += 30 * 3.2f;
			player_hp->framepos.x -= 30 * 3.2f;
			player_hp->gaugesize.x = player_hp->gaugesize.x + 30 * 3.2f;
			player_hp->pos.x = player_hp->pos.x - 30 * 3.2f;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
		if (IsButtonTriggered(0, BUTTON_Y) && avatarpoint.count == 1)
		{
			player->atk += 20;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
		if (IsButtonTriggered(0, BUTTON_Y) && avatarpoint.count == 2)
		{
			player->def += 10;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
	}
	if (PADUSE == 1)
	{
		//�I�����̑I��
		if (GetKeyboardTrigger(DIK_W) && avatarpoint.count > 0)
		{
			avatarpoint.pos.y -= avatarpoint.minus;
			avatarpoint.count -= 1;
		}
		if (GetKeyboardTrigger(DIK_S) && avatarpoint.count < 2)
		{
			avatarpoint.pos.y += avatarpoint.minus;
			avatarpoint.count += 1;
		}
		//�I���������̌���
		//HP�y�эő�HP��+50����
		if (GetKeyboardTrigger(DIK_RETURN) && avatarpoint.count == 0)
		{
			player_hp->framesize.x += 30;
			player_hp->framepos.x -= 30;
			player_hp->gaugesize.x = player_hp->gaugesize.x + 30;
			player_hp->pos.x = player_hp->pos.x - 30;
			player_hp->saidai_pos.x = player_hp->pos.x - 30;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
		//�v���C���[�̍U���͂�+20����
		if (GetKeyboardTrigger(DIK_RETURN) && avatarpoint.count == 1)
		{
			player->atk += 20;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
		//�v���C���[�̖h��͂�+10����
		if (GetKeyboardTrigger(DIK_RETURN) && avatarpoint.count == 2)
		{
			player->def += 10;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
	}
}

void DrawAvatar(void)
{
	DrawSpriteLeftTop(avatar.texture, avatar.pos.x, avatar.pos.y, avatar.size.x, avatar.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

	DrawSpriteLeftTop(avatarpoint.texture, avatarpoint.pos.x, avatarpoint.pos.y, avatarpoint.size.x, avatarpoint.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

AVATAR* GetAvaret()
{
	return &avatar;
}

AVATARPOINT* GetAvatarPoint()
{
	return &avatarpoint;
}
