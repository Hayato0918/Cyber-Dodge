//スキル_ボール巨大化処理 [BigBall.cpp]
#include "bigball.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "ball.h"

//-----マクロ定義
#define bigballtime 180		//3s間

//-----プロトタイプ宣言
BIGBALL bigball;

//-----グローバル変数

//-----初期化処理
HRESULT InitBigBall(void)
{
	bigball.use = false;
	bigball.timeflag = false;
	bigball.time = 0.0f;

	return S_OK;
}

//-----ボール巨大化処理
void _BigBall(void)
{
	BALL* ball = GetBall();

	//8キーを押したら、3s間ボールのサイズが大きくなる
	if (GetKeyboardTrigger(DIK_0) && bigball.use == false)
	{
		ball->size = D3DXVECTOR2(ball->size.x * 2, ball->size.y * 2);
		bigball.timeflag = true;
		bigball.use = true;
	}
	//スキル使用3s後にもとの大きさに戻る
	if (bigball.timeflag == true)
		bigball.time = bigball.time + 1.0f;
	if (bigball.time > bigballtime)
	{
		bigball.timeflag = false;
		ball->size = D3DXVECTOR2(ball->size.x * 0.5f, ball->size.y * 0.5f);
		bigball.time = 0.0f;
	}
}