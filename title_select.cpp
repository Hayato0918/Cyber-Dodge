//タイトル選択処理 [title_select.cpp]
#include "title_select.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "sound.h"
//
#include "title_bg.h"
#include "title_gamestart.h"
#include "title_continue.h"
#include "title_option.h"
#include "title_exit.h"
#include "soundvolume_select.h"

TITLE_SELECT title_select;

HRESULT InitTitleSelect(void)
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();
	TITLE_START* title_start = GetTitleStart();

	title_select.sound = LoadSound("data/SE/cursormove.wav");
	SetVolume(title_select.sound, soundvolume_select[1].count * 0.1f + 0.5f);

	title_select.pos = D3DXVECTOR2(title_start->pos.x, title_start->pos.y);
	title_select.size = D3DXVECTOR2(title_start->size.x, title_start->size.y);
	title_select.count = 0;
	title_select.texture = LoadTexture("data/TEXTURE/rest_frame.png");

	return S_OK;
}

void UninitTitleSelect(void)
{

}

void UpdateTitleSelect(void)
{
	TITLE_START* title_start = GetTitleStart();
	TITLE_CONTINUE* title_continue = GetTitleContinue();
	TITLE_OPTION* title_option = GetTitleOption();
	TITLE_EXIT* title_exit = GetTitleExit();

	if (PADUSE == 0)
	{
		//休憩マスの選択
		if (IsButtonTriggered(0, BUTTON_UP) && title_select.count > 0)
		{
			PlaySound(title_select.sound, 0.5f);
			title_select.count -= 1;
		}
		if (IsButtonTriggered(0, BUTTON_DOWN) && title_select.count < 3)
		{
			PlaySound(title_select.sound, 0.5f);
			title_select.count += 1;
		}
	}

	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_W) && title_select.count > 0)		//上移動
		{
			PlaySound(title_select.sound, 0.5f);
			title_select.count -= 1;
		}
		if (GetKeyboardTrigger(DIK_S) && title_select.count < 3)		//下移動
		{
			PlaySound(title_select.sound, 0.5f);
			title_select.count += 1;
		}
	}


	if (title_select.count == 0)
	{
		title_select.pos = D3DXVECTOR2(title_start->pos.x, title_start->pos.y);
		title_select.size = D3DXVECTOR2(title_start->size.x, title_start->size.y);
	}
	if (title_select.count == 1)
	{
		title_select.pos = D3DXVECTOR2(title_continue->pos.x, title_continue->pos.y);
		title_select.size = D3DXVECTOR2(title_continue->size.x, title_continue->size.y);
	}
	if (title_select.count == 2)
	{
		title_select.pos = D3DXVECTOR2(title_option->pos.x, title_option->pos.y);
		title_select.size = D3DXVECTOR2(title_option->size.x, title_option->size.y);
	}
	if (title_select.count == 3)
	{
		title_select.pos = D3DXVECTOR2(title_exit->pos.x, title_exit->pos.y);
		title_select.size = D3DXVECTOR2(title_exit->size.x, title_exit->size.y);
	}
}

void DrawTitleSelect(void)
{
	TITLE_BG* title_bg = GetTitleBG();

	if(title_bg->drawflag == true)
	DrawSpriteLeftTop(title_select.texture, title_select.pos.x, title_select.pos.y, title_select.size.x, title_select.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

TITLE_SELECT* GetTitleSelect()
{
	return &title_select;
}