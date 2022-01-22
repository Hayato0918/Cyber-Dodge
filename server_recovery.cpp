//イベント_サーバー安定処理 [server_recovery.cpp]

#include "map.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "fade.h"

#include "server_recovery.h"
#include "bugincrease.h"

SERVER_RECOVERY server_recovery;
SERVER_POINT server_point;

void InitServerRecovery(void)
{
	BUG* bug = GetBugIncrease();

	server_recovery.pos = D3DXVECTOR2(0.0f, 0.0f);
	server_recovery.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	server_recovery.texture = LoadTexture("data/TEXTURE/server_recovery_bg.png");

	server_point.pos = D3DXVECTOR2(900.0f, 800.0f);
	server_point.size = D3DXVECTOR2(260.0f, 80.0f);
	server_point.texture = LoadTexture("data/TEXTURE/rest_frame.png");

	bug->gaugesize.x = 0.0f; //	バグゲージを0に戻す

}

void UninitServerRecovery(void)
{

}

void UpdateServerRecovery(void)
{

	//エンターキーでマップへ戻る
	if (GetKeyboardTrigger(DIK_RETURN))
	{
		SceneTransition(SCENE_MAP);
	}
}

void DrawServerRecovery(void)
{
	DrawSpriteLeftTop(server_recovery.texture, server_recovery.pos.x, server_recovery.pos.y, server_recovery.size.x, server_recovery.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

	DrawSpriteLeftTop(server_point.texture, server_point.pos.x, server_point.pos.y, server_point.size.x, server_point.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}