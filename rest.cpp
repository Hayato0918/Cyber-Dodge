//‹xŒeƒ}ƒXˆ— [rest.cpp]

#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "rest.h"
#include "player_hp.h"

REST rest;
RESTPOINT restpoint;

void InitRest(void)
{
	rest.pos = D3DXVECTOR2(0.0f, 0.0f);
	rest.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	rest.texture = LoadTexture("data/TEXTURE/rest_bg.png");

	restpoint.pos = D3DXVECTOR2(1180.0f, 36.0f);
	restpoint.size = D3DXVECTOR2(390.0f, 83.0f);
	restpoint.texture = LoadTexture("data/TEXTURE/rest_frame.png");
}

void UninitRest(void)
{

}

void UpdateRest(void)
{
	PLAYERHP* player_hp = GetPlayerHp();

	if (PADUSE == 0)
	{
		//‹xŒeƒ}ƒX‚Ì‘I‘ð
		if (IsButtonTriggered(0, BUTTON_UP) && restpoint.count > 0)
		{
			restpoint.pos.y -= 116;
			restpoint.count -= 1;
		}
		if (IsButtonTriggered(0, BUTTON_DOWN) && restpoint.count < 2)
		{
			restpoint.pos.y += 116;
			restpoint.count += 1;
		}
		//‘I‘ð‚µ‚½Žž‚ÌŒø‰Ê
		if (IsButtonTriggered(0, BUTTON_X) && restpoint.count == 0)
		{
			player_hp->gaugesize.x = player_hp->gaugesize.x + 100;
			player_hp->pos.x = player_hp->pos.x - 100;
			SceneTransition(SCENE_MAP);
		}
		if (IsButtonTriggered(0, BUTTON_X) && 1 < restpoint.count < 2)
			SceneTransition(SCENE_MAP);
	}
	if (PADUSE == 1)
	{
		//‹xŒeƒ}ƒX‚Ì‘I‘ð
		if (GetKeyboardTrigger(DIK_W) && restpoint.count > 0)
		{
			restpoint.pos.y -= 116;
			restpoint.count -= 1;
		}
		if (GetKeyboardTrigger(DIK_S) && restpoint.count < 2)
		{
			restpoint.pos.y += 116;
			restpoint.count += 1;
		}
		//‘I‘ð‚µ‚½Žž‚ÌŒø‰Ê
		if (GetKeyboardTrigger(DIK_RETURN) && restpoint.count == 0)
		{
			player_hp->gaugesize.x = player_hp->gaugesize.x + 100;
			player_hp->pos.x = player_hp->pos.x - 100;
			SceneTransition(SCENE_MAP);
		}
		if (GetKeyboardTrigger(DIK_RETURN) && 1 < restpoint.count < 2)
			SceneTransition(SCENE_MAP);
	}
}

void DrawRest(void)
{
	DrawSpriteLeftTop(rest.texture, rest.pos.x, rest.pos.y, rest.size.x, rest.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

	DrawSpriteLeftTop(restpoint.texture, restpoint.pos.x, restpoint.pos.y, restpoint.size.x, restpoint.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}