//�Q�[������ [game.cpp]
#include "game.h"
//�V�X�e��.h
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

//-----�萔��`

//-----�\���̐錾

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ��̒�`


//-----�������֐�
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

//-----�I�������֐�
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

//-----�X�V����������֐�
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

//-----�`�揈���֐�
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

