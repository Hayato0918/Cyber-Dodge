//ウィンドウサイズ処理 [windowsize.cpp]
#include "windowsize.h"
//
#include "windowsize_bg.h"
#include "windowsize_select.h"

#include "option_select.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数

//-----初期化処理
HRESULT InitWindowSize(void)
{
	OPTION_SELECT* option_select = GetOptionSelect();

	if (option_select->count == 0)
	{
		InitWindowSizeBG();
		InitWindowSizeSelect();
	}

	return S_OK;
}

//-----終了処理
void UninitWindowSize(void)
{
	OPTION_SELECT* option_select = GetOptionSelect();

	if (option_select->count == 0)
	{
		UninitWindowSizeBG();
		UninitWindowSizeSelect();
	}

}

//-----更新処理
void UpdateWindowSize(void)
{
	OPTION_SELECT* option_select = GetOptionSelect();

	if (option_select->count == 0)
	{
		UpdateWindowSizeBG();
		UpdateWindowSizeSelect();
	}

}

//-----描画処理
void DrawWindowSize(void)
{
	OPTION_SELECT* option_select = GetOptionSelect();

	if (option_select->count == 0)
	{
		DrawWindowSizeBG();
		DrawWindowSizeSelect();
	}

}