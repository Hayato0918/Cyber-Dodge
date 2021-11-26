/*==============================================================================

   シーン管理 [scene.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/

#include "scene.h"
#include "game.h"
#include "fade.h"

#include "title.h"
#include "map.h"
#include "map_player.h"
#include "game.h"
#include "clear.h"
#include "gameover.h"

/*------------------------------------------------------------------------------
   定数定義
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   構造体宣言
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   プロトタイプ宣言
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   グローバル変数の定義
------------------------------------------------------------------------------*/
static SCENE g_SceneIndex = SCENE_NONE;
static SCENE g_SceneNextIndex = g_SceneIndex;


/*------------------------------------------------------------------------------
   初期化関数
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
		InitMapPlayer();
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
   終了処理をする関数
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
		UninitMapPlayer();
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
   更新処理をする関数
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
		UpdateMapPlayer();
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
   描画処理をする関数
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
		DrawMapPlayer();
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
   シーン遷移を要求する関数
------------------------------------------------------------------------------*/
void SetScene(SCENE index)
{
	//遷移先シーンを設定する
	g_SceneNextIndex = index;
}

/*------------------------------------------------------------------------------
   遷移を要求がある場合にシーンを切り替える関数
------------------------------------------------------------------------------*/
void CheckScene(void)
{
	//現在のシーンと遷移先シーンが違っていたら
	if( g_SceneIndex != g_SceneNextIndex )
	{
		//現在のシーンを終了させる
		UninitScene();
		
		//遷移先シーンの初期化処理を行う
		InitScene(g_SceneNextIndex);
	}
}
