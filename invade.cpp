//スキル_不法侵入処理 [invade.cpp]
#include "invade.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"

//-----マクロ定義
#define invadetime 180		//3s間

//-----プロトタイプ宣言
INVADE invade;

//-----グローバル変数

//-----初期化処理
HRESULT InitInvade(void)
{
	invade.use = false;
	invade.timeflag = false;
	invade.time = 0.0f;

	return S_OK;
}

//-----不法侵入処理
void _Invade(void)
{
	PLAYER* player = GetPlayer();

	//1キーで使用/3秒間敵の陣地に入れる
	if (GetKeyboardTrigger(DIK_0) && invade.use == false)
	{
		//-----プレイヤーの位置を敵陣までワープさせる
		player->pos.x = (SCREEN_WIDTH / 2) + 5;

		invade.timeflag = true;
		invade.use = true;
	}

	//スキル終了時に敵陣にいた場合、x座標を自陣と敵陣の境界まで戻す
	if (invade.timeflag == true)
		invade.time = invade.time + 1.0f;
	if (invade.time > invadetime)
	{
		invade.timeflag = false;
		invade.time = 0.0f;
	}
}

//-----構造体ポインタ取得処理
INVADE* GetInvade(void)
{
	return &invade;
}