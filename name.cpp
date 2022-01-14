//名前決め処理 [name.cpp]
#include "name.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"

#include "name_bg.h"
#include "name_keyboard.h"
#include "name_input.h"
#include "name_select.h"

//-----定数定義

//-----構造体宣言

//-----プロトタイプ宣言

//-----グローバル変数の定義


//-----初期化関数
HRESULT InitName(void)
{
	InitNameBG();
	InitNameKeyboard();
	InitNameInput();
	InitNameSelect();

	return S_OK;
}

//-----終了処理関数
void UninitName()
{
	UninitNameBG();
	UninitNameKeyboard();
	UninitNameInput();
	UninitNameSelect();
}

//-----更新処理をする関数
void UpdateName(void)
{
	UpdateNameBG();
	UpdateNameKeyboard();
	UpdateNameInput();
	UpdateNameSelect();
}

//-----描画処理関数
void DrawName(void)
{
	DrawNameBG();
	DrawNameKeyboard();
	DrawNameInput();
	DrawNameSelect();
}