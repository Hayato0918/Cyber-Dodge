//デリーター描画処理[deleter_animation.cpp]
#include "deleter_animation.h"
#include "deleter.h"


void deleter_animation()
{
	DELETER* deleter = GetDeleter();

	//-----描画設定
	//-----止まってるとき
	if (deleter->walktextureflag == false)
	{
		deleter->standtexturetime = deleter->standtexturetime + 1.0f;
		if (deleter->rotate == 3)		//右を向いてたら
		{
			deleter->standLRflag = false;
			if (deleter->standtexturetime < 27)
			{
				deleter->u = 0.75f;
				deleter->uw = 0.25f;
			}
			if (deleter->standtexturetime >= 27 && deleter->standtexturetime < 54)
			{
				deleter->u = 0.50f;
				deleter->uw = 0.25f;
			}
			if (deleter->standtexturetime >= 54 && deleter->standtexturetime < 81)
			{
				deleter->u = 0.25f;
				deleter->uw = 0.25f;
			}
			if (deleter->standtexturetime >= 81 && deleter->standtexturetime < 108)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.25f;
			}
			if (deleter->standtexturetime >= 108)
				deleter->standtexturetime = 0.0f;
		}
		if (deleter->rotate == 2)		//左を向いてたら
		{
			deleter->standLRflag = true;
			if (deleter->standtexturetime < 27)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.25f;
			}
			if (deleter->standtexturetime >= 27 && deleter->standtexturetime < 54)
			{
				deleter->u = 0.25f;
				deleter->uw = 0.25f;
			}
			if (deleter->standtexturetime >= 54 && deleter->standtexturetime < 81)
			{
				deleter->u = 0.50f;
				deleter->uw = 0.25f;
			}
			if (deleter->standtexturetime >= 81 && deleter->standtexturetime < 108)
			{
				deleter->u = 0.75f;
				deleter->uw = 0.25f;
			}
			if (deleter->standtexturetime >= 108)
				deleter->standtexturetime = 0.0f;
		}
	}

	//-----歩いているとき
	if (deleter->walktextureflag == true)
	{
		deleter->walktexturetime = deleter->walktexturetime + 1.0f;
		if (deleter->rotate == 3)		//右を向いてたら
		{
			deleter->walkLRflag = false;
			if (deleter->walktexturetime < 20)
			{
				deleter->u = 0.75f;
				deleter->uw = 0.25f;
			}
			if (deleter->walktexturetime >= 20 && deleter->walktexturetime < 40)
			{
				deleter->u = 0.50f;
				deleter->uw = 0.25f;
			}
			if (deleter->walktexturetime >= 40 && deleter->walktexturetime < 60)
			{
				deleter->u = 0.25f;
				deleter->uw = 0.25f;
			}
			if (deleter->walktexturetime >= 60 && deleter->walktexturetime < 80)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.25f;
			}
			if (deleter->walktexturetime >= 80)
				deleter->walktexturetime = 0.0f;
		}
		if (deleter->rotate == 2)		//左を向いてたら
		{
			deleter->walkLRflag = true;
			if (deleter->walktexturetime < 20)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.25f;
			}
			if (deleter->walktexturetime >= 20 && deleter->walktexturetime < 40)
			{
				deleter->u = 0.25f;
				deleter->uw = 0.25f;
			}
			if (deleter->walktexturetime >= 40 && deleter->walktexturetime < 60)
			{
				deleter->u = 0.50f;
				deleter->uw = 0.25f;
			}
			if (deleter->walktexturetime >= 60 && deleter->walktexturetime < 80)
			{
				deleter->u = 0.75f;
				deleter->uw = 0.25f;
			}
			if (deleter->walktexturetime >= 80)
				deleter->walktexturetime = 0.0f;
		}
	}
	if (deleter->walktextureflag == false)
		deleter->walktexturetime = 0.0f;

	//-----投げるとき
	if (deleter->throwtextureflag == true)
	{
		deleter->throwtexturetime = deleter->throwtexturetime + 1.0f;
		if (deleter->rotate == 3)		//右を向いてたら
		{
			deleter->throwLRflag = false;
			if (deleter->throwtexturetime < 5)
			{
				deleter->u = 0.86f;
				deleter->uw = 0.14f;
			}
			if (deleter->throwtexturetime >= 5 && deleter->throwtexturetime < 10)
			{
				deleter->u = 0.71f;
				deleter->uw = 0.14f;
			}
			if (deleter->throwtexturetime >= 10 && deleter->throwtexturetime < 15)
			{
				deleter->u = 0.57f;
				deleter->uw = 0.14f;
			}
			if (deleter->throwtexturetime >= 15 && deleter->throwtexturetime < 20)
			{
				deleter->u = 0.43f;
				deleter->uw = 0.14f;
			}
			if (deleter->throwtexturetime >= 20 && deleter->throwtexturetime < 25)
			{
				deleter->u = 0.28f;
				deleter->uw = 0.14f;
			}
			if (deleter->throwtexturetime >= 25 && deleter->throwtexturetime < 30)
			{
				deleter->u = 0.14f;
				deleter->uw = 0.14f;
			}
			if (deleter->throwtexturetime >= 30 && deleter->throwtexturetime < 35)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.14f;
			}
			if (deleter->throwtexturetime >= 35)
			{
				deleter->throwtextureflag = false;
				deleter->catchtextureflag_2 = false;
				deleter->throwtexturetime = 0.0f;
			}
		}
		if (deleter->rotate == 2)		//左を向いてたら
		{
			deleter->throwLRflag = true;
			if (deleter->throwtexturetime < 5)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.14f;
			}
			if (deleter->throwtexturetime >= 5 && deleter->throwtexturetime < 10)
			{
				deleter->u = 0.14f;
				deleter->uw = 0.14f;
			}
			if (deleter->throwtexturetime >= 10 && deleter->throwtexturetime < 15)
			{
				deleter->u = 0.28f;
				deleter->uw = 0.14f;
			}
			if (deleter->throwtexturetime >= 15 && deleter->throwtexturetime < 20)
			{
				deleter->u = 0.43f;
				deleter->uw = 0.14f;
			}
			if (deleter->throwtexturetime >= 20 && deleter->throwtexturetime < 25)
			{
				deleter->u = 0.57f;
				deleter->uw = 0.14f;
			}
			if (deleter->throwtexturetime >= 25 && deleter->throwtexturetime < 30)
			{
				deleter->u = 0.71f;
				deleter->uw = 0.14f;
			}
			if (deleter->throwtexturetime >= 30 && deleter->throwtexturetime < 35)
			{
				deleter->u = 0.86f;
				deleter->uw = 0.14f;
			}
			if (deleter->throwtexturetime >= 35)
			{
				deleter->throwtextureflag = false;
				deleter->catchtextureflag_2 = false;
				deleter->throwtexturetime = 0.0f;
			}
		}
	}
	if (deleter->throwtextureflag == false)
		deleter->throwtexturetime = 0.0f;

	//-----キャッチしたとき
	if (deleter->catchtextureflag == true)
	{
		deleter->catchtexturetime = deleter->catchtexturetime + 1.0f;
		if (deleter->rotate == 3)		//右を向いてたら
		{
			deleter->catchLRflag = false;
			if (deleter->catchtexturetime < 5)
			{
				deleter->u = 0.75f;
				deleter->uw = 0.25f;
			}
			if (deleter->catchtexturetime >= 5 && deleter->catchtexturetime < 10)
			{
				deleter->u = 0.50f;
				deleter->uw = 0.25f;
			}
			if (deleter->catchtexturetime >= 10 && deleter->catchtexturetime < 15)
			{
				deleter->u = 0.25f;
				deleter->uw = 0.25f;
			}
			if (deleter->catchtexturetime >= 15 && deleter->catchtexturetime < 20)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.25f;
			}
			if (deleter->catchtexturetime >= 20)
			{
				deleter->catchtextureflag = false;
				deleter->catchtextureflag_2 = true;
				deleter->catchtexturetime = 0.0f;
			}
		}
		if (deleter->rotate == 2)		//左を向いてたら
		{
			deleter->catchLRflag = true;
			if (deleter->catchtexturetime < 5)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.25f;
			}
			if (deleter->catchtexturetime >= 5 && deleter->catchtexturetime < 10)
			{
				deleter->u = 0.25f;
				deleter->uw = 0.25f;
			}
			if (deleter->catchtexturetime >= 10 && deleter->catchtexturetime < 15)
			{
				deleter->u = 0.50f;
				deleter->uw = 0.25f;
			}
			if (deleter->catchtexturetime >= 15 && deleter->catchtexturetime < 20)
			{
				deleter->u = 0.75f;
				deleter->uw = 0.25f;
			}
			if (deleter->catchtexturetime >= 20)
			{
				deleter->catchtextureflag = false;
				deleter->catchtextureflag_2 = true;
				deleter->catchtexturetime = 0.0f;
			}
		}
	}
	if (deleter->catchtextureflag == false)
		deleter->catchtexturetime = 0.0f;


	if (deleter->damagetextureflag == true)
	{
		deleter->damagetexturetime = deleter->damagetexturetime + 1;

		if (deleter->rotate == 2)
		{
			deleter->damageLRflag = true;
				deleter->u = 0.f;
				deleter->uw = 1.f;
			if (deleter->damagetexturetime > 40)
			{
				deleter->damagetextureflag = false;
				deleter->damagetexturetime = 0.f;
				deleter->u = 0.f;
				deleter->uw = 0.25f;
			}
		}
		if (deleter->rotate == 3)
		{
			deleter->damageLRflag = false;
				deleter->u = 0.f;
				deleter->uw = 1.f;
			if (deleter->damagetexturetime > 40)
			{
				deleter->damagetextureflag = false;
				deleter->damagetexturetime = 0.f;
				deleter->u = 0.f;
				deleter->uw = 0.25f;
			}
		}

	}


	//-----死んだとき
	if (deleter->drawflag == false)
	{
		deleter->u = 0.0f;
		deleter->uw = 1.0f;
	}
}