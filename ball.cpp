//ボール処理 [ball.cpp]
#include "ball.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "player.h"

//-----マクロ定義

//-----プロトタイプ宣言
BALL ball;

//-----グローバル変数

//-----初期化処理
HRESULT InitBall(void)
{
	/*ball.pos = D3DXVECTOR2(360.0f, 360.0f);*/
	ball.size = D3DXVECTOR2(60.0f, 60.0f);
	ball.move = D3DXVECTOR2(15.0f, -3.5f);
	ball.gravity = 0.03f;
	ball.texture = LoadTexture("data/TEXTURE/ball.png");
	ball.throwflag = false;
	ball.fallpos = 0.0f;

	return S_OK;
}

//-----終了処理
void UninitBall(void)
{

}

//-----更新処理
void UpdateBall(void)
{
	PLAYER* player = GetPlayer();

	if (ball.throwflag == false)
	{
		if (player->rotate == 2)
		{
			ball.pos = D3DXVECTOR2(player->pos.x - ball.size.x * 0.5, player->pos.y + player->size.y * 0.5 - ball.size.y * 0.5);
			ball.move.x = -15.0f;
		}
		if (player->rotate == 3 || player->rotate == 0 || player->rotate == 1)
		{
			ball.pos = D3DXVECTOR2(player->pos.x + ball.size.x * 0.5, player->pos.y + player->size.y * 0.5 - ball.size.y * 0.5);
			ball.move.x = 15.0f;
		}
	}
}

//-----描画処理
void DrawBall(void)
{
	DrawSpriteLeftTop(ball.texture, ball.pos.x, ball.pos.y, ball.size.x, ball.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//投げる処理
void _Throw(void)
{
	PLAYER* player = GetPlayer();

	//-----jキーで投げる
	if (GetKeyboardTrigger(DIK_L) && ball.throwflag == false)
	{
		ball.fallpos = player->pos.y + player->size.y;
		ball.throwflag = true;
	}

	//-----軌道計算
	if (ball.throwflag == true)
	{
		ball.pos += ball.move;
		ball.move.y += ball.gravity;

		//-----慣性計算
		if (ball.move.y < 0)	//上に向かう
		{
			ball.move.y += 0.02f;
			if (ball.move.y >= 0)
				ball.move.y = 0;
		}
		if (ball.move.y > 0)	//下に向かう
		{
			ball.move.y -= 0.02f;
			if (ball.move.y <= 0)
				ball.move.y = 0;
		}
		if (ball.move.x < 0)	//左に向かう
		{
			ball.move.x += 0.02f;
			if (ball.move.x >= 0)
				ball.move.x = 0;
		}
		if (ball.move.x > 0)	//右に向かう
		{
			ball.move.x -= 0.02f;
			if (ball.move.x <= 0)
				ball.move.x = 0;
		}

		//-----反射,減速計算
		if (ball.pos.y < 0.0f)							//上
			ball.move.y *= -1;
		if (ball.pos.y + ball.size.y > ball.fallpos)	//下(投げた瞬間のプレイヤーのy座標)
			ball.move.y *= -1;
		if (ball.pos.x < 0.0f)							//左
		{
			if (ball.move.x < 0)
				ball.move.x += 5.0f;
			if (ball.move.x > 0)
				ball.move.x -= 5.0f;
			ball.move.x *= -1;
		}
		if (ball.pos.x + ball.size.x > SCREEN_WIDTH)	//右
		{
			if (ball.move.x > 0)
				ball.move.x -= 5.0f;
			if (ball.move.x < 0)
				ball.move.x += 5.0f;
			ball.move.x *= -1;
		}
	}
}

BALL* GetBall()
{
	return &ball;
}