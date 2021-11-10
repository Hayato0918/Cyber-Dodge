//ゲーム処理 [game.cpp]

#include "game.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"

#include "bg.h"
#include "player.h"
#include "enemy.h"
#include "ball.h"
#include "catch.h"
#include "escape.h"

//-----定数定義

//-----構造体宣言

//-----プロトタイプ宣言

//-----グローバル変数の定義


//-----初期化関数
void InitGame(void)
{
	InitBG();
	InitPlayer();
	InitEnemy();
	InitBall();
	InitCatch();
	InitEscape();


}

//-----終了処理関数
void UninitGame()
{


	InitCatch();
	UninitBall();
	UninitEnemy();
	UninitPlayer();
	UninitBG();
}

//-----更新処理をする関数
void UpdateGame(void)
{
	UpdatePlayer();
	UpdateEnemy();
	UpdateBall();
	UpdateCatch();



	//スペースキーが押されていて、フェード処理中ではないとき
	if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE) {

		//RESULTへ移行する
		//SceneTransition(SCENE_RESULT);
	}
}

//-----描画処理関数
void DrawGame(void)
{
	DrawBG();
	DrawPlayer();
	DrawEnemy();
	DrawBall();
	DrawCatch();


}

