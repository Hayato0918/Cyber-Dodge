//タイトルスタートボタン処理 [title_gamestart.cpp]
#include "title_gamestart.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include "sound.h"

#include "title_bg.h"
#include "title_select.h"
#include "soundvolume_select.h"

//-----マクロ定義

//-----プロトタイプ宣言
TITLE_START title_start;

//-----グローバル変数

//-----初期化処理
HRESULT InitTitleStart(void)
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();
	title_start.sound = LoadSound("data/SE/gamestart.wav");
	SetVolume(title_start.sound, soundvolume_select[1].count * 0.1f + 0.5f);

	title_start.pos = D3DXVECTOR2(1180.f, 530.f);	//1600:900→1180,600
	title_start.size = D3DXVECTOR2(380.f, 70.f);	//1600:900→380,70

	return S_OK;
}

//-----終了処理
void UninitTitleStart(void)
{
	StopSoundAll();
}

//-----更新処理
void UpdateTitleStart(void)
{
	TITLE_BG* title_bg = GetTitleBG();
	TITLE_SELECT* title_select = GetTitleSelect();

	if (PADUSE == 0)
	{
		if (title_select->count == 0 && IsButtonTriggered(0, BUTTON_Y) && title_bg->drawflag == true)
		{
			PlaySound(title_start.sound, 0.5f);
			SceneTransition(SCENE_NAME);
		}
	}

	if (PADUSE == 1)
	{
		if (title_select->count == 0 && GetKeyboardTrigger(DIK_RETURN) && title_bg->drawflag == true)
		{
			PlaySound(title_start.sound, 0.5f);
			SceneTransition(SCENE_NAME);
		}
	}
}

//-----描画処理
void DrawTitleStart(void)
{
	TITLE_BG* title_bg = GetTitleBG();

	if(title_bg->drawflag == true)
	DrawSpriteLeftTop(title_start.texture, title_start.pos.x, title_start.pos.y, title_start.size.x, title_start.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
}

TITLE_START* GetTitleStart()
{
	return &title_start;
}