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
	InitBugRandom();
	InitBugIncrease();
	InitPlayerHp();
	InitPlayer();
	InitEnemy();
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
	UninitPlayer();
	UninitPlayerHp();
	UninitBugIncrease();
	UninitBG();
}

//-----�X�V����������֐�
void UpdateGame(void)
{
	UpdatePlayer();
	UpdatePlayerHp();
	UpdateBugIncrease();
	UpdateEnemy();
	UpdateBall();
	UpdateCatch();
	UpdateRandom();
	_Bug();

	if (GetKeyboardTrigger(DIK_M))
		SceneTransition(SCENE_MAP);


}

//-----�`�揈���֐�
void DrawGame(void)
{
	PLAYER* player = GetPlayer();

	DrawBG();
	DrawBugIncrease();
	DrawBug();
	DrawPlayerHp();
	if (player->drawdepth == true)
	{
		DrawPlayer();
		DrawEnemy();
		DrawBall();
	}
	if (player->drawdepth == false)
	{
		DrawBall();
		DrawEnemy();
		DrawPlayer();
	}
	DrawCatch();
	DrawRandom();
}

