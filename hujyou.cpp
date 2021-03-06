//浮遊情報体処理 [hujyou.cpp]

#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"
#include "map_player.h"
#include "hujyou.h"

HUJYOU hujyou;
HUJYOUPOINT hujyoupoint;

void InitHujyou(void)
{
	hujyou.pos = D3DXVECTOR2(0.0f, 0.0f);
	hujyou.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

	hujyoupoint.pos = D3DXVECTOR2(825.0f, 766.0f);
	hujyoupoint.size = D3DXVECTOR2(690.0f, 90.0f);
}

void UninitHujyou(void)
{

}

void UpdateHujyou(void)
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

void DrawHujyou(void)
{
	DrawSpriteLeftTop(hujyou.texture, hujyou.pos.x, hujyou.pos.y, hujyou.size.x, hujyou.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

	DrawSpriteLeftTop(hujyoupoint.texture, hujyoupoint.pos.x, hujyoupoint.pos.y, hujyoupoint.size.x, hujyoupoint.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

HUJYOU* GetHujyou()
{
	return &hujyou;
}
HUJYOUPOINT* GetHujyouPoint()
{
	return &hujyoupoint;
}