//スキル処理 [skill.cpp]
#include "bg.h"
#include "texture.h"
#include "sprite.h"

#include "buildup.h"
#include "ballspeedup.h"
#include "barrier.h"
#include "smallplayer.h"
#include "bigball.h"
#include "slowarea.h"
#include "invade.h"
#include "step.h"
#include "Billiards.h"
#include "baseball.h"
#include "invincible.h"
#include "ballturnaround.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数
int skill_num;


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

	//-----スロウエリア生成
	InitSlowArea();

	//-----不法侵入処理
	InitInvade();

	//-----ステップ
	InitStep();

	//-----ビリヤード
	InitBilliards();

	//-----野球
	InitBaseball();

	//-----無敵
	InitInvincible();



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

	//-----スロウエリア生成
	_SlowArea();

	//-----不法侵入
	_Invade();

	//-----ステップ
	_Step();

	//-----ビリヤード
	_Billiards();

	//-----野球
	_Baseball();

	//-----無敵
	_Invincible();

	//-----方向転換
	_BallTurnAround();
}

void DrawSkill(void)
{
	//-----バリア描画
	DrawBarrier();

	//-----スロウエリア描画
	DrawSlowArea();

	//-----ビリヤード描画
	DrawBilliards();

	//-----バット描画
	DrawBaseball();

	//-----無敵描画
	DrawInvincible();
}