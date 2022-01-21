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
				deleter->u = 0.67f;
				deleter->uw = 0.33f;
			}
			if (deleter->standtexturetime >= 27 && deleter->standtexturetime < 54)
			{
				deleter->u = 0.34f;
				deleter->uw = 0.33f;
			}
			if (deleter->standtexturetime >= 54 && deleter->standtexturetime < 81)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.34f;
			}
			if (deleter->standtexturetime >= 81)
				deleter->standtexturetime = 0.0f;
		}
		if (deleter->rotate == 2)		//左を向いてたら
		{
			deleter->standLRflag = true;
			if (deleter->standtexturetime < 27)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.32f;
			}
			if (deleter->standtexturetime >= 27 && deleter->standtexturetime < 54)
			{
				deleter->u = 0.32f;
				deleter->uw = 0.32f;
			}
			if (deleter->standtexturetime >= 54 && deleter->standtexturetime < 81)
			{
				deleter->u = 0.64f;
				deleter->uw = 0.32f;
			}
			if (deleter->standtexturetime >= 81)
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
				deleter->u = 0.67f;
				deleter->uw = 0.33f;
			}
			if (deleter->walktexturetime >= 20 && deleter->walktexturetime < 40)
			{
				deleter->u = 0.34f;
				deleter->uw = 0.33f;
			}
			if (deleter->walktexturetime >= 40 && deleter->walktexturetime < 60)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.33f;
			}
			if (deleter->walktexturetime >= 60)
				deleter->walktexturetime = 0.0f;
		}
		if (deleter->rotate == 2)		//左を向いてたら
		{
			deleter->walkLRflag = true;
			if (deleter->walktexturetime < 20)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.33f;
			}
			if (deleter->walktexturetime >= 20 && deleter->walktexturetime < 40)
			{
				deleter->u = 0.33f;
				deleter->uw = 0.33f;
			}
			if (deleter->walktexturetime >= 40 && deleter->walktexturetime < 60)
			{
				deleter->u = 0.66f;
				deleter->uw = 0.34f;
			}
			if (deleter->walktexturetime >= 60)
				deleter->walktexturetime = 0.0f;
		}
	}
	if (deleter->walktextureflag == false)
		deleter->walktexturetime = 0.0f;

	//-----キャッチしたとき
	//if()

	//-----死んだとき
	if (deleter->drawflag == false)
	{
		deleter->u = 0.0f;
		deleter->uw = 1.0f;
	}
}