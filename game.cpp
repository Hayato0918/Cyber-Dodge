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

#include "skill.h"
#include "skillrandom.h"

#include "enemybreak.h"
#include "enemy_explosion_animation.h"

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
	//InitEnemyExplosion();
}

//-----終了処理関数
void UninitGame()
{

	UninitEnemyBreak();
	UninitRandom();
	InitCatch();
	UninitBall();
	UninitEnemy();
	UninitPlayer();
	UninitPlayerHp();
	UninitBugIncrease();
	UninitBG();
	//UninitEnemyExplosion();
}

//-----更新処理をする関数
void UpdateGame(void)
{
	UpdateBG();
	UpdatePlayer();
	UpdatePlayerHp();
	UpdateBugIncrease();
	UpdateEnemy();
	UpdateBall();
	UpdateCatch();
	_Skill();
	UpdateRandom();
	_Bug();
	UpdateEnemyBreak();
	//UpdateEnemyExplosion();

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
	//DrawEnemyExplosion();
}

