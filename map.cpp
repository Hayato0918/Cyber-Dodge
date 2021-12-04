//マップ処理 [map.cpp]
#include "map.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"

#include "map_point.h"
#include "map_hack.h"
#include "map_line.h"

//-----定数定義

//-----構造体宣言

//-----プロトタイプ宣言

//-----グローバル変数の定義


//-----初期化関数
void InitMap(void)
{
	InitMapPoint();
	InitMapPlayer();
	InitPolygon();
	InitMapHack();

}

//-----終了処理関数
void UninitMap()
{
	UninitMapPoint();
	UninitMapPlayer();
	UninitMapHack();
	UninitPolygon();

}

//-----更新処理をする関数
void UpdateMap(void)
{
	UpdateMapPoint();
	UpdateMapPlayer();
	UpdateMapHack();
	UpdatePolygon();

}

//-----描画処理関数
void DrawMap(void)
{
	DrawMapPoint();
	DrawMapPlayer();
	DrawPolygon();
	DrawMapHack();

}