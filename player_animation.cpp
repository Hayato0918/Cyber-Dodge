//プレイヤー操作処理[player_animation.cpp]
#include "player_animation.h"
//システム.h
#include "input.h"
//
#include "player.h"
#include "ball.h"
#include "catch.h"

void player_animation()
{
	PLAYER* player = GetPlayer();
	BALL* ball = GetBall();

	//-----描画設定
	//止まってるとき
	if (player->walktextureflag == false)
	{
		if (ball->playerhaveflag == false)	//ボールを持ってなかったら
		{
			if (player->rotate == 3)		//右を向いてたら
			{
				player->u = 0.0f;
				player->uw = 0.5f;
				player->standLRflag = false;
			}
			if (player->rotate == 2)		//左を向いてたら
			{
				player->u = 0.5f;
				player->uw = 0.5f;
				player->standLRflag = true;
			}
		}

		if (ball->playerhaveflag == true)	//ボールを持ってるとき
		{
			if (player->rotate == 3)		//右を向いてたら
			{
				player->u = 0.5f;
				player->uw = 0.5f;
				player->standLRflag = false;
			}
			if (player->rotate == 2)		//左を向いてたら
			{
				player->u = 0.0f;
				player->uw = 0.5f;
				player->standLRflag = true;
			}
		}
	}

	//動いているとき
	if (player->walktextureflag == true)
	{
		if (ball->playerhaveflag == false)	//ボールを持てなかったら
		{
			if (player->rotate == 3)		//右を向いてたら
			{
				player->u = 0.f;
				player->uw = 0.5f;
				player->walkLRflag = false;
			}
			if (player->rotate == 2)		//左を向いてたら
			{
				player->u = 0.5f;
				player->uw = 0.5f;
				player->walkLRflag = true;
			}
		}

		if (ball->playerhaveflag == true)	//ボールを持ってるとき
		{
			if (player->rotate == 3)		//右を向いてたら
			{
				player->u = 0.5f;
				player->uw = 0.5f;
				player->walkLRflag = false;
			}
			if (player->rotate == 2)		//左を向いてたら
			{
				player->u = 0.0f;
				player->uw = 0.5f;
				player->walkLRflag = true;
			}
		}
	}

	//キャッチしたとき
	if (ball->playerhaveflag == true)	//プレイヤーがボールをキャッチしたら
	{
		if (ball->fallflag == false)
		{
			player->catchtexturetime = player->catchtexturetime + 1.0f;
			if (player->rotate == 3)		//右を向いていたら
			{
				player->catchtextureflag = true;
				player->catchLRflag = false;
				if (player->catchtexturetime < 5)	//
				{
					player->u = 0.7f;
					player->uw = 0.3f;
				}
				if (player->catchtexturetime >= 5 && player->catchtexturetime < 15)
				{
					player->u = 0.33f;
					player->uw = 0.375f;
				}
				if (player->catchtexturetime >= 15 && player->catchtexturetime < 20)
				{
					player->u = 0.0f;
					player->uw = 0.33f;
				}
				if (player->catchtexturetime >= 20)
					player->catchtextureflag = false;
			}
			if (player->rotate == 2)
			{
				player->catchtextureflag = true;
				player->catchLRflag = true;
				if (player->catchtexturetime < 5)
				{
					player->u = 0.0f;
					player->uw = 0.3f;
				}
				if (player->catchtexturetime >= 5 && player->catchtexturetime < 15)
				{
					player->u = 0.29f;
					player->uw = 0.375f;
				}
				if (player->catchtexturetime >= 15 && player->catchtexturetime < 20)
				{
					player->u = 0.67f;
					player->uw = 0.33f;
				}
				if (player->catchtexturetime >= 20)
					player->catchtextureflag = false;
			}
		}
	}
	if (ball->playerhaveflag == false)
	{
		player->catchtexturetime = 0.0f;
		player->catchtextureflag = false;
	}

	//落ちているボールを拾ったとき
	if (ball->playerhaveflag == true)
	{
		if (ball->fallflag == true)
		{
			player->picktexturetime = player->picktexturetime + 1.0f;
			if (player->rotate == 3)		//右を向いていたら
			{
				player->picktextureflag = true;
				player->pickLRflag = false;
				if (player->picktexturetime < 30)	//
				{
					player->u = 0.0f;
					player->uw = 0.55f;
				}
				if (player->picktexturetime >= 30 && player->picktexturetime < 20)
				{
					player->u = 0.55f;
					player->uw = 0.45f;
				}
				if (player->picktexturetime >= 20)
				{
					player->picktextureflag = false;

				}
			}
			if (player->rotate == 2)
			{
				player->picktextureflag = true;
				player->pickLRflag = true;
				if (player->picktexturetime < 10)
				{
					player->u = 0.45f;
					player->uw = 0.55f;
				}
				if (player->picktexturetime >= 10 && player->picktexturetime < 15)
				{
					player->u = 0.0f;
					player->uw = 0.45f;
				}
				if (player->picktexturetime >= 15)
				{
					player->picktextureflag = false;
				}
			}
		}
	}
	if (ball->playerhaveflag == false)
	{
		player->picktexturetime = 0.0f;
		player->picktextureflag = false;
	}

	//投げたとき
	if (ball->playerthrowflag == true)
	{
		player->throwtexturetime = player->throwtexturetime + 1.0f;
		if (player->rotate == 3)		//右を向いていたら
		{
			player->throwtextureflag = true;
			player->throwLRflag = false;
			if (player->throwtexturetime < 5)	//
			{
				player->u = 0.0f;
				player->uw = 0.2f;
			}
			if (player->throwtexturetime >= 5 && player->throwtexturetime < 10)
			{
				player->u = 0.2f;
				player->uw = 0.2f;
			}
			if (player->throwtexturetime >= 10 && player->throwtexturetime < 15)
			{
				player->u = 0.4f;
				player->uw = 0.26f;
			}
			if (player->throwtexturetime >= 15 && player->throwtexturetime < 20)
			{
				player->u = 0.66f;
				player->uw = 0.18f;
			}
			if (player->throwtexturetime >= 20 && player->throwtexturetime < 25)
			{
				player->u = 0.84f;
				player->uw = 0.16f;
			}
			if (player->throwtexturetime >= 25)
			{
				player->throwtextureflag = false;
				player->throwtexturetime = 0.0f;
				ball->playerthrowflag = false;
			}
		}
		if (player->rotate == 2)
		{
			player->throwtextureflag = true;
			player->throwLRflag = true;
			if (player->throwtexturetime < 5)	//
			{
				player->u = 0.8f;
				player->uw = 0.2f;
			}
			if (player->throwtexturetime >= 5 && player->throwtexturetime < 10)
			{
				player->u = 0.6f;
				player->uw = 0.2f;
			}
			if (player->throwtexturetime >= 10 && player->throwtexturetime < 15)
			{
				player->u = 0.34f;
				player->uw = 0.26f;
			}
			if (player->throwtexturetime >= 15 && player->throwtexturetime < 20)
			{
				player->u = 0.16f;
				player->uw = 0.18f;
			}
			if (player->throwtexturetime >= 20 && player->throwtexturetime < 25)
			{
				player->u = 0.0f;
				player->uw = 0.16f;
			}
			if (player->throwtexturetime >= 25)
			{
				player->throwtextureflag = false;
				player->throwtexturetime = 0.0f;
				ball->playerthrowflag = false;
			}
		}
	}

	//スキルを使ったとき
	if (player->skilluseflag == true)
	{
		player->skilltexturetime = player->skilltexturetime + 1.0f;
		if (player->rotate == 3)		//右を向いていたら
		{
			player->skilltextureflag = true;
			player->skillLRflag = false;
			if (player->skilltexturetime < 5)
			{
				player->u = 0.0f;
				player->uw = 0.23f;
			}
			if (player->skilltexturetime >= 5 && player->skilltexturetime < 10)
			{
				player->u = 0.23f;
				player->uw = 0.23f;
			}
			if (player->skilltexturetime >= 10 && player->skilltexturetime < 15)
			{
				player->u = 0.46f;
				player->uw = 0.27f;
			}
			if (player->skilltexturetime >= 15 && player->skilltexturetime < 20)
			{
				player->u = 0.73f;
				player->uw = 0.27f;
			}
			if (player->skilltexturetime >= 20)
			{
				player->skilltextureflag = false;
				player->skilluseflag = false;
				player->skilltexturetime = 0.0f;
			}
		}
		if (player->rotate == 2)
		{
			player->skilltextureflag = true;
			player->skillLRflag = true;
			if (player->skilltexturetime < 5)	//
			{
				player->u = 0.78f;
				player->uw = 0.22f;
			}
			if (player->skilltexturetime >= 5 && player->skilltexturetime < 10)
			{
				player->u = 0.54f;
				player->uw = 0.23f;
			}
			if (player->skilltexturetime >= 10 && player->skilltexturetime < 15)
			{
				player->u = 0.27f;
				player->uw = 0.27f;
			}
			if (player->skilltexturetime >= 15 && player->skilltexturetime < 20)
			{
				player->u = 0.0f;
				player->uw = 0.27f;
			}
			if (player->skilltexturetime >= 20)
			{
				player->skilltextureflag = false;
				player->skilluseflag = false;
				player->skilltexturetime = 0.0f;
			}
		}
	}



	//ダメージを受けたとき
	if (player->damagetextureflag == true)
	{
		player->damagetexturetime = player->damagetexturetime + 1.0f;
		if (player->rotate == 3)
		{
			player->u = 0.0f;
			player->uw = 1.0f;
			player->damageLRflag = false;
			if (player->damagetexturetime > 15)
			{
				player->damagetextureflag = false;
				player->damagetexturetime = 0.0f;
			}
		}
		if (player->rotate == 2)
		{
			player->u = 0.0f;
			player->uw = 1.0f;
			player->damageLRflag = true;
			if (player->damagetexturetime > 15)
			{
				player->damagetextureflag = false;
				player->damagetexturetime = 0.0f;
			}
		}
	}

	if (player->drawflag == false)
	{
		//player->size.y = 180.0f;
		player->u = 0.0f;
		player->uw = 1.0f;
	}
}