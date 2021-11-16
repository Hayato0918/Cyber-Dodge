//ボール処理 [ball.cpp]
#include "ball.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "player.h"
#include "enemy.h"
#include "invincible.h"

//-----マクロ定義

//-----プロトタイプ宣言
BALL ball;

//-----グローバル変数

//-----初期化処理
HRESULT InitBall(void)
{
	ball.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, 360.0f);
	ball.size = D3DXVECTOR2(60.0f, 60.0f);
	ball.move = D3DXVECTOR2(5.0f, -2.5f);
	ball.startmove = D3DXVECTOR2(5.0f, -2.5f);
	ball.throwway = 1;
	ball.gravity = 0.03f;
	ball.texture = LoadTexture("data/TEXTURE/ball.png");
	ball.throwflag = false;
	ball.fallpos = 0.0f;
	ball.playerhavetime = 0.0f;
	ball.playerhaveflag = false;
	ball.playerhitflag = false;
	ball.enemyhaveflag = false;
	ball.enemyhitflag = false;

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
	ENEMY* enemy = GetEnemy();

	//-----ボールの座標を決める(Player)
	if (ball.throwflag == false && ball.playerhaveflag == true)		//ボールが飛んでいないとき&&プレイヤーが持ってるとき
	{
		if (player->rotate == 2)
		{
			ball.pos = D3DXVECTOR2(player->pos.x - ball.size.x * 0.5, player->pos.y + player->size.y * 0.5 - ball.size.y * 0.5);
			ball.throwway = -1;
		}
		if (player->rotate == 3 || player->rotate == 0 || player->rotate == 1)
		{
			ball.pos = D3DXVECTOR2(player->pos.x + ball.size.x * 0.5, player->pos.y + player->size.y * 0.5 - ball.size.y * 0.5);
			ball.throwway = 1;
		}
	}

	//-----ボールの座標を決める(Enemy)
	if (ball.throwflag == false && ball.enemyhaveflag == true)		//ボールが飛んでいないとき&&エネミーが持ってるとき
	{
		if (enemy->rotate == 2)
		{
			ball.pos = D3DXVECTOR2(enemy->pos.x - ball.size.x * 0.5, enemy->pos.y + enemy->size.y * 0.5 - ball.size.y * 0.5);
			ball.throwway = -1;
		}
		if (enemy->rotate == 3 || enemy->rotate == 0 || enemy->rotate == 1)
		{
			ball.pos = D3DXVECTOR2(enemy->pos.x + ball.size.x * 0.5, enemy->pos.y + enemy->size.y * 0.5 - ball.size.y * 0.5);
			ball.throwway = 1;
		}
	}

	//-----軌道計算
	if (ball.throwflag == true)
	{
		ball.pos.x += ball.move.x * ball.throwway;
		ball.pos.y += ball.move.y;
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

		//-----反射,ゲームっぽい減速計算
		if (ball.pos.y < 0.0f)							//上
			ball.move.y *= -1;
		if (ball.pos.y + ball.size.y > ball.fallpos)	//下(投げた瞬間のプレイヤーのy座標)
		{
			ball.move.y *= -1;
			ball.enemyhitflag = false;
			ball.playerhitflag = false;
		}
		if (ball.pos.x < 0.0f)							//左
		{
			if (ball.move.x < 0)
				ball.move.x += 5.0f;
			if (ball.move.x > 0)
				ball.move.x -= 5.0f;
			ball.enemyhitflag = false;
			ball.playerhitflag = false;
		}
		if (ball.pos.x + ball.size.x > SCREEN_WIDTH)	//右
		{
			if (ball.move.x > 0)
				ball.move.x -= 5.0f;
			if (ball.move.x < 0)
				ball.move.x += 5.0f;
			ball.move.x *= -1;
			ball.enemyhitflag = false;
			ball.playerhitflag = false;
		}
	}
}

//-----描画処理
void DrawBall(void)
{
	DrawSpriteLeftTop(ball.texture, ball.pos.x, ball.pos.y, ball.size.x, ball.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----エネミーが投げる処理
void E_Throw(void)
{
	ENEMY* enemy = GetEnemy();
	INVINCIBLE* invincible = GetInvincible();
	if (ball.throwflag == false && ball.enemyhaveflag == true)
	{
		ball.fallpos = enemy->pos.y + enemy->size.y;
		ball.enemyhaveflag = false;
		if (invincible->use == true) //-----無敵スキルを使ってるか？どうかの判定
			ball.playerhitflag = false;
		if (invincible->use == false)
			ball.playerhitflag = true;
		ball.throwflag = true;
	}
}

//プレイヤーが投げる処理
void P_Throw(void)
{
	PLAYER* player = GetPlayer();

	//-----lキーでプレイヤーが投げる
	if (GetKeyboardTrigger(DIK_L) && ball.throwflag == false && ball.playerhaveflag == true)
	{
		ball.playerhavetime = 0.0f;
		ball.fallpos = player->pos.y + player->size.y;
		ball.playerhaveflag = false;
		ball.enemyhitflag = true;
		ball.throwflag = true;
	}
}

void AddBallMove(float move, float rotato, float set_pos_y, float set_size_y)
//渡された角度に渡された速度で加算する。角度はラジアン。反時計回り。
{
	ball.move.x = cosf(rotato) * move; // 玉の撃ちだすスピードを計算
	ball.move.y = sinf(rotato) * -move;
	ball.fallpos = set_pos_y + set_size_y;
}

//-----構造体ポインタ取得処理
BALL* GetBall()
{
	return &ball;
}