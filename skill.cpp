//スキル処理 [skill.cpp]
#include "bg.h"
#include "texture.h"
#include "sprite.h"

#include "buildup.h"
#include "ballspeedup.h"
#include "barrier.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数

//-----初期化処理
HRESULT InitSkill(void)
{
	//-----巨大化処理
	InitBuildUp();

	//-----ボールスピードアップ処理
	InitBallSpeedUp();

	//-----バリア処理
	InitBarrier();


	return S_OK;
}

void _Skill(void)
{
	//-----巨大化処理
	_BuildUp();

	//-----ボールスピードアップ処理
	_BallSpeedUp();

	//-----バリア処理
	_Barrier();


}

void DrawSkill(void)
{
	//-----バリア描画
	DrawBarrier();
}