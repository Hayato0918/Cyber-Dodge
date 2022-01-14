/*==============================================================================

   シーン管理 [scene.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/

#include "scene.h"
#include "game.h"
#include "fade.h"
#include "input.h"
//テスト用
#include "Texture.h"
#include "sprite.h"

//タイトル.h
#include "title.h"
//設定.h
#include "option.h"
//名前決め.h
#include "name.h"
//マップ.h
#include "map.h"
#include "rest.h"
#include "shop.h"
#include "banner.h"
#include "deckmenu.h"
//戦闘.h
#include "game.h"
//クリア.h
#include "clear.h"
//ゲームオーバー.h
#include "gameover.h"
//セーブ機能.h
#include "save.h"

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

	case SCENE_OPTION:
		InitOption();
		break;

	case SCENE_NAME:
		InitName();
		break;

	case SCENE_MAP:
		InitMap();
		InitBanner();
		break;

	case SCENE_DECKMENU:
		InitDeckMenu();
		break;

	case SCENE_REST:
		InitRest();
		break;

	case SCENE_SHOP:
		InitShop();
		break;

	case SCENE_EVENT:
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

	case SCENE_OPTION:
		UninitOption();
		break;

	case SCENE_NAME:
		UninitName();
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

	case SCENE_SHOP:
		UninitShop();
		UninitBanner();
		break;

	case SCENE_EVENT:
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

	case SCENE_OPTION:
		UpdateOption();
		break;

	case SCENE_NAME:
		UpdateName();
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

	case SCENE_SHOP:
		UpdateShop();
		UpdateBanner();
		break;

	case SCENE_EVENT:
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

	case SCENE_OPTION:
		DrawOption();
		break;

	case SCENE_NAME:
		DrawName();
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

	case SCENE_SHOP:
		DrawShop();
		DrawBanner();
		break;

	case SCENE_EVENT:
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

	//テスト用
	//int masstexture;
	//masstexture = LoadTexture("data/TEXTURE/test/mass.png");
	//DrawSpriteLeftTop(masstexture, 0.f, 0.f, 1600.f, 900.f, 0.f, 0.f, 1.f, 1.f);

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
