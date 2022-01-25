/*------------------------------------------
[ 画面割れ [ Bug_screencrack.cpp ] ]
-------------------------------------------*/
#include "screencrack.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"

#include "bugincrease.h"
#include "bugrandom.h"
#include "player.h"

//-----マクロ定義
#define cracktime 180		//3s間
#define cracktime_yure 10		//0.5s間

//-----プロトタイプ宣言
CRACK crack;

//-----初期化処理
HRESULT InitCrack(void)
{
	crack.pos = D3DXVECTOR2(SCREEN_WIDTH / 2 + 300.0f, SCREEN_HEIGHT / 2 - 300.0f);
	crack.move = D3DXVECTOR2(-50, 50);
	crack.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

	crack.oldpos = crack.pos;
	crack.oldmove = crack.move;

	crack.use = false;
	crack.drawflag = false;
	crack.texture = LoadTexture("data/TEXTURE/buggauge/screencrack.png");
	crack.timeflag = false;
	crack.time = 0.0f;
	crack.time_yure = 0.0f;
	crack.bugflag = false;
	crack.a = 1.0f;
	//crack.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, crack.a);

	return S_OK;
}

//-----プレイヤー反転処理
void _Crack(void)
{
	BUG* bug = GetBugIncrease();
	BUGRANDOM* bugrandom = GetBugRandom();
	PLAYER* player = GetPlayer();

	//バグゲージが100以上になって、スキルを使うかボールが当たると画面が割れる
	if (bug->gaugeoverflag == true && player->skilluseflag == true && crack.use == false && crack.bugflag == false)
	{
		crack.use = true;
		crack.drawflag = true;
		crack.timeflag = true;
		crack.bugflag = true;
	}

	crack.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, crack.a);

	//-----画面が割れた3s後にバグ状態に移行
	if (crack.timeflag == true)
	{
		crack.time = crack.time + 1.0f;
		crack.time_yure = crack.time_yure + 1.0f;
		crack.pos += crack.move;
		crack.a = crack.a - 0.005f;
	}

	//画面を揺らす
	if (crack.time_yure > cracktime_yure)
	{
		crack.move /= 2.0f;
		crack.move *= -1.0f;
		crack.time_yure = 0.0f;
	}

	//画面割れのフェードアウト後、元の数値に戻す
	if (crack.time > cracktime)
	{
		crack.timeflag = false;
		crack.drawflag = false;
		crack.time = 0.0f;
		bug->breakflag = true;
		crack.a = 1.0f;
		/*crack.pos = crack.oldpos;
		crack.move = crack.oldmove;*/
	}

	//バグゲージが100以下になったら
	if (bug->gaugeoverflag == false && crack.use == true)
	{
		crack.use = false;
		crack.pos = D3DXVECTOR2(SCREEN_WIDTH / 2 + 300.0f, SCREEN_HEIGHT / 2 - 300.0f);
		crack.move = D3DXVECTOR2(-50, 50);
		crack.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

		crack.oldpos = crack.pos;
		crack.oldmove = crack.move;

		crack.use = false;
		crack.drawflag = false;
		crack.timeflag = false;
		crack.time = 0.0f;
		crack.time_yure = 0.0f;
		crack.bugflag = false;
		crack.a = 1.0f;
	}
}

//-----描画処理
void DrawCrack(void)
{
	if (crack.drawflag == true && crack.bugflag == true)
	{
		//DrawSpriteLeftTop(crack.texture, crack.pos.x, crack.pos.y, crack.size.x, crack.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		DrawSpriteColor(crack.texture, crack.pos.x, crack.pos.y, crack.size.x, crack.size.y, 0.0f, 0.0f, 1.0f, 1.0f, crack.color);
	}
}

//-----構造体ポインタ取得処理
CRACK* GetCrack()
{
	return &crack;
}