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
			if (firewall->standtexturetime < 27)
			{
				firewall->u = 0.67f;
				firewall->uw = 0.33f;
			}
			if (firewall->standtexturetime >= 27 && firewall->standtexturetime < 54)
			{
				firewall->u = 0.34f;
				firewall->uw = 0.33f;
			}
			if (firewall->standtexturetime >= 54 && firewall->standtexturetime < 81)
			{
				firewall->u = 0.0f;
				firewall->uw = 0.34f;
			}
			if (firewall->standtexturetime >= 81)
				firewall->standtexturetime = 0.0f;
		}
		if (firewall->rotate == 2)		//左を向いてたら
		{
			firewall->standLRflag = true;
			if (firewall->standtexturetime < 27)
			{
				firewall->u = 0.0f;
				firewall->uw = 0.32f;
			}
			if (firewall->standtexturetime >= 27 && firewall->standtexturetime < 54)
			{
				firewall->u = 0.32f;
				firewall->uw = 0.32f;
			}
			if (firewall->standtexturetime >= 54 && firewall->standtexturetime < 81)
			{
				firewall->u = 0.64f;
				firewall->uw = 0.32f;
			}
			if (firewall->standtexturetime >= 81)
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

	//-----キャッチしたとき
	if (firewall->catchtextureflag == true)
	{
		firewall->catchtexturetime = firewall->catchtexturetime + 1.0f;
		if (firewall->rotate == 3)		//右を向いてたら
		{
			firewall->catchLRflag = false;
			if (firewall->catchtexturetime < 10)
			{
				firewall->u = 0.59f;
				firewall->uw = 0.41f;
			}
			if (firewall->catchtexturetime >= 10 && firewall->catchtexturetime < 20)
			{
				firewall->u = 0.28f;
				firewall->uw = 0.3f;
			}
			if (firewall->catchtexturetime >= 20 && firewall->catchtexturetime < 30)
			{
				firewall->u = 0.f;
				firewall->uw = 0.28f;
			}
			if (firewall->catchtexturetime >= 30)
			{
				firewall->catchtextureflag = false;
				firewall->catchtexturetime = 0.0f;
			}
		}
		if (firewall->rotate == 2)		//左を向いてたら
		{
			firewall->catchLRflag = true;
			if (firewall->catchtexturetime < 10)
			{
				firewall->u = 0.0f;
				firewall->uw = 0.28f;
			}
			if (firewall->catchtexturetime >= 10 && firewall->catchtexturetime < 20)
			{
				firewall->u = 0.28f;
				firewall->uw = 0.3f;
			}
			if (firewall->catchtexturetime >= 20 && firewall->catchtexturetime < 30)
			{
				firewall->u = 0.59f;
				firewall->uw = 0.41f;
			}
			if (firewall->catchtexturetime >= 30)
			{
				firewall->catchtextureflag = false;
				firewall->catchtexturetime = 0.0f;
			}
		}
	}
	if (firewall->catchtextureflag == false)
		firewall->catchtexturetime = 0.0f;

	//-----死んだとき
	if (firewall->drawflag == false)
	{
		firewall->u = 0.0f;
		firewall->uw = 1.0f;
	}
}