//ゲーム処理 [game.cpp]

#include "game.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"

#include "bg.h"
#include "bug.h"
#include "bugrandom.h"
#include "bugincrease.h"
#include "player.h"
#include "player_hp.h"
#include "enemy.h"
#include "enemy_hp.h"
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
	InitBugRandom();
	InitBugIncrease();
	InitPlayerHp();
	InitPlayer();
	InitEnemy();
	InitEnemyHp();
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
	UninitEnemyHp();
	UninitPlayer();
	UninitPlayerHp();
	UninitBugIncrease();
	UninitBG();
}

//-----更新処理をする関数
void UpdateGame(void)
{
	UpdatePlayer();
	UpdatePlayerHp();
	UpdateBugIncrease();
	UpdateEnemy();
	UpdateEnemyHp();
	UpdateBall();
	UpdateCatch();
	UpdateRandom();
	_Bug();

	if (GetKeyboardTrigger(DIK_M))
		SceneTransition(SCENE_MAP);


}

//-----描画処理関数
void DrawGame(void)
{
	PLAYER* player = GetPlayer();

	if (player->drawdepth == true)
	{
		DrawBG();
		DrawBugIncrease();
		DrawBug();
		DrawPlayerHp();
		DrawPlayer();
		DrawEnemy();
		DrawEnemyHp();
		DrawBall();
		DrawCatch();
		DrawRandom();
	}
	if (player->drawdepth == false)
	{
		DrawBG();
		DrawBugIncrease();
		DrawBug();
		DrawPlayerHp();
		DrawBall();
		DrawEnemy();
		DrawEnemyHp();
		DrawPlayer();
		DrawCatch();
		DrawRandom();
	}

}

