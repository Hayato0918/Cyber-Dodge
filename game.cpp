//ゲーム処理 [game.cpp]
#include "game.h"
//システム.h
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"

#include "bg.h"
#include "bug.h"
#include "bugrandom.h"
#include "bugincrease.h"
#include "enemy.h"
#include "player.h"
#include "player_hp.h"
#include "ball.h"
#include "catch.h"
#include "tutorial.h"

#include "skill.h"
#include "skillrandom.h"

#include "enemybreak.h"

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
	InitBall();
	InitCatch();
	InitSkill();
	InitRandom();
	InitEnemyBreak();
	InitTutorial();

}

//-----終了処理関数
void UninitGame()
{
	UninitTutorial();
	UninitEnemyBreak();
	UninitRandom();
	InitCatch();
	UninitBall();
	UninitEnemy();
	UninitPlayer();
	UninitPlayerHp();
	UninitBugIncrease();
	UninitBG();
}

//-----更新処理をする関数
void UpdateGame(void)
{
	UpdateBG();
	UpdatePlayerHp();
	UpdatePlayer();
	UpdateBugIncrease();
	UpdateEnemy();
	UpdateBall();
	UpdateCatch();
	_Skill();
	UpdateRandom();
	_Bug();
	UpdateEnemyBreak();
	UpdateTutorial();
}

//-----描画処理関数
void DrawGame(void)
{
	PLAYER* player = GetPlayer();

	if (player->drawdepth == true)
	{
		DrawBG();
		DrawTutorial();
		DrawPlayer();
		DrawEnemy();
		DrawBall();
		DrawCatch();
		DrawBug();
		DrawSkill();
		DrawRandom();
		DrawBugIncrease();
		DrawPlayerHp();
	}
	if (player->drawdepth == false)
	{
		DrawBG();
		DrawTutorial();
		DrawEnemy();
		DrawPlayer();
		DrawBall();
		DrawCatch();
		DrawBug();
		DrawSkill();
		DrawRandom();
		DrawBugIncrease();
		DrawPlayerHp();
	}
	DrawEnemyBreak();

}

