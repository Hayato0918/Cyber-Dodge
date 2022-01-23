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

}

//-----�I�������֐�
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
}

//-----�X�V����������֐�
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

	if (GetKeyboardTrigger(DIK_M))
		SceneTransition(SCENE_MAP);
}

//-----�`�揈���֐�
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

}

