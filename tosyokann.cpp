//電脳図書館処理 [tosyokann.cpp]

#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "tosyokann.h"
#include "player_hp.h"
#include "player.h"
#include "map_player.h"

TOSYOKANN tosyokann;
TOSYOKANNPOINT tosyokannpoint;

void InitTosyokann(void)
{
	tosyokann.pos = D3DXVECTOR2(0.0f, 0.0f);
	tosyokann.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

	tosyokannpoint.pos = D3DXVECTOR2(825.0f, 663.0f);
	tosyokannpoint.size = D3DXVECTOR2(690.0f, 90.0f);
	tosyokannpoint.count = 0;
	tosyokannpoint.minus = 103;
}

void UninitTosyokann(void)
{

}

void UpdateTosyokann(void)
{
	PLAYERHP* player_hp = GetPlayerHp();
	PLAYER* player = GetPlayer();
	MAP_PLAYER* map_player = GetMapPlayer();

	if (PADUSE == 0)
	{
		//選択肢の選択
		if (IsButtonTriggered(0, BUTTON_UP) && tosyokannpoint.count > 0)
		{
			tosyokannpoint.pos.y -= tosyokannpoint.minus;
			tosyokannpoint.count -= 1;
		}
		if (IsButtonTriggered(0, BUTTON_DOWN) && tosyokannpoint.count < 1)
		{
			tosyokannpoint.pos.y += tosyokannpoint.minus;
			tosyokannpoint.count += 1;
		}
		//選択した時の効果
		//プレイヤーの防御力を10増やす
		if (IsButtonTriggered(0, BUTTON_Y) && tosyokannpoint.count == 0)
		{
			player->def += 10;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
		//プレイヤーのHPを初期状態まで回復する
		if (IsButtonTriggered(0, BUTTON_Y) && tosyokannpoint.count == 1)
		{
			player_hp->gaugesize.x = player_hp->framesize.x;
			player_hp->pos.x = player_hp->framepos.x;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
	}
	if (PADUSE == 1)
	{
		//選択肢の選択
		if (GetKeyboardTrigger(DIK_W) && tosyokannpoint.count > 0)
		{
			tosyokannpoint.pos.y -= tosyokannpoint.minus;
			tosyokannpoint.count -= 1;
		}
		if (GetKeyboardTrigger(DIK_S) && tosyokannpoint.count < 1)
		{
			tosyokannpoint.pos.y += tosyokannpoint.minus;
			tosyokannpoint.count += 1;
		}
		//選択した時の効果
		//プレイヤーの防御力を10増やす
		if (GetKeyboardTrigger(DIK_RETURN) && tosyokannpoint.count == 0)
		{
			player->def += 10;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
		//プレイヤーのHPを初期状態まで回復する
		if (GetKeyboardTrigger(DIK_RETURN) && tosyokannpoint.count == 1)
		{
			player_hp->gaugesize.x = player_hp->framesize.x;
			player_hp->pos.x = player_hp->saidai_pos.x;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
	}
}

void DrawTosyokann(void)
{
	DrawSpriteLeftTop(tosyokann.texture, tosyokann.pos.x, tosyokann.pos.y, tosyokann.size.x, tosyokann.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

	DrawSpriteLeftTop(tosyokannpoint.texture, tosyokannpoint.pos.x, tosyokannpoint.pos.y, tosyokannpoint.size.x, tosyokannpoint.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

TOSYOKANN* GetTosyo()
{
	return &tosyokann;
}
TOSYOKANNPOINT* GetTosyPoint()
{
	return &tosyokannpoint;
}