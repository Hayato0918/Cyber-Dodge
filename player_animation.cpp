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
			player->standtexturetime = player->standtexturetime + 1.f;
			if (player->rotate == 3)		//右を向いてたら
			{
				player->v = 0.f;
				player->uw = 0.1f;
				player->vh = 0.5f;
				if (player->standtexturetime < 10)
				{
					player->u = 0.f;
				}
				if (player->standtexturetime > 10 && player->standtexturetime <= 20)
				{
					player->u = 0.1f;

				}
				if (player->standtexturetime > 20 && player->standtexturetime <= 30)
				{
					player->u = 0.2f;
				}
				if (player->standtexturetime > 30 && player->standtexturetime <= 40)
				{
					player->u = 0.3f;
				}
				if (player->standtexturetime > 40 && player->standtexturetime <= 50)
				{
					player->u = 0.4f;
				}
				if (player->standtexturetime > 50 && player->standtexturetime <= 60)
				{
					player->u = 0.5f;
				}
				if (player->standtexturetime > 60 && player->standtexturetime <= 70)
				{
					player->u = 0.6f;
				}
				if (player->standtexturetime > 70 && player->standtexturetime <= 80)
				{
					player->u = 0.7f;
				}
				if (player->standtexturetime > 80 && player->standtexturetime <= 90)
				{
					player->u = 0.8f;
				}
				if (player->standtexturetime > 90 && player->standtexturetime <= 100)
				{
					player->u = 0.9f;
				}
				if (player->standtexturetime > 100)
				{
					player->standtexturetime = 0.f;
				}
				player->standLRflag = false;
			}
			if (player->rotate == 2)		//左を向いてたら
			{
				player->v = 0.f;
				player->uw = 0.1f;
				player->vh = 0.5f;
				if (player->standtexturetime < 10)
				{
					player->u = 0.9f;
				}
				if (player->standtexturetime > 10 && player->standtexturetime <= 20)
				{
					player->u = 0.8f;

				}
				if (player->standtexturetime > 20 && player->standtexturetime <= 30)
				{
					player->u = 0.7f;
				}
				if (player->standtexturetime > 30 && player->standtexturetime <= 40)
				{
					player->u = 0.6f;
				}
				if (player->standtexturetime > 40 && player->standtexturetime <= 50)
				{
					player->u = 0.5f;
				}
				if (player->standtexturetime > 50 && player->standtexturetime <= 60)
				{
					player->u = 0.4f;
				}
				if (player->standtexturetime > 60 && player->standtexturetime <= 70)
				{
					player->u = 0.3f;
				}
				if (player->standtexturetime > 70 && player->standtexturetime <= 80)
				{
					player->u = 0.2f;
				}
				if (player->standtexturetime > 80 && player->standtexturetime <= 90)
				{
					player->u = 0.1f;
				}
				if (player->standtexturetime > 90 && player->standtexturetime <= 100)
				{
					player->u = 0.0f;
				}
				if (player->standtexturetime > 100)
				{
					player->standtexturetime = 0.f;
				}
				player->standLRflag = true;
			}
		}

		if (ball->playerhaveflag == true)	//ボールを持ってるとき
		{
			if (player->rotate == 3)		//右を向いてたら
			{
				player->v = 0.5f;
				player->uw = 0.1f;
				player->vh = 0.5f;
				if (player->standtexturetime < 10)
				{
					player->u = 0.f;
				}
				if (player->standtexturetime > 10 && player->standtexturetime <= 20)
				{
					player->u = 0.1f;

				}
				if (player->standtexturetime > 20 && player->standtexturetime <= 30)
				{
					player->u = 0.2f;
				}
				if (player->standtexturetime > 30 && player->standtexturetime <= 40)
				{
					player->u = 0.3f;
				}
				if (player->standtexturetime > 40 && player->standtexturetime <= 50)
				{
					player->u = 0.4f;
				}
				if (player->standtexturetime > 50 && player->standtexturetime <= 60)
				{
					player->u = 0.5f;
				}
				if (player->standtexturetime > 60 && player->standtexturetime <= 70)
				{
					player->u = 0.6f;
				}
				if (player->standtexturetime > 70 && player->standtexturetime <= 80)
				{
					player->u = 0.7f;
				}
				if (player->standtexturetime > 80 && player->standtexturetime <= 90)
				{
					player->u = 0.8f;
				}
				if (player->standtexturetime > 90 && player->standtexturetime <= 100)
				{
					player->u = 0.9f;
				}
				if (player->standtexturetime > 100)
				{
					player->standtexturetime = 0.f;
				}
				player->standLRflag = false;
			}
			if (player->rotate == 2)		//左を向いてたら
			{
				player->v = 0.5f;
				player->uw = 0.1f;
				player->vh = 0.5f;
				if (player->standtexturetime < 10)
				{
					player->u = 0.9f;
				}
				if (player->standtexturetime > 10 && player->standtexturetime <= 20)
				{
					player->u = 0.8f;

				}
				if (player->standtexturetime > 20 && player->standtexturetime <= 30)
				{
					player->u = 0.7f;
				}
				if (player->standtexturetime > 30 && player->standtexturetime <= 40)
				{
					player->u = 0.6f;
				}
				if (player->standtexturetime > 40 && player->standtexturetime <= 50)
				{
					player->u = 0.5f;
				}
				if (player->standtexturetime > 50 && player->standtexturetime <= 60)
				{
					player->u = 0.4f;
				}
				if (player->standtexturetime > 60 && player->standtexturetime <= 70)
				{
					player->u = 0.3f;
				}
				if (player->standtexturetime > 70 && player->standtexturetime <= 80)
				{
					player->u = 0.2f;
				}
				if (player->standtexturetime > 80 && player->standtexturetime <= 90)
				{
					player->u = 0.1f;
				}
				if (player->standtexturetime > 90 && player->standtexturetime <= 100)
				{
					player->u = 0.0f;
				}
				if (player->standtexturetime > 100)
				{
					player->standtexturetime = 0.f;
				}
				player->standLRflag = true;
			}
		}
	}

	//動いているとき
	if (player->walktextureflag == true)
	{
		if (ball->playerhaveflag == false)	//ボールを持ってなかったら
		{
			player->v = 0.f;
			player->uw = 0.5f;
			player->vh = 1.f;
			if (player->rotate == 3)		//右を向いてたら
			{
				player->u = 0.f;
				player->walkLRflag = false;
			}
			if (player->rotate == 2)		//左を向いてたら
			{
				player->u = 0.5f;
				player->walkLRflag = true;
			}
		}

		if (ball->playerhaveflag == true)	//ボールを持ってるとき
		{
			player->v = 0.f;
			player->uw = 0.5f;
			player->vh = 1.f;
			if (player->rotate == 3)		//右を向いてたら
			{
				player->u = 0.5f;
				player->walkLRflag = false;
			}
			if (player->rotate == 2)		//左を向いてたら
			{
				player->u = 0.0f;
				player->walkLRflag = true;
			}
		}
	}

	//キャッチしたとき
	if (ball->playerhaveflag == true)	//プレイヤーがボールをキャッチしたら
	{
			player->catchtexturetime = player->catchtexturetime + 1.0f;
			if (player->rotate == 3)		//右を向いていたら
			{
				player->v = 0.f;
				player->uw = 0.3f;
				player->vh = 1.f;

				player->catchtextureflag = true;
				player->catchLRflag = false;
				if (player->catchtexturetime < 5)	//
				{
					player->u = 0.0f;
					player->uw = 0.3f;
				}
				if (player->catchtexturetime >= 5 && player->catchtexturetime < 15)
				{
					player->u = 0.31f;
					player->uw = 0.375f;
				}
				if (player->catchtexturetime >= 15 && player->catchtexturetime < 20)
				{
					player->u = 0.675f;
					player->uw = 0.315f;
				}
				if (player->catchtexturetime >= 20)
				{
					player->catchtextureflag = false;
					player->uw = 0.5f;
				}
			}
			if (player->rotate == 2)
			{
				player->v = 0.f;
				player->uw = 0.3f;
				player->vh = 1.f;
				player->catchtextureflag = true;
				player->catchLRflag = true;
				if (player->catchtexturetime < 5)
				{
					player->u = 0.0f;
					player->uw = 0.3f;
				}
				if (player->catchtexturetime >= 5 && player->catchtexturetime < 15)
				{
					player->u = 0.31f;
					player->uw = 0.375f;
				}
				if (player->catchtexturetime >= 15 && player->catchtexturetime < 20)
				{
					player->u = 0.675f;
					player->uw = 0.315f;
				}
				if (player->catchtexturetime >= 20)
				{
					player->catchtextureflag = false;
					player->uw = 0.5f;
				}
			}
	}
	if (ball->playerhaveflag == false)
	{
		player->catchtexturetime = 0.0f;
		player->catchtextureflag = false;
	}

	//落ちているボールを拾ったとき
	//if (ball->playerhaveflag == true)
	//{
	//	if (ball->fallflag == true)
	//	{
	//		player->picktexturetime = player->picktexturetime + 1.0f;
	//		if (player->rotate == 3)		//右を向いていたら
	//		{
	//			player->v = 0.f;
	//			player->vh = 1.f;
	//			player->picktextureflag = true;
	//			player->pickLRflag = false;
	//			if (player->picktexturetime < 5)	//
	//			{
	//				player->u = 0.0f;
	//				player->uw = 0.083f;
	//			}
	//			if (player->picktexturetime > 5 && player->picktexturetime <= 10)	//
	//			{
	//				player->u = 0.083f;
	//				player->uw = 0.09f;
	//			}
	//			if (player->picktexturetime > 10 && player->picktexturetime <= 15)	//
	//			{
	//				player->u = 0.173f;
	//				player->uw = 0.092f;
	//			}
	//			if (player->picktexturetime > 15 && player->picktexturetime <= 20)	//
	//			{
	//				player->u = 0.265f;
	//				player->uw = 0.092f;
	//			}
	//			if (player->picktexturetime > 20 && player->picktexturetime <= 25)	//
	//			{
	//				player->u = 0.357f;
	//				player->uw = 0.093f;
	//			}
	//			if (player->picktexturetime > 25 && player->picktexturetime <= 30)	//
	//			{
	//				player->u = 0.45f;
	//				player->uw = 0.094f;
	//			}
	//			if (player->picktexturetime > 30 && player->picktexturetime <= 35)	//
	//			{
	//				player->u = 0.545f;
	//				player->uw = 0.067f;
	//			}
	//			if (player->picktexturetime > 35 && player->picktexturetime <= 40)	//
	//			{
	//				player->u = 0.612f;
	//				player->uw = 0.067f;
	//			}
	//			if (player->picktexturetime > 40 && player->picktexturetime <= 45)	//
	//			{
	//				player->u = 0.679f;
	//				player->uw = 0.064f;
	//			}
	//			if (player->picktexturetime > 45 && player->picktexturetime <= 50)	//
	//			{
	//				player->u = 0.743f;
	//				player->uw = 0.064f;
	//			}
	//			if (player->picktexturetime > 50 && player->picktexturetime <= 55)	//
	//			{
	//				player->u = 0.807f;
	//				player->uw = 0.064f;
	//			}
	//			if (player->picktexturetime > 55 && player->picktexturetime <= 60)	//
	//			{
	//				player->u = 0.871f;
	//				player->uw = 0.064f;
	//			}
	//			if (player->picktexturetime > 60 && player->picktexturetime <= 65)	//
	//			{
	//				player->u = 0.935f;
	//				player->uw = 0.064f;
	//			}
	//			if (player->picktexturetime > 65)
	//			{
	//				player->picktextureflag = false;
	//			}
	//		}
	//		if (player->rotate == 2)
	//		{
	//			player->v = 0.f;
	//			player->vh = 1.f;
	//			player->picktextureflag = true;
	//			player->pickLRflag = true;
	//			if (player->picktexturetime < 5)	//
	//			{
	//				player->u = 0.917f;
	//				player->uw = 0.083f;
	//			}
	//			if (player->picktexturetime > 5 && player->picktexturetime <= 10)	//
	//			{
	//				player->u = 0.827f;
	//				player->uw = 0.09f;
	//			}
	//			if (player->picktexturetime > 10 && player->picktexturetime <= 15)	//
	//			{
	//				player->u = 0.735f;
	//				player->uw = 0.092f;
	//			}
	//			if (player->picktexturetime > 15 && player->picktexturetime <= 20)	//
	//			{
	//				player->u = 0.643f;
	//				player->uw = 0.092f;
	//			}
	//			if (player->picktexturetime > 20 && player->picktexturetime <= 25)	//
	//			{
	//				player->u = 0.55f;
	//				player->uw = 0.093f;
	//			}
	//			if (player->picktexturetime > 25 && player->picktexturetime <= 30)	//
	//			{
	//				player->u = 0.456f;
	//				player->uw = 0.094f;
	//			}
	//			if (player->picktexturetime > 30 && player->picktexturetime <= 35)	//
	//			{
	//				player->u = 0.389f;
	//				player->uw = 0.067f;
	//			}
	//			if (player->picktexturetime > 35 && player->picktexturetime <= 40)	//
	//			{
	//				player->u = 0.322f;
	//				player->uw = 0.067f;
	//			}
	//			if (player->picktexturetime > 40 && player->picktexturetime <= 45)	//
	//			{
	//				player->u = 0.255f;
	//				player->uw = 0.067f;
	//			}
	//			if (player->picktexturetime > 45 && player->picktexturetime <= 50)	//
	//			{
	//				player->u = 0.188f;
	//				player->uw = 0.065f;
	//			}
	//			if (player->picktexturetime > 50 && player->picktexturetime <= 55)	//
	//			{
	//				player->u = 0.126f;
	//				player->uw = 0.065f;
	//			}
	//			if (player->picktexturetime > 55 && player->picktexturetime <= 60)	//
	//			{
	//				player->u = 0.061f;
	//				player->uw = 0.065f;
	//			}
	//			if (player->picktexturetime > 60 && player->picktexturetime <= 65)	//
	//			{
	//				player->u = 0.0f;
	//				player->uw = 0.061f;
	//			}
	//			if (player->picktexturetime > 65)
	//			{
	//				player->picktextureflag = false;
	//			}
	//		}
	//	}
	//}
	//if (ball->playerhaveflag == false)
	//{
	//	player->picktexturetime = 0.0f;
	//	player->picktextureflag = false;
	//}

	//投げたとき
	if (ball->playerthrowflag == true)
	{
		player->throwtexturetime = player->throwtexturetime + 1.0f;
		if (player->rotate == 3)		//右を向いていたら
		{
			player->v = 0.f;
			player->vh = 1.f;
			player->u = 0.f;
			player->uw = 0.22f;

			player->throwtextureflag = true;
			player->throwLRflag = false;
			if (player->throwtexturetime < 5)	//
			{
				player->u = 0.0f;
				player->uw = 0.22f;
			}
			if (player->throwtexturetime >= 5 && player->throwtexturetime < 10)
			{
				player->u = 0.22f;
				player->uw = 0.22f;
			}
			if (player->throwtexturetime >= 10 && player->throwtexturetime < 15)
			{
				player->u = 0.44f;
				player->uw = 0.23f;
			}
			if (player->throwtexturetime >= 15 && player->throwtexturetime < 20)
			{
				player->u = 0.67f;
				player->uw = 0.16f;
			}
			if (player->throwtexturetime >= 20 && player->throwtexturetime < 25)
			{
				player->u = 0.83f;
				player->uw = 0.17f;
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
			player->v = 0.f;
			player->vh = 1.f;
			player->u = 0.78f;
			player->uw = 0.22f;
			player->throwtextureflag = true;
			player->throwLRflag = true;
			if (player->throwtexturetime < 5)	//
			{
				player->u = 0.78f;
				player->uw = 0.22f;
			}
			if (player->throwtexturetime >= 5 && player->throwtexturetime < 10)
			{
				player->u = 0.56f;
				player->uw = 0.22f;
			}
			if (player->throwtexturetime >= 10 && player->throwtexturetime < 15)
			{
				player->u = 0.33f;
				player->uw = 0.23f;
			}
			if (player->throwtexturetime >= 15 && player->throwtexturetime < 20)
			{
				player->u = 0.17f;
				player->uw = 0.16f;
			}
			if (player->throwtexturetime >= 20 && player->throwtexturetime < 25)
			{
				player->u = 0.0f;
				player->uw = 0.17f;
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
			player->v = 0.f;
			player->vh = 1.f;
			player->u = 0.f;
			player->uw = 0.23f;
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
			player->v = 0.f;
			player->vh = 1.f;
			player->u = 0.78f;
			player->uw = 0.22f;
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
		player->u = 0.0f;
		player->uw = 1.0f;
	}
}