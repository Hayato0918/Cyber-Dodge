//ファイアーウォール描画処理[slime_animation.cpp]
#include "slime_animation.h"
#include "slime.h"
#include "ball.h"


void slime_animation()
{
	SLIME* slime = GetSlime();
	BALL* ball = GetBall();

	//-----描画設定
	//-----止まってるとき
	if (slime->walktextureflag == false)
	{
		slime->standtexturetime = slime->standtexturetime + 1.f;

		if (slime->rotate == 3)		//右を向いてたら
		{
			slime->standLRflag = false;
			if (slime->standtexturetime < 30.f)
			{
				slime->u = 0.5f;
				slime->uw = 0.5f;
			}
			if (slime->standtexturetime > 30.f && slime->standtexturetime <= 60.f)
			{
				slime->u = 0.f;
				slime->uw = 0.5f;
			}
		}
		if (slime->rotate == 2)		//左を向いてたら
		{
			slime->standLRflag = true;
			if (slime->standtexturetime < 30.f)
			{
				slime->u = 0.f;
				slime->uw = 0.5f;
			}
			if (slime->standtexturetime > 30.f && slime->standtexturetime <= 60.f)
			{
				slime->u = 0.5f;
				slime->uw = 0.5f;
			}
		}
		if (slime->standtexturetime > 60)
			slime->standtexturetime = 0.0f;
	}

	//投げたとき
	if (slime->throwtextureflag == true)
	{
		slime->throwtexturetime = slime->throwtexturetime + 1.0f;
		if (slime->rotate == 3)		//右を向いていたら
		{
			slime->throwtextureflag = true;
			slime->throwLRflag = false;
			if (slime->throwtexturetime < 5)	//
			{
				slime->u = 0.8f;
				slime->uw = 0.15f;
			}
			if (slime->throwtexturetime >= 5 && slime->throwtexturetime < 10)
			{
				slime->u = 0.65f;
				slime->uw = 0.15f;
			}
			if (slime->throwtexturetime >= 10 && slime->throwtexturetime < 15)
			{
				slime->u = 0.5f;
				slime->uw = 0.15f;
			}
			if (slime->throwtexturetime >= 15 && slime->throwtexturetime < 20)
			{
				slime->u = 0.33f;
				slime->uw = 0.15f;
			}
			if (slime->throwtexturetime >= 20 && slime->throwtexturetime < 25)
			{
				slime->u = 0.17f;
				slime->uw = 0.13f;
			}
			if (slime->throwtexturetime >= 25 && slime->throwtexturetime < 30)
			{
				slime->u = 0.0f;
				slime->uw = 0.1f;
			}
			if (slime->throwtexturetime >= 30)
			{
				slime->throwtextureflag = false;
				slime->throwtexturetime = 0.0f;
			}
		}

		if (slime->rotate == 2)		//左を向いていたら
		{
			slime->throwtextureflag = true;
			slime->throwLRflag = true;
			if (slime->throwtexturetime < 5)	//
			{
				slime->u = 0.05f;
				slime->uw = 0.15f;
			}
			if (slime->throwtexturetime >= 5 && slime->throwtexturetime < 10)
			{
				slime->u = 0.2f;
				slime->uw = 0.15f;
			}
			if (slime->throwtexturetime >= 10 && slime->throwtexturetime < 15)
			{
				slime->u = 0.35f;
				slime->uw = 0.15f;
			}
			if (slime->throwtexturetime >= 15 && slime->throwtexturetime < 20)
			{
				slime->u = 0.5f;
				slime->uw = 0.17f;
			}
			if (slime->throwtexturetime >= 20 && slime->throwtexturetime < 25)
			{
				slime->u = 0.67f;
				slime->uw = 0.16f;
			}
			if (slime->throwtexturetime >= 25 && slime->throwtexturetime < 30)
			{
				slime->u = 0.9f;
				slime->uw = 0.1f;
			}
			if (slime->throwtexturetime >= 30)
			{
				slime->throwtextureflag = false;
				slime->throwtexturetime = 0.0f;
			}
		}
	}
	if (slime->throwtextureflag == false)
		slime->throwtexturetime = 0.0f;

	//ダメージを受けたら
	if (slime->damagetextureflag == true)
	{
		slime->damagetexturetime = slime->damagetexturetime + 1.f;
		if (slime->rotate == 3)		//右を向いていたら
		{
			slime->damageLRflag = false;
			slime->u = 0.f;
			slime->uw = 1.f;
			if (slime->damagetexturetime >= 30)
			{
				slime->damagetextureflag = false;
				slime->damagetexturetime = 0.0f;
			}
		}
		if (slime->rotate == 2)		//右を向いていたら
		{
			slime->damageLRflag = true;
			slime->u = 0.f;
			slime->uw = 1.f;
			if (slime->damagetexturetime >= 30)
			{
				slime->damagetextureflag = false;
				slime->damagetexturetime = 0.0f;
			}
		}
	}
}