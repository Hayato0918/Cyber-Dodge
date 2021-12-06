//バグゲージ処理 [bug.cpp]
#include "bug.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "ball.h"
#include "map_point.h"

//-----マクロ定義
#define gaugedecrease 0.2f	//ゲージの減少量
#define gaugeincrease 4.0f  //ゲージ増加量
#define gaugeincreasetime 300

//-----プロトタイプ宣言
BUG bug;

//-----グローバル変数

//-----初期化処理
HRESULT InitBug(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->gamecount == 1)
	{
		bug.gaugeonce = 8;
		bug.pos = D3DXVECTOR2(105.0f, 20.0f);
		bug.framesize = D3DXVECTOR2(150.f * bug.gaugeonce, 60);
		bug.frametexture = LoadTexture("data/TEXTURE/bugframe.png");

		bug.gaugesize = D3DXVECTOR2(0.0f, bug.framesize.y);
		bug.gaugetexture = LoadTexture("data/TEXTURE/obstacle.png");
	}

	return S_OK;
}

//-----終了処理
void UninitBug(void)
{

}

//-----更新処理
void UpdateBug(void)
{
	PLAYER* player = GetPlayer();
	BALL* ball = GetBall();

	//-----プレイヤーがボールを持ち続けている時間が一定以上になったら、バグゲージを増やす
	if (ball->playerhaveflag == true)
	{
		ball->playerhavetime = ball->playerhavetime + 1.0f;
		if (ball->playerhavetime >= gaugeincreasetime && bug.gaugesize.x < 150.f * bug.gaugeonce)
			bug.gaugesize.x = bug.gaugesize.x + gaugeincrease;
		else if (bug.gaugesize.x >= 150.f * bug.gaugeonce)
		{
			bug.gaugesize.x = 150.f * bug.gaugeonce;
		}
	}

	//-----時間経過によるゲージの減少
	if (ball->playerhaveflag == false || ball->playerhavetime < gaugeincreasetime)
	{
		if (bug.gaugesize.x >= 0)
			bug.gaugesize.x = bug.gaugesize.x - gaugedecrease;
	}
}

//-----描画処理
void DrawBug(void)
{
	//-----バグゲージの描画
	DrawSpriteLeftTop(bug.gaugetexture, bug.pos.x, bug.pos.y, bug.gaugesize.x, bug.gaugesize.y, 0.0f, 0.0f, 1.0f, 1.0f);

	//-----バグゲージの枠の描画
	DrawSpriteLeftTop(bug.frametexture, bug.pos.x, bug.pos.y, bug.framesize.x, bug.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----構造体ポインタ取得処理
BUG* GetBug()
{
	return &bug;
}