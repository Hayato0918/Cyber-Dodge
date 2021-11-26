//�Q�[������ [game.cpp]

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
#include "enemy_hp.h"
#include "ball.h"
#include "catch.h"
#include "escape.h"

#include "skillrandom.h"

//-----�萔��`

//-----�\���̐錾

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ��̒�`


//-----�������֐�
void InitGame(void)
{
	InitBG();
	InitBug();
	InitPlayerHp();
	InitPlayer();
	InitEnemy();
	InitEnemyHp();
	InitBall();
	InitCatch();
	InitEscape();
	InitRandom();


}

//-----�I�������֐�
void UninitGame()
{


	UninitRandom();
	InitCatch();
	UninitBall();
	UninitEnemy();
	UninitEnemyHp();
	UninitPlayer();
	UninitPlayerHp();
	UninitBug();
	UninitBG();
}

//-----�X�V����������֐�
void UpdateGame(void)
{
	UpdatePlayer();
	UpdatePlayerHp();
	UpdateBug();
	UpdateEnemy();
	UpdateEnemyHp();
	UpdateBall();
	UpdateCatch();
	UpdateRandom();


}

//-----�`�揈���֐�
void DrawGame(void)
{
	DrawBG();
	DrawBug();
	DrawPlayerHp();
	DrawPlayer();
	DrawEnemy();
	DrawEnemyHp();
	DrawBall();
	DrawCatch();
	DrawRandom();


}

