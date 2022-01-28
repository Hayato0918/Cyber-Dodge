//蘇る増幅装置処理 [yomigaeru.cpp]

#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "yomigaeru.h"
#include "player_hp.h"
#include "player.h"
#include "map_player.h"

YOMIGAERU yomigaeru;
YOMIGAERUPOINT yomigaerupoint;

void InitYomigaeru(void)
{
	yomigaeru.pos = D3DXVECTOR2(0.0f, 0.0f);
	yomigaeru.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

	yomigaerupoint.pos = D3DXVECTOR2(825.0f, 663.0f);
	yomigaerupoint.size = D3DXVECTOR2(690.0f, 90.0f);
	yomigaerupoint.count = 0;
	yomigaerupoint.minus = 103;
}

void UninitYomigaeru(void)
{

}

void UpdateYomigaeru(void)
{
	PLAYER* player = GetPlayer();
	MAP_PLAYER* map_player = GetMapPlayer();

	if (PADUSE == 0)
	{
		//選択肢の選択
		if (IsButtonTriggered(0, BUTTON_UP) && yomigaerupoint.count > 0)
		{
			yomigaerupoint.pos.y -= yomigaerupoint.minus;
			yomigaerupoint.count -= 1;
		}
		if (IsButtonTriggered(0, BUTTON_DOWN) && yomigaerupoint.count < 1)
		{
			yomigaerupoint.pos.y += yomigaerupoint.minus;
			yomigaerupoint.count += 1;
		}
		//選択した時の効果
		if (IsButtonTriggered(0, BUTTON_Y) && yomigaerupoint.count == 0)
		{
			player->atk *= 1.2f;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
		if (IsButtonTriggered(0, BUTTON_Y) && yomigaerupoint.count == 1)
		{
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
	}
	if (PADUSE == 1)
	{
		//選択肢の選択
		if (GetKeyboardTrigger(DIK_W) && yomigaerupoint.count > 0)
		{
			yomigaerupoint.pos.y -= yomigaerupoint.minus;
			yomigaerupoint.count -= 1;
		}
		if (GetKeyboardTrigger(DIK_S) && yomigaerupoint.count < 1)
		{
			yomigaerupoint.pos.y += yomigaerupoint.minus;
			yomigaerupoint.count += 1;
		}
		//選択した時の効果
		//プレイヤーの攻撃力を1.2倍にする
		if (GetKeyboardTrigger(DIK_RETURN) && yomigaerupoint.count == 0)
		{
			player->atk *= 1.2f;
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
		if (GetKeyboardTrigger(DIK_RETURN) && yomigaerupoint.count == 1)
		{
			map_player->nextflag = true;
			SceneTransition(SCENE_MAP);
		}
	}
}

void DrawYomigaeru(void)
{
	DrawSpriteLeftTop(yomigaeru.texture, yomigaeru.pos.x, yomigaeru.pos.y, yomigaeru.size.x, yomigaeru.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

	DrawSpriteLeftTop(yomigaerupoint.texture, yomigaerupoint.pos.x, yomigaerupoint.pos.y, yomigaerupoint.size.x, yomigaerupoint.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

YOMIGAERU* GetYomi()
{
	return &yomigaeru;
}
YOMIGAERUPOINT* GetPomiPoint()
{
	return &yomigaerupoint;
}