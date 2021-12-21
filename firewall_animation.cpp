//ファイアーウォール描画処理[firewall_animation.cpp]
#include "firewall_animation.h"
#include "firewall.h"


void firewall_animation()
{
	FIREWALL* firewall = GetFireWall();

	//-----描画設定
	//-----止まってるとき
	if (firewall->walktextureflag == false)
	{
		firewall->standtexturetime = firewall->standtexturetime + 1.0f;
		if (firewall->rotate == 3)		//右を向いてたら
		{
			firewall->standLRflag = false;
			if (firewall->standtexturetime < 20)
			{
				firewall->u = 0.75f;
				firewall->uw = 0.25f;
			}
			if (firewall->standtexturetime >= 20 && firewall->standtexturetime < 40)
			{
				firewall->u = 0.5f;
				firewall->uw = 0.25f;
			}
			if (firewall->standtexturetime >= 40 && firewall->standtexturetime < 60)
			{
				firewall->u = 0.25f;
				firewall->uw = 0.25f;
			}
			if (firewall->standtexturetime >= 60 && firewall->standtexturetime < 80)
			{
				firewall->u = 0.0f;
				firewall->uw = 0.25f;
			}
			if (firewall->standtexturetime >= 80)
				firewall->standtexturetime = 0.0f;
		}
		if (firewall->rotate == 2)		//左を向いてたら
		{
			firewall->standLRflag = true;
			if (firewall->standtexturetime < 20)
			{
				firewall->u = 0.0f;
				firewall->uw = 0.25f;
			}
			if (firewall->standtexturetime >= 20 && firewall->standtexturetime < 40)
			{
				firewall->u = 0.25f;
				firewall->uw = 0.25f;
			}
			if (firewall->standtexturetime >= 40 && firewall->standtexturetime < 60)
			{
				firewall->u = 0.5f;
				firewall->uw = 0.25f;
			}
			if (firewall->standtexturetime >= 60 && firewall->standtexturetime < 80)
			{
				firewall->u = 0.75f;
				firewall->uw = 0.25f;
			}
			if (firewall->standtexturetime >= 80)
				firewall->standtexturetime = 0.0f;
		}
	}

	//-----歩いているとき
	if (firewall->walktextureflag == true)
	{
		firewall->walktexturetime = firewall->walktexturetime + 1.0f;
		if (firewall->rotate == 3)		//右を向いてたら
		{
			firewall->walkLRflag = false;
			if (firewall->walktexturetime < 20)
			{
				firewall->u = 0.67f;
				firewall->uw = 0.33f;
			}
			if (firewall->walktexturetime >= 20 && firewall->walktexturetime < 40)
			{
				firewall->u = 0.34f;
				firewall->uw = 0.33f;
			}
			if (firewall->walktexturetime >= 40 && firewall->walktexturetime < 60)
			{
				firewall->u = 0.0f;
				firewall->uw = 0.33f;
			}
			if (firewall->walktexturetime >= 60)
				firewall->walktexturetime = 0.0f;
		}
		if (firewall->rotate == 2)		//左を向いてたら
		{
			firewall->walkLRflag = true;
			if (firewall->walktexturetime < 20)
			{
				firewall->u = 0.0f;
				firewall->uw = 0.33f;
			}
			if (firewall->walktexturetime >= 20 && firewall->walktexturetime < 40)
			{
				firewall->u = 0.33f;
				firewall->uw = 0.33f;
			}
			if (firewall->walktexturetime >= 40 && firewall->walktexturetime < 60)
			{
				firewall->u = 0.66f;
				firewall->uw = 0.34f;
			}
			if (firewall->walktexturetime >= 60)
				firewall->walktexturetime = 0.0f;
		}
	}
	if (firewall->walktextureflag == false)
		firewall->walktexturetime = 0.0f;

	//-----死んだとき
	if (firewall->drawflag == false)
	{
		firewall->u = 0.0f;
		firewall->uw = 1.0f;
	}
}