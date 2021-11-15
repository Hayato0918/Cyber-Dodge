//スキル処理 [skill.cpp]
#include "bg.h"
#include "texture.h"
#include "sprite.h"

#include "buildup.h"
#include "ballspeedup.h"
#include "barrier.h"
#include "smallplayer.h"
#include "bigball.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数

//-----初期化処理
HRESULT InitSkill(void)
{
	//-----プレイヤー巨大化
	InitBuildUp();

	//-----ボールスピードアップ
	InitBallSpeedUp();

	//-----バリア
	InitBarrier();

	//-----プレイヤー縮小
	InitSmallPlayer();

	//-----ボール巨大化
	InitBigBall();




	return S_OK;
}

void _Skill(void)
{
	//-----プレイヤー巨大化
	_BuildUp();

	//-----ボールスピードアップ
	_BallSpeedUp();

	//-----バリア
	_Barrier();

	//-----プレイヤー縮小
	_SmallPlayer();

	//-----ボール巨大化
	_BigBall();


}

void DrawSkill(void)
{
	//-----バリア描画
	DrawBarrier();
}