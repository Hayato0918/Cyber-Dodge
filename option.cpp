//設定処理 [option.cpp]
#include "option.h"
//
#include "option_bg.h"
#include "option_select.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数

//-----初期化処理
HRESULT InitOption(void)
{
	InitOptionBG();
	InitOptionSelect();

	return S_OK;
}

//-----終了処理
void UninitOption(void)
{
	UninitOptionBG();
	UninitOptionSelect();

}

//-----更新処理
void UpdateOption(void)
{
	UpdateOptionBG();
	UpdateOptionSelect();

}

//-----描画処理
void DrawOption(void)
{
	DrawOptionBG();
	DrawOptionSelect();

}