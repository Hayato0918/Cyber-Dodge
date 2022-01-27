//スキル処理 [skill.cpp]
#include "bg.h"
#include "texture.h"
#include "sprite.h"

#include "autocatch.h"
#include "ballspeedup.h"
#include "ballturnaround.h"
#include "barrier.h"
#include "baseball.h"
#include "bigball.h"
#include "Billiards.h"
#include "buildup.h"
#include "catchjamming.h"
#include "enemy_powerdown.h"
#include "disappear.h"
#include "doubleattack.h"
#include "invade.h"
#include "invincible.h"
#include "landmines.h"
#include "mindhack.h"
#include "otoshiana.h"
#include "penetration.h"
#include "player_powerup.h"
#include "player_regen.h"
#include "player_speedup.h"
#include "rockcreate.h"
#include "slowarea.h"
#include "smallplayer.h"
#include "timestop.h"
#include "warp.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数

//-----初期化処理
HRESULT InitSkill(void)
{
	InitWarp();

	InitOtosiana();

	InitDouble();

	InitDisappear();

	InitAuto_c();

	InitLandMines();

	//-----ブーストボール
	InitBallSpeedUp();

	//-----方向転換
	InitBallTurnAround();

	//-----バリア
	InitBarrier();

	//-----プレイ！ベースボール
	InitBaseball();

	//-----ボール巨大化
	InitBigBall();

	//-----ビリヤードは初めて？
	InitBilliards();

	//-----ビルドアップ
	InitBuildUp();

	//-----キャッチ不可
	InitCatchJamming();

	//-----エネミーパワーダウン
	InitPowerDown();

	//-----不法侵入
	InitInvade();

	//-----無敵
	InitInvincible();

	//-----マインドハック
	InitMindhack();

	//-----貫通
	InitKantsuu();

	//-----プレイヤーパワーアップ
	InitPowerUp();

	//-----プレイヤーリジェネ
	InitPlayerRegen();

	//-----プレイヤースピードアップ
	InitSpeedUp();

	//----岩石生成
	InitGanseki();

	//-----スロウエリア
	InitSlowArea();

	//-----プレイヤー縮小
	InitSmallPlayer();

	//-----タイムストップ
	InitTimestop();

	return S_OK;
}

void _Skill(void)
{
	_Warp();

	_Otosiana();

	_LandMines();

	_Double();

	_Disappear();

	_Auto_c();

	//-----ブーストボール
	_BallSpeedUp();

	//-----方向転換
	_BallTurnAround();

	//-----バリア
	_Barrier();

	//-----プレイ！ベースボール
	_Baseball();

	//-----ボール巨大化
	_BigBall();

	//-----ビリヤードは初めて？
	_Billiards();

	//-----ビルドアップ
	_BuildUp();

	//-----キャッチ不可
	_CatchJamming();

	//-----エネミーパワーダウン
	_PowerDown();

	//-----不法侵入
	_Invade();

	//-----無敵
	_Invincible();

	//-----マインドハック
	_Mindhack();

	//-----貫通
	_Kantsuu();

	//-----プレイヤーパワーアップ
	_PowerUp();

	//-----プレイヤーリジェネ
	_PlayerRegen();

	//-----プレイヤースピードアップ
	_SpeedUp();

	//----岩石生成
	_Ganseki();

	//-----スロウエリア
	_SlowArea();

	//-----プレイヤー縮小
	_SmallPlayer();

	//-----タイムストップ
	_Timestop();
}

void DrawSkill(void)
{
	DrawWarp();

	DrawOtosiana();

	DrawLandMines();

	//-----バリア
	DrawBarrier();

	//-----プレイ！ベースボール
	DrawBaseball();

	//-----ビリヤードは初めて？
	DrawBilliards();

	//-----無敵
	DrawInvincible();

	//-----岩石生成
	DrawGanseki();

	//-----スロウエリア描画
	DrawSlowArea();

	DrawTimestop();

	DrawRegen();

	DrawSpeedup();

	DrawPowerup();
}