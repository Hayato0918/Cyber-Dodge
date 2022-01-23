//名前決め_選択処理 [name_select.cpp]
#include "name_select.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
//
#include "name_keyboard.h"

NAME_SELECT name_select;

HRESULT InitNameSelect(void)
{
	NAME_KEYBOARD* name_keyboard = GetNameKeyboard();

	name_select.pos = D3DXVECTOR2(name_keyboard->pos.x, name_keyboard->pos.y);
	name_select.size = D3DXVECTOR2(name_keyboard->size.x / 9.f, name_keyboard->size.y / 3.f);
	name_select.LRcount = 0;
	name_select.UDcount = 0;
	name_select.texture = LoadTexture("data/TEXTURE/rest_frame.png");

	return S_OK;
}

void UninitNameSelect(void)
{

}

void UpdateNameSelect(void)
{
	NAME_KEYBOARD* name_keyboard = GetNameKeyboard();

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_UP) && name_select.UDcount > 0)		//上移動
		{
			name_select.UDcount -= 1;
			name_select.pos.y = name_select.pos.y - name_select.size.y;
		}
		if (IsButtonTriggered(0, BUTTON_DOWN) && name_select.UDcount < 2)		//下移動
		{
			name_select.UDcount += 1;
			name_select.pos.y = name_select.pos.y + name_select.size.y;
		}
		if (IsButtonTriggered(0, BUTTON_LEFT) && name_select.LRcount > 0)		//左移動
		{
			name_select.LRcount -= 1;
			name_select.pos.x = name_select.pos.x - name_select.size.x;
		}
		if (IsButtonTriggered(0, BUTTON_RIGHT) && name_select.LRcount < 8)		//右移動
		{
			name_select.LRcount += 1;
			name_select.pos.x = name_select.pos.x + name_select.size.x;
		}

	}
	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_W) && name_select.UDcount > 0)		//上移動
		{
			name_select.UDcount -= 1;
			name_select.pos.y = name_select.pos.y - name_select.size.y;
		}
		if (GetKeyboardTrigger(DIK_S) && name_select.UDcount < 2)		//下移動
		{
			name_select.UDcount += 1;
			name_select.pos.y = name_select.pos.y + name_select.size.y;
		}
		if (GetKeyboardTrigger(DIK_A) && name_select.LRcount > 0)		//左移動
		{
			name_select.LRcount -= 1;
			name_select.pos.x = name_select.pos.x - name_select.size.x;
		}
		if (GetKeyboardTrigger(DIK_D) && name_select.LRcount < 8)		//右移動
		{
			name_select.LRcount += 1;
			name_select.pos.x = name_select.pos.x + name_select.size.x;
		}
	}
}

void DrawNameSelect(void)
{
		DrawSpriteLeftTop(name_select.texture, name_select.pos.x, name_select.pos.y, name_select.size.x, name_select.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

NAME_SELECT* GetNameSelect()
{
	return &name_select;
}