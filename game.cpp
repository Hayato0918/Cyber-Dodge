//�Q�[������ [game.cpp]

#include "game.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"

#include "bg.h"
#include "bug.h"
#include "player.h"
#include "enemy.h"
#include "ball.h"
#include "catch.h"
#include "escape.h"

//-----�萔��`

//-----�\���̐錾

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ��̒�`


//-----�������֐�
void InitGame(void)
{
	InitBG();
	InitBug();
	InitPlayer();
	InitEnemy();
	InitBall();
	InitCatch();
	InitEscape();



}

//-----�I�������֐�
void UninitGame()
{



	InitCatch();
	UninitBall();
	UninitEnemy();
	UninitPlayer();
	UninitBug();
	UninitBG();
}

//-----�X�V����������֐�
void UpdateGame(void)
{
	UpdatePlayer();
	UpdateBug();
	UpdateEnemy();
	UpdateBall();
	UpdateCatch();



}

//-----�`�揈���֐�
void DrawGame(void)
{
	DrawBG();
	DrawBug();
	DrawPlayer();
	DrawEnemy();
	DrawBall();
	DrawCatch();



}

