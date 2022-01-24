//仮想研究空間 [event_kasoukenkyuukuukan.cpp]

#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "kasoukenkyuukuukan.h"
#include "player.h"

#include "map_player.h"

KASOU kasou;
KASOUPOINT kasoupoint;

void InitKasou(void)
{
	kasou.pos = D3DXVECTOR2(0.0f, 0.0f);
	kasou.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	kasou.texture = LoadTexture("data/TEXTURE/kasou.png");

	kasoupoint.pos = D3DXVECTOR2(810.0f, 750.0f);
	kasoupoint.size = D3DXVECTOR2(350.0f, 83.0f);
	kasoupoint.texture = LoadTexture("data/TEXTURE/rest_frame.png");
	kasoupoint.count = 0;
}

void UninitKasou(void)
{

}

void UpdateKasou(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();
	PLAYER* player = GetPlayer();

	if (PADUSE == 0)
	{
		//休憩マスの選択
		if (IsButtonTriggered(0, BUTTON_LEFT) && kasoupoint.count == 1)
		{
			kasoupoint.pos = D3DXVECTOR2(810.0f, 750.0f);
			kasoupoint.count -= 1;
		}
		if (IsButtonTriggered(0, BUTTON_RIGHT) && kasoupoint.count == 0)
		{
			kasoupoint.pos = D3DXVECTOR2(1160.0f, 750.0f);
			kasoupoint.count += 1;
		}
		//選択した時の効果
		if (IsButtonTriggered(0, BUTTON_X) && kasoupoint.count == 0)
		{
			player->def = player->def - 20;
			player->atk = player->atk + 40;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
		if (IsButtonTriggered(0, BUTTON_X) && kasoupoint.count == 1)
		{
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
	}
	if (PADUSE == 1)
	{
		//選択肢A
		if (GetKeyboardTrigger(DIK_A) && kasoupoint.count == 1)
		{
			kasoupoint.pos = D3DXVECTOR2(810.0f, 750.0f);
			kasoupoint.count -= 1;
		}
		//選択肢B
		if (GetKeyboardTrigger(DIK_D) && kasoupoint.count == 0)
		{
			kasoupoint.pos = D3DXVECTOR2(1160.0f, 750.0f);
			kasoupoint.count += 1;
		}
		//選択した時の効果
		if (GetKeyboardTrigger(DIK_RETURN) && kasoupoint.count == 0)
		{
			player->def = player->def - 20;
			player->atk = player->atk + 40;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
		if (GetKeyboardTrigger(DIK_RETURN) && kasoupoint.count == 1)
		{
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
	}
}

void DrawKasou(void)
{
	DrawSpriteLeftTop(kasou.texture, kasou.pos.x, kasou.pos.y, kasou.size.x, kasou.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	DrawSpriteLeftTop(kasoupoint.texture, kasoupoint.pos.x, kasoupoint.pos.y, kasoupoint.size.x, kasoupoint.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}