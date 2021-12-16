//スキル処理 [skill.cpp]
#include "bg.h"
#include "texture.h"
#include "sprite.h"

#include "ballspeedup.h"
#include "ballturnaround.h"
#include "barrier.h"
#include "baseball.h"
#include "bigball.h"
#include "Billiards.h"
#include "buildup.h"
#include "catchjamming.h"
#include "enemy_powerdown.h"
#include "invade.h"
#include "invincible.h"
#include "penetration.h"
#include "player_powerup.h"
#include "player_regen.h"
#include "player_speedup.h"
#include "rockcreate.h"
#include "slowarea.h"
#include "smallplayer.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数

//-----初期化処理
HRESULT InitSkill(void)
{
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

	return S_OK;
}

void _Skill(void)
{
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

	//-----スロウエリア描画
	DrawSlowArea();
}