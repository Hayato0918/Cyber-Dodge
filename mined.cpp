//マインドブルーム処理 [mined.cpp]

#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"
#include "map_player.h"
#include "mined.h"

MINED mined;
MINEDPOINT minedpoint;

void InitMined(void)
{
	mined.pos = D3DXVECTOR2(0.0f, 0.0f);
	mined.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	mined.texture = LoadTexture("data/TEXTURE/event_bg/mined_bg.png");

	minedpoint.pos = D3DXVECTOR2(825.0f, 766.0f);
	minedpoint.size = D3DXVECTOR2(690.0f, 90.0f);
	minedpoint.texture = LoadTexture("data/TEXTURE/rest_frame.png");
}

void UninitMined(void)
{

}

void UpdateMined(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (PADUSE == 0)
	{
		//選択した時の効果
		if (IsButtonTriggered(0, BUTTON_Y))
		{
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
	}
	if (PADUSE == 1)
	{

		if (GetKeyboardTrigger(DIK_RETURN))
		{
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
	}
}

void DrawMined(void)
{
	DrawSpriteLeftTop(mined.texture, mined.pos.x, mined.pos.y, mined.size.x, mined.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

	DrawSpriteLeftTop(minedpoint.texture, minedpoint.pos.x, minedpoint.pos.y, minedpoint.size.x, minedpoint.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}