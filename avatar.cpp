//アバターの残骸処理 [avatar.cpp]

#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "avatar.h"
#include "player_hp.h"
#include "player.h"

#include "map_player.h"

AVATAR avatar;
AVATARPOINT avatarpoint;

void InitAvatar(void)
{
	avatar.pos = D3DXVECTOR2(0.0f, 0.0f);
	avatar.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	avatar.texture = LoadTexture("data/TEXTURE/event_bg/avatar_bg.png");

	avatarpoint.pos = D3DXVECTOR2(825.0f, 560.0f);
	avatarpoint.size = D3DXVECTOR2(690.0f, 90.0f);
	avatarpoint.texture = LoadTexture("data/TEXTURE/rest_frame.png");
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
		//選択肢の選択
		if (IsButtonTriggered(0, BUTTON_UP) && avatarpoint.count > 0)
		{
			avatarpoint.pos.y -= avatarpoint.minus;
			avatarpoint.count -= 1;
		}
		if (IsButtonTriggered(0, BUTTON_DOWN) && avatarpoint.count < 2)
		{
			avatarpoint.pos.y += avatarpoint.minus;
			avatarpoint.count += 1;
		}
		//選択した時の効果
		if (IsButtonTriggered(0, BUTTON_X) && avatarpoint.count == 0)
		{
			player_hp->framesize.x += 30 * 3.2f;
			player_hp->framepos.x -= 30 * 3.2f;
			player_hp->gaugesize.x = player_hp->gaugesize.x + 30 * 3.2f;
			player_hp->pos.x = player_hp->pos.x - 30 * 3.2f;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
		if (IsButtonTriggered(0, BUTTON_X) && avatarpoint.count == 1)
		{
			player->atk += 20;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
		if (IsButtonTriggered(0, BUTTON_X) && avatarpoint.count == 2)
		{
			player->def += 10;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
	}
	if (PADUSE == 1)
	{
		//選択肢の選択
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
		//選択した時の効果
		//HP及び最大HPを+50する
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
		//プレイヤーの攻撃力を+20する
		if (GetKeyboardTrigger(DIK_RETURN) && avatarpoint.count == 1)
		{
			player->atk += 20;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
		//プレイヤーの防御力を+10する
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