//名前決め_キーボード処理 [name_keyboard.cpp]
#include "name_keyboard.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "Texture.h"
#include "sprite.h"
#include "sound.h"

#include "name_select.h"
#include "name_input.h"

//-----定数定義

//-----構造体宣言

//-----プロトタイプ宣言
NAME_KEYBOARD name_keyboard;

//-----グローバル変数の定義


//-----初期化関数
HRESULT InitNameKeyboard(void)
{
	name_keyboard.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.219f, SCREEN_HEIGHT * 0.555f);	//1600:900→350,500
	name_keyboard.size = D3DXVECTOR2(SCREEN_WIDTH * 0.562f, SCREEN_HEIGHT * 0.333f);	//1600:900→900,300
	name_keyboard.texture = LoadTexture("data/TEXTURE/name/keyboard.png");
	name_keyboard.wardnum = 0;

	return S_OK;
}

//-----終了処理関数
void UninitNameKeyboard(void)
{

}

//-----更新処理をする関数
void UpdateNameKeyboard(void)
{
	NAME_SELECT* name_select = GetNameSelect();
	NAME_INPUTWARD* name_inputward = GetNameInputWard();

	if (name_inputward[name_keyboard.wardnum].drawflag == false && name_keyboard.wardnum < 8)
	{
		if (GetKeyboardTrigger(DIK_RETURN))
		{
					name_inputward[name_keyboard.wardnum].u = 0.037037037f * name_select->LRcount + 0.333333333f * name_select->UDcount;
					name_inputward[name_keyboard.wardnum].drawflag = true;
					name_keyboard.wardnum = name_keyboard.wardnum + 1;
		}
	}

	//決定処理
	if (GetKeyboardTrigger(DIK_RETURN))
	{
		if (name_select->UDcount == 2)
		{
			if (name_select->LRcount == 8)
				SceneTransition(SCENE_MAP);
		}
	}
}

//-----描画処理関数
void DrawNameKeyboard(void)
{
	DrawSpriteLeftTop(name_keyboard.texture, name_keyboard.pos.x, name_keyboard.pos.y, name_keyboard.size.x, name_keyboard.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

NAME_KEYBOARD* GetNameKeyboard()
{
	return &name_keyboard;
}