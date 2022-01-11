//バグゲージ処理 [bug.cpp]
#include "bugincrease.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "ball.h"
#include "map_point.h"

//-----マクロ定義
#define gaugedecrease 0.2f	//ゲージの減少量
#define gaugeincrease 4.0f  //ゲージ増加量
#define gaugeincreasetime 30
#define gaugedecreasetime 30

#define gaugenum 20		//ゲージの数(ゲージ量換算で1つ5)

//-----プロトタイプ宣言
BUG bug;
BUGGAUGE buggauge[gaugenum];
BUGNUMBER bugnumber[3];

//-----グローバル変数

//-----初期化処理
HRESULT InitBugIncrease(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->gamecount == 1)
	{
		//フレームの設定
		bug.gaugeonce = 8;
		bug.framepos = D3DXVECTOR2(150.0f, 20.0f);
		bug.framesize = D3DXVECTOR2(150.f * bug.gaugeonce, 220);
		bug.frametexture = LoadTexture("data/TEXTURE/buggauge/gaugeframe.png");
		bug.breaktexture = LoadTexture("data/TEXTURE/gaugebreak.png");
		bug.breakflag = false;
		bug.drawnum = 0;
		bug.decreasetime = 0.f;

		//ゲージの設定
		for (int i = 0; i < gaugenum; i++)
		{
			buggauge[i].pos = D3DXVECTOR2(370.f + i * 40.f, 65.f);
			buggauge[i].size = D3DXVECTOR2(95.0f, 70);
			buggauge[i].drawflag = false;
		}
		bug.gaugetexture = LoadTexture("data/TEXTURE/buggauge/gaugebar.png");

		//数字の設定
		for (int i = 0; i < 3; i++)
		{
			bugnumber[i].pos = D3DXVECTOR2(850.f + i * 65.f , 155.f);
			bugnumber[i].size = D3DXVECTOR2(65.f, 70.f);
			bugnumber[i].u = 0.0f;
			bugnumber[i].v = 0.0f;
			bugnumber[i].uw = 0.2f;
			bugnumber[i].vh = 0.5f;
			bugnumber[i].drawflag = false;
		}
		bugnumber[0].u = 0.2f;
		bugnumber[0].v = 0.f;
		bugnumber[0].uw = 0.2f;
		bugnumber[0].vh = 0.5f;
		bug.numbertexture = LoadTexture("data/TEXTURE/buggauge/Number.png");
	}

	return S_OK;
}

//-----終了処理
void UninitBugIncrease(void)
{

}

//-----更新処理
void UpdateBugIncrease(void)
{
	PLAYER* player = GetPlayer();
	BALL* ball = GetBall();

	//-----プレイヤーがボールを持ち続けている時間が一定以上になったら、バグゲージを増やす
	if (ball->playerhaveflag == true && bug.drawnum < gaugenum)
	{
		ball->playerhavetime = ball->playerhavetime + 1.0f;

		if (ball->playerhavetime >= gaugeincreasetime)
		{
				buggauge[bug.drawnum].drawflag = true;
				bug.drawnum = bug.drawnum + 1;
				ball->playerhavetime = 0.f;
		}
	}

	//-----時間経過によるゲージの減少
	if (ball->playerhaveflag == false && bug.drawnum >= 0)
	{
		bug.decreasetime = bug.decreasetime + 1.f;

		if (bug.decreasetime > gaugedecreasetime)
		{
			buggauge[bug.drawnum].drawflag = false;
			bug.drawnum = bug.drawnum - 1;
			bug.decreasetime = 0.f;
		}
	}

	if (bug.drawnum <= 1)
	{
		bugnumber[0].drawflag = false;
		bugnumber[1].drawflag = false;
		bugnumber[2].drawflag = true;
	}
	if (bug.drawnum >= 2 && bug.drawnum <= 19)
	{
		bugnumber[0].drawflag = false;
		bugnumber[1].drawflag = true;
		bugnumber[2].drawflag = true;
	}
	if (bug.drawnum > 19)
	{
		bugnumber[0].drawflag = true;
		bugnumber[1].drawflag = true;
		bugnumber[2].drawflag = true;
	}

	//-----ゲージ下の数字の描画設定
	if (bug.drawnum == 0)	//0
	{
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 1)	//5
	{
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}

	if (bug.drawnum == 2)	//10
	{
		bugnumber[1].u = 0.2f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 3)	//15
	{
		bugnumber[1].u = 0.2f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 4)	//20
	{
		bugnumber[1].u = 0.4f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 5)	//25
	{
		bugnumber[1].u = 0.4f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 6)	//30
	{
		bugnumber[1].u = 0.6f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 7)	//35
	{
		bugnumber[1].u = 0.6f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 8)	//40
	{
		bugnumber[1].u = 0.8f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 9)	//45
	{
		bugnumber[1].u = 0.8f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 10)	//50
	{
		bugnumber[1].u = 0.0f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 11)	//55
	{
		bugnumber[1].u = 0.0f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 12)	//60
	{
		bugnumber[1].u = 0.2f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 13)	//65
	{
		bugnumber[1].u = 0.2f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 14)	//70
	{
		bugnumber[1].u = 0.4f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 15)	//75
	{
		bugnumber[1].u = 0.4f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 16)	//80
	{
		bugnumber[1].u = 0.6f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 17)	//85
	{
		bugnumber[1].u = 0.6f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 18)	//90
	{
		bugnumber[1].u = 0.8f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 19)	//95
	{
		bugnumber[1].u = 0.8f;
		bugnumber[1].v = 0.5f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.5f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
	if (bug.drawnum == 20)	//100
	{
		bugnumber[0].u = 0.2f;
		bugnumber[0].v = 0.0f;
		bugnumber[0].uw = 0.2f;
		bugnumber[0].vh = 0.5f;
		bugnumber[1].u = 0.0f;
		bugnumber[1].v = 0.0f;
		bugnumber[1].uw = 0.2f;
		bugnumber[1].vh = 0.5f;
		bugnumber[2].u = 0.0f;
		bugnumber[2].v = 0.0f;
		bugnumber[2].uw = 0.2f;
		bugnumber[2].vh = 0.5f;
	}
}

//-----描画処理
void DrawBugIncrease(void)
{
	//-----バグゲージの描画
	for (int i = 0; i < gaugenum; i++)
	{
		if(buggauge[i].drawflag == true)
		DrawSpriteLeftTop(bug.gaugetexture, buggauge[i].pos.x, buggauge[i].pos.y, buggauge[i].size.x, buggauge[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}

	//-----バグゲージの枠の描画
	if(bug.breakflag == false)
	DrawSpriteLeftTop(bug.frametexture, bug.framepos.x, bug.framepos.y, bug.framesize.x, bug.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);
	if (bug.breakflag == true)
		DrawSpriteLeftTop(bug.breaktexture, bug.framepos.x, bug.framepos.y, bug.framesize.x, bug.framesize.y, 0.0f, 0.0f, 1.0f, 1.0f);

	//-----数字の描画
	for (int i = 0; i < 3; i++)
	{
		if(bugnumber[i].drawflag == true)
		DrawSpriteLeftTop(bug.numbertexture, bugnumber[i].pos.x, bugnumber[i].pos.y, bugnumber[i].size.x, bugnumber[i].size.y, bugnumber[i].u, bugnumber[i].v, bugnumber[i].uw, bugnumber[i].vh);
	}
}

//-----構造体ポインタ取得処理
BUG* GetBugIncrease()
{
	return &bug;
}

BUGGAUGE* GetBugGauge()
{
	return &buggauge[0];
}