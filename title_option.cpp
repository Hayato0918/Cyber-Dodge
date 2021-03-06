//タイトル設定ボタン処理 [title_exit.cpp]
#include "title_option.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include "sound.h"

#include "soundvolume_select.h"

#include "title_bg.h"
#include "title_select.h"

//-----マクロ定義

//-----プロトタイプ宣言
TITLE_OPTION title_option;

//-----グローバル変数

//-----初期化処理
HRESULT InitTitleOption(void)
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	title_option.sound = LoadSound("data/SE/titleselect.wav");
	SetVolume(title_option.sound, soundvolume_select[1].count * 0.1f + 0.5f);

	title_option.pos = D3DXVECTOR2(1300.f, 740.f);	//1600:900→1240,740
	title_option.size = D3DXVECTOR2(260.f, 70.f);	//1600:900→380,70

	return S_OK;
}

//-----終了処理
void UninitTitleOption(void)
{

}

//-----更新処理
void UpdateTitleOption(void)
{
	TITLE_SELECT* title_select = GetTitleSelect();
	TITLE_BG* title_bg = GetTitleBG();

	//if (PADUSE == 0)
	//{
	//	if (title_select->count == 3 && IsButtonTriggered(0, BUTTON_Y) && title_bg->drawflag == true)
	//	{
	//		PlaySound(title_option.sound, 0.5f);
	//		SceneTransition(SCENE_OPTION);
	//	}
	//}

	//if (PADUSE == 1)
	//{
	//	if (title_select->count == 3 && GetKeyboardTrigger(DIK_RETURN) && title_bg->drawflag == true)
	//	{
	//		PlaySound(title_option.sound, 0.5f);
	//		SceneTransition(SCENE_OPTION);
	//	}
	//}
}

//-----描画処理
void DrawTitleOption(void)
{
	TITLE_BG* title_bg = GetTitleBG();

	if (title_bg->drawflag == true)
		DrawSpriteLeftTop(title_option.texture, title_option.pos.x, title_option.pos.y, title_option.size.x, title_option.size.y,
			0.0f, 0.0f, 1.0f, 1.0f);
}

TITLE_OPTION* GetTitleOption()
{
	return &title_option;
}