//同業者の失敗処理 [dougyousya.cpp]

#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "dougyousya.h"
#include "map_player.h"

DOUGYOUSYA dougyousya;
DOUGYOUSYAPOINT dougyousyapoint;

void InitDougyousya(void)
{
	dougyousya.pos = D3DXVECTOR2(0.0f, 0.0f);
	dougyousya.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

	dougyousyapoint.pos = D3DXVECTOR2(825.0f, 766.0f);
	dougyousyapoint.size = D3DXVECTOR2(690.0f, 90.0f);
}

void UninitDougyousya(void)
{

}

void UpdateDougyousya(void)
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

void DrawDougyousya(void)
{
	DrawSpriteLeftTop(dougyousya.texture, dougyousya.pos.x, dougyousya.pos.y, dougyousya.size.x, dougyousya.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

	DrawSpriteLeftTop(dougyousyapoint.texture, dougyousyapoint.pos.x, dougyousyapoint.pos.y, dougyousyapoint.size.x, dougyousyapoint.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}


DOUGYOUSYA* GetDougyousya()
{
	return &dougyousya;
}
DOUGYOUSYAPOINT* GetDougyousyaPoint()
{
	return &dougyousyapoint;
}