/*------------------------------------------
[ 暗転 [ Bug_anten.cpp ] ]
-------------------------------------------*/
#include "anten.h"
#include "input.h"
#include "Texture.h"
#include "sprite.h"

#include "bug.h"

//-----プロトタイプ宣言
ANTEN anten;

//-----初期化処理
HRESULT InitAnten(void)
{
	anten.pos = D3DXVECTOR2(0.0f, SCREEN_HEIGHT - 450.0f);
	anten.size = D3DXVECTOR2(960.0f, 540.0f);

	anten.use = false;
	anten.drawflag = false;

	anten.texture = LoadTexture("data/TEXTURE/anten.png");

	return S_OK;
}

//-----プレイヤー反転処理
void _Anten(void)
{
	BUG* bug = GetBug();

	//バグゲージが100以上になったら画面を霧が覆う
	if (bug->gaugesize.x >= 100 == true && anten.use == false)
	{
		anten.use = true;
		anten.drawflag = true;
	}

	//バグゲージが100以下になったら霧が晴れる
	if (bug->gaugesize.x <= 100 == true && anten.use == true)
	{
		anten.use = false;
		anten.drawflag = false;
	}
}

//-----描画処理
void DrawAnten(void)
{
	if (anten.drawflag == true)
		DrawSpriteLeftTop(anten.texture, anten.pos.x, anten.pos.y, anten.size.x, anten.size.y, 0.0f, 0.0f, 1.0f, 1.0f);

}