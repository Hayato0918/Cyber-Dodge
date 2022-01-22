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
#include "disappear.h"
#include "doubleattack.h"
#include "enemy_powerdown.h"
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
	//-----オートキャッチ
	InitAuto_c();

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

	//-----消滅
	InitDisappear();

	//-----ダブルアタック
	InitDouble();

	//-----エネミーパワーダウン
	InitPowerDown();

	//-----不法侵入
	InitInvade();

	//-----無敵
	InitInvincible();

	//-----地雷
	InitLandMines();

	//-----マインドハック
	InitMindhack();

	//-----落とし穴
	InitOtosiana();

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

	//-----ワープ
	InitWarp();

	return S_OK;
}

void _Skill(void)
{
	//-----オートキャッチ
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

	//-----消滅
	_Disappear();

	//-----ダブルアタック
	_Double();

	//-----エネミーパワーダウン
	_PowerDown();

	//-----不法侵入
	_Invade();

	//-----無敵
	_Invincible();

	//-----地雷
	_LandMines();

	//-----マインドハック
	_Mindhack();

	//-----落とし穴
	_Otosiana();

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

	//-----ワープ
	_Warp();
}

void DrawSkill(void)
{
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

	//-----地雷
	DrawLandMines();

	//-----落とし穴
	//DrawOtosiana();

	//-----スロウエリア描画
	DrawSlowArea();

	//-----ワープ
	DrawWarp();
}