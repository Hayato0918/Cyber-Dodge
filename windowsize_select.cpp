//ウィンドウサイズ選択処理 [windowsize_select.cpp]
#include "windowsize_select.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "sound.h"
#include "soundvolume_select.h" 
//

WINDOWSIZE_SELECT windowsize_select;

HRESULT InitWindowSizeSelect(void)
{
	windowsize_select.pos = D3DXVECTOR2(350.f, 350.f);		//1600:900→150:100
	windowsize_select.size = D3DXVECTOR2(SCREEN_WIDTH * 0.056f, SCREEN_HEIGHT * 0.1f);		//1600:900→90:90
	windowsize_select.count = 0;
	windowsize_select.texture = LoadTexture("data/TEXTURE/option/option_select.png");

	windowsize_select.x = 1600;
	windowsize_select.y = 900;

	return S_OK;
}

void UninitWindowSizeSelect(void)
{

}

void UpdateWindowSizeSelect(void)
{
	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_UP) && windowsize_select.count > 0)		//上移動
		{
			windowsize_select.pos.y -= 100;	//1600:900→500
			windowsize_select.count -= 1;
		}
		if (IsButtonTriggered(0, BUTTON_DOWN) && windowsize_select.count < 3)		//下移動
		{
			windowsize_select.pos.y += 100;	//1600:900→500
			windowsize_select.count += 1;
		}
		if (IsButtonTriggered(0, BUTTON_Y) && windowsize_select.count == 1)
		{
			windowsize_select.x = 1920;
			windowsize_select.y = 1080;
		}
		if (IsButtonTriggered(0, BUTTON_Y) && windowsize_select.count == 2)
		{
			windowsize_select.x = 1600;
			windowsize_select.y = 900;
		}
		if (IsButtonTriggered(0, BUTTON_Y) && windowsize_select.count == 3)
		{
			windowsize_select.x = 1280;
			windowsize_select.y = 720;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_W) && windowsize_select.count > 0)		//上移動
		{
			windowsize_select.pos.y -= 100;	//1600:900→500
			windowsize_select.count -= 1;
		}
		if (GetKeyboardTrigger(DIK_S) && windowsize_select.count < 3)		//下移動
		{
			windowsize_select.pos.y += 100;	//1600:900→500
			windowsize_select.count += 1;
		}
		if (GetKeyboardTrigger(DIK_RETURN) && windowsize_select.count == 1)
		{
			windowsize_select.x = 1920;
			windowsize_select.y = 1080;
		}
		if (GetKeyboardTrigger(DIK_RETURN) && windowsize_select.count == 2)
		{
			windowsize_select.x = 1600;
			windowsize_select.y = 900;
		}
		if (GetKeyboardTrigger(DIK_RETURN) && windowsize_select.count == 3)
		{
			windowsize_select.x = 1280;
			windowsize_select.y = 720;
		}
	}
}

void DrawWindowSizeSelect(void)
{
	DrawSpriteLeftTop(windowsize_select.texture, windowsize_select.pos.x, windowsize_select.pos.y, windowsize_select.size.x, windowsize_select.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

WINDOWSIZE_SELECT* GetWindowSizeSelect()
{
	return &windowsize_select;
}