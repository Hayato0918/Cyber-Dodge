//イベント_サーバー安定処理 [server_recovery.cpp]

#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "server_recovery.h"
#include "bugincrease.h"
#include "banner_bug.h"
#include "map_player.h"

SERVER_RECOVERY server_recovery;
SERVER_POINT server_point;

void InitServerRecovery(void)
{
	BUG* bug = GetBugIncrease();
	BUGGAUGE* buggauge = GetBugGauge();
	BANNER_BUGNUM* banner_bugnum = GetBannerBug();

	server_recovery.pos = D3DXVECTOR2(0.0f, 0.0f);
	server_recovery.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	server_recovery.texture = LoadTexture("data/TEXTURE/server_recovery_bg.png");

	server_point.pos = D3DXVECTOR2(825.0f, 766.0f);
	server_point.size = D3DXVECTOR2(690.0f, 90.0f);
	server_point.texture = LoadTexture("data/TEXTURE/rest_frame.png");

	for (int i = bug->drawnum; i > 0; i--)
	{
		buggauge[bug->drawnum].drawflag = false;
		banner_bugnum->bugnum = banner_bugnum->bugnum - 5;
		bug->drawnum = bug->drawnum - 1;
	}

}

void UninitServerRecovery(void)
{

}

void UpdateServerRecovery(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	//エンターキーでマップへ戻る
	if (PADUSE == 0)
	{
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

void DrawServerRecovery(void)
{
	DrawSpriteLeftTop(server_recovery.texture, server_recovery.pos.x, server_recovery.pos.y, server_recovery.size.x, server_recovery.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

	DrawSpriteLeftTop(server_point.texture, server_point.pos.x, server_point.pos.y, server_point.size.x, server_point.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}