//�Q�[������ [game.cpp]

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

//-----�萔��`

//-----�\���̐錾

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ��̒�`


//-----�������֐�
void InitGame(void)
{
	InitBG();
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
	UninitBG();
}

//-----�X�V����������֐�
void UpdateGame(void)
{
	UpdatePlayer();
	UpdateEnemy();
	UpdateBall();
	UpdateCatch();



	//�X�y�[�X�L�[��������Ă��āA�t�F�[�h�������ł͂Ȃ��Ƃ�
	if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE) {

		//RESULT�ֈڍs����
		//SceneTransition(SCENE_RESULT);
	}
}

//-----�`�揈���֐�
void DrawGame(void)
{
	DrawBG();
	DrawPlayer();
	DrawEnemy();
	DrawBall();
	DrawCatch();


}

