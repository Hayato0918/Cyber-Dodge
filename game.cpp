//ゲーム処理 [game.cpp]

#include "game.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"

#include "bg.h"
#include "bug.h"
#include "player.h"
#include "player_hp.h"
#include "enemy.h"
#include "ball.h"
#include "catch.h"
#include "escape.h"

#include "skillrandom.h"

//-----定数定義

//-----構造体宣言

//-----プロトタイプ宣言

//-----グローバル変数の定義


//-----初期化関数
void InitGame(void)
{
	InitBG();
	InitBug();
	InitPlayerHp();
	InitPlayer();
	InitEnemy();
	InitBall();
	InitCatch();
	InitEscape();
	InitRandom();


}

//-----終了処理関数
void UninitGame()
{


	UninitRandom();
	InitCatch();
	UninitBall();
	UninitEnemy();
	UninitPlayer();
	UninitPlayerHp();
	UninitBug();
	UninitBG();
}

//-----更新処理をする関数
void UpdateGame(void)
{
	UpdatePlayer();
	UpdatePlayerHp();
	UpdateBug();
	UpdateEnemy();
	UpdateBall();
	UpdateCatch();
	UpdateRandom();


}

//-----描画処理関数
void DrawGame(void)
{
	DrawBG();
	DrawBug();
	DrawPlayerHp();
	DrawPlayer();
	DrawEnemy();
	DrawBall();
	DrawCatch();
	DrawRandom();


}

