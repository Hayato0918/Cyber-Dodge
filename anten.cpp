/*------------------------------------------
[ 暗転 [ Bug_anten.cpp ] ]
-------------------------------------------*/
#include "anten.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"

#include "bugincrease.h"
#include "bugrandom.h"
#include "screencrack.h"

//-----プロトタイプ宣言
ANTEN anten;

//-----初期化処理
HRESULT InitAnten(void)
{
	anten.pos = D3DXVECTOR2(0.0f, 0.f);
	anten.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

	anten.use = false;
	anten.drawflag = false;

	return S_OK;
}

//-----プレイヤー反転処理
void _Anten(void)
{
	BUG* bug = GetBugIncrease();
	BUGRANDOM* bugrandom = GetBugRandom();
	CRACK* crack = GetCrack();

	//バグゲージが100以上になって、スキルを使うかボールが当たると画面を霧が覆う
	if (bugrandom->code == 1 && bug->breakflag == true && anten.use == false)
	{
		anten.use = true;
		anten.drawflag = true;
	}

	//バグゲージが100以下になったら霧が晴れる
	if (bug->breakflag == false && anten.use == true)
	{
		anten.use = false;
		anten.drawflag = false;
		bugrandom->code = (rand() % bugrandom->num) + 1;
	}
}

//-----描画処理
void DrawAnten(void)
{
	if (anten.drawflag == true)
		DrawSpriteLeftTop(anten.texture, anten.pos.x, anten.pos.y, anten.size.x, anten.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

ANTEN* GetAnten()
{
	return &anten;
}