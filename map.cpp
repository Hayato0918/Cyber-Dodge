//マップ処理 [map.cpp]
#include "map.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"

#include "map_bg.h"
#include "map_line.h"
#include "map_point.h"
#include "map_player.h"
#include "map_hack.h"

#include "banner.h"
#include "save.h"

//-----定数定義

//-----構造体宣言

//-----プロトタイプ宣言

//-----グローバル変数の定義


//-----初期化関数
HRESULT InitMap(void)
{
	InitMapBG();
	InitMapLine();
	InitMapPoint();
	InitMapPlayer();
	InitMapHack();

	return S_OK;
}

//-----終了処理関数
void UninitMap()
{
	UninitMapPoint();
	UninitMapPlayer();
	UninitMapHack();
	UninitMapLine();
	UninitMapBG();
}

//-----更新処理をする関数
void UpdateMap(void)
{
	UpdateMapBG();
	UpdateMapLine();
	UpdateMapPoint();
	UpdateMapPlayer();
	UpdateMapHack();

	if (GetKeyboardTrigger(DIK_1))
		Save();
	if (GetKeyboardTrigger(DIK_2))
		Load();
	if (GetKeyboardTrigger(DIK_3))
		SceneTransition(SCENE_DECKMENU);
}

//-----描画処理関数
void DrawMap(void)
{
	DrawMapBG();
	DrawMapLine();
	DrawMapPoint();
	DrawMapPlayer();
	DrawMapHack();
}