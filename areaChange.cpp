/*------------------------------------------
[ エリア変化 [ areaChange.h ] ]
-------------------------------------------*/
#include "areaChange.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"

#include "bugincrease.h"
#include "bg.h"

//-----マクロ定義
#define areaChangetime 2400
#define areaChangeReturntime 180

//-----プロトタイプ宣言
AREACHANGE areaChange;

//-----グローバル変数

HRESULT InitAreaChange(void)
{
	areaChange.pos = D3DXVECTOR2(0.0f, 0.0f);
	areaChange.move = D3DXVECTOR2(0.0f, 0.0f);
	areaChange.use = false;
	areaChange.time = 0;
	areaChange.counttime = 0;
	areaChange.finishflag = false;
	areaChange.timeflag = false;

	return S_OK;
}

void _AreaChange(void)
{
	BUG* bug = GetBugIncrease();
	BG* bg = GetBG();



	//バグゲージが溜まると、40秒間境界線がランダムに動く処理。
	if (bug->gaugesize.x >= 100)
	{
		areaChange.time = 0;
		if (areaChange.use == false)
		{
			areaChange.timeflag = true;
			areaChange.use = true;
			areaChange.counttime = 0;
		}
	}

	if (areaChange.timeflag == true)
	{
		areaChange.time = areaChange.time + 1;
		areaChange.counttime = areaChange.counttime + 1;
		areaChange.pos.x = bg->clPos.x;

		if (areaChange.counttime % 60 == 1)
		{
			if (rand() % 2 == 0)
			{
				areaChange.move.x = (rand() % 3 + 1) * 0.5f;
			}
			else
			{
				areaChange.move.x = (rand() % 3 + 1) * -0.5f;
			}
		}

		if (areaChange.pos.x < bg->size.x / 4)
		{
			areaChange.move.x *= -1;
		}
		if (areaChange.pos.x > bg->size.x / 4 + bg->size.x / 2)
		{
			areaChange.move.x *= -1;
		}


		areaChange.pos.x += areaChange.move.x;
		SetCenterLine(areaChange.pos.x);
	}

	//40秒後にもとに戻る
	if (areaChange.time > areaChangetime)
	{
		areaChange.timeflag = false;
		areaChange.time = 0;
		areaChange.counttime = 0;
		areaChange.finishflag = true;

		if (areaChange.pos.x > bg->size.x / 2)
		{
			areaChange.move.x = (areaChange.pos.x - bg->size.x / 2) / areaChangeReturntime * -1;
		}
		else if (areaChange.pos.x < bg->size.x / 2)
		{
			areaChange.move.x = (bg->size.x / 2 - areaChange.pos.x) / areaChangeReturntime;
		}
		else
		{
			areaChange.finishflag = false;
		}
	}

	if (areaChange.finishflag == true && areaChange.use == true)
	{
		areaChange.counttime = areaChange.counttime + 1;
		areaChange.pos.x += areaChange.move.x;

		if (areaChange.counttime > areaChangeReturntime - 1)
		{
			areaChange.pos.x = bg->size.x / 2;

			areaChange.finishflag = false;
			areaChange.use = false;
			areaChange.counttime = 0;
		}

		SetCenterLine(areaChange.pos.x);
	}
}

AREACHANGE* GetAreaChange(void)
{
	return &areaChange;
}
