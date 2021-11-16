//スキル_ベースボール処理 [baseball.cpp]
#include "baseball.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "player.h"
#include "ball.h"

//-----マクロ定義
#define swingtime	180						//バットの判定時間
#define PI 3.1415926535897932				//円周率


//-----グローバル変数
BASEBALL baseball;

HRESULT InitBaseball(void)
{
	baseball.pos = D3DXVECTOR2(0.0f, 0.0f);
	baseball.size = D3DXVECTOR2(20.0f, 120.0f);
	baseball.use = false;
	baseball.timeflag = false;
	baseball.time = 0.0f;

	baseball.texture = LoadTexture("data/TEXTURE/bat.png");

	return S_OK;
}

void _Baseball(void)
{
	//5キーが押されたら処理を開始。
	//玉を持っていない間バットを一定時間表示、その間玉を一定の速度で打ち出すような処理を行います。

	BALL* ball = GetBall();

	//スキルが使えるかの判断
	if (GetKeyboardTrigger(DIK_0) && baseball.use == false && ball->playerhaveflag == false)
	{
		baseball.timeflag = true;
		baseball.use = true;
	}

	PLAYER* player = GetPlayer();

	//バットを振っている最中の処理
	if (baseball.timeflag == true)
	{
		if (player->rotate == 3) // 右向き
		{
			baseball.pos = D3DXVECTOR2(player->pos.x + player->size.x, player->pos.y);// バットの描画位置
		}
		if (player->rotate == 2) // 左向き
		{
			baseball.pos = D3DXVECTOR2(player->pos.x - baseball.size.x, player->pos.y);// バットの描画位置
		}

		//当たり判定処理
		if (baseball.pos.x + baseball.size.x > ball->pos.x && baseball.pos.x < ball->pos.x + ball->size.x)
		{
			if (baseball.pos.y + baseball.size.y > ball->pos.y && baseball.pos.y < ball->pos.y + ball->size.y)
			{
				if (player->rotate == 3) // 右向き
				{
					AddBallMove(-5.0f, PI * 0.05, player->pos.y, player->size.y);
				}
				if (player->rotate == 2) // 左向き
				{
					AddBallMove(-5.0f, PI * 0.95, player->pos.y, player->size.y);
				}
			}
		}

		baseball.time = baseball.time + 1.0f;
	}

	//バットを振り切ったかの判断
	if (baseball.time > swingtime)
	{
		baseball.timeflag = false;
		baseball.time = 0.0f;
	}
}

void DrawBaseball(void)
{
	if (baseball.timeflag == true)
		//描画処理
		DrawSpriteLeftTop(baseball.texture, baseball.pos.x, baseball.pos.y, baseball.size.x, baseball.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}