/*==============================================================================

   �V�[���Ǘ� [scene.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/

#include "scene.h"
#include "game.h"
#include "fade.h"
#include "input.h"

#include "title.h"
#include "map.h"
#include "banner.h"
#include "rest.h"
#include "game.h"
#include "clear.h"
#include "deckmenu.h"
#include "gameover.h"
#include "save.h"

/*------------------------------------------------------------------------------
   �萔��`
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   �\���̐錾
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   �v���g�^�C�v�錾
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   �O���[�o���ϐ��̒�`
------------------------------------------------------------------------------*/
static SCENE g_SceneIndex = SCENE_NONE;
static SCENE g_SceneNextIndex = g_SceneIndex;


/*------------------------------------------------------------------------------
   �������֐�
------------------------------------------------------------------------------*/
void InitScene(SCENE index)
{
	g_SceneIndex = g_SceneNextIndex = index;

	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		InitTitle();
		break;

	case SCENE_MAP:
		InitMap();
		InitBanner();
		break;

	case SCENE_DECKMENU:
		InitDeckMenu();
		InitBanner();
		break;

	case SCENE_REST:
		InitRest();
		InitBanner();
		break;

	case SCENE_GAME:
		InitGame();
		break;

	case SCENE_CLEAR:
		InitClear();
		break;

	case SCENE_GAMEOVER:
		InitGameOver();
		break;
	}
}

/*------------------------------------------------------------------------------
   �I������������֐�
------------------------------------------------------------------------------*/
void UninitScene(void)
{
	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		UninitTitle();
		break;

	case SCENE_MAP:
		UninitMap();
		UninitBanner();
		break;

	case SCENE_DECKMENU:
		UninitDeckMenu();
		UninitBanner();
		break;

	case SCENE_REST:
		UninitRest();
		UninitBanner();
		break;

	case SCENE_GAME:
		UninitGame();
		break;

	case SCENE_CLEAR:
		UninitClear();
		break;

	case SCENE_GAMEOVER:
		UninitGameOver();
		break;
	}
}

/*------------------------------------------------------------------------------
   �X�V����������֐�
------------------------------------------------------------------------------*/
void UpdateScene(void)
{
	switch( g_SceneIndex ) 
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		UpdateTitle();
		break;

	case SCENE_MAP:
		UpdateMap();
		UpdateBanner();
		break;

	case SCENE_DECKMENU:
		UpdateDeckMenu();
		UpdateBanner();
		break;

	case SCENE_REST:
		UpdateRest();
		UpdateBanner();
		break;

	case SCENE_GAME:
		UpdateGame();
		break;

	case SCENE_CLEAR:
		UpdateClear();
		break;

	case SCENE_GAMEOVER:
		UpdateGameOver();
		break;
	}

	UpdateFade();
}

/*------------------------------------------------------------------------------
   �`�揈��������֐�
------------------------------------------------------------------------------*/
void DrawScene(void)
{
	switch( g_SceneIndex )
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		DrawTitle();
		break;

	case SCENE_MAP:
		DrawMap();
		DrawBanner();
		break;

	case SCENE_DECKMENU:
		DrawDeckMenu();
		DrawBanner();
		break;

	case SCENE_REST:
		DrawRest();
		DrawBanner();
		break;

	case SCENE_GAME:
		DrawGame();
		break;

	case SCENE_CLEAR:
		DrawClear();
		break;

	case SCENE_GAMEOVER:
		DrawGameOver();
		break;
	}

	DrawFade();
}

/*------------------------------------------------------------------------------
   �V�[���J�ڂ�v������֐�
------------------------------------------------------------------------------*/
void SetScene(SCENE index)
{
	//�J�ڐ�V�[����ݒ肷��
	g_SceneNextIndex = index;
}

/*------------------------------------------------------------------------------
   �J�ڂ�v��������ꍇ�ɃV�[����؂�ւ���֐�
------------------------------------------------------------------------------*/
void CheckScene(void)
{
	//���݂̃V�[���ƑJ�ڐ�V�[��������Ă�����
	if( g_SceneIndex != g_SceneNextIndex )
	{
		//���݂̃V�[�����I��������
		UninitScene();
		
		//�J�ڐ�V�[���̏������������s��
		InitScene(g_SceneNextIndex);
	}
}
