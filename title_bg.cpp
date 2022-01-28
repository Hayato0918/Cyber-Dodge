//タイトルBG処理 [title_BG.cpp]
#include "title_bg.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include "sound.h"

#include "title_teamname.h"
#include "soundvolume_select.h"

//-----マクロ定義

//-----プロトタイプ宣言
TITLE_BG title_bg_white;
TITLE_BG title_bg_black;
TITLE_BG title_bg_game;

//-----グローバル変数

//-----初期化処理
HRESULT InitTitleBG(void)
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	title_bg_white.pos = D3DXVECTOR2(0.0f, 0.0f);
	title_bg_white.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

	title_bg_black.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
	title_bg_black.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	title_bg_black.a = 0.0f;
	title_bg_black.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, title_bg_black.a);

	title_bg_game.pos = D3DXVECTOR2(0.0f, 0.0f);
	title_bg_game.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	title_bg_game.drawflag = false;

	title_bg_game.sound = LoadSound("data/BGM/titleBGM.wav");
	title_bg_game.soundflag = false;
	title_bg_game.soundonce = false;

	SetVolume(title_bg_game.sound, soundvolume_select[0].count * 0.1f + 0.5f);

	return S_OK;
}

//-----終了処理
void UninitTitleBG(void)
{
	StopSoundAll();
}

//-----更新処理
void UpdateTitleBG(void)
{
	TITLE_TEAMNAME* title_teamname = GetTitleTeamName();

	title_bg_black.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, title_bg_black.a);
	if (title_teamname->time > 240)
		title_bg_black.a = title_bg_black.a + 0.016f;
	if (title_teamname->time > 300)
	{
		title_bg_game.drawflag = true;
		PlaySound(title_bg_game.sound, -1);
	}



}

//-----描画処理
void DrawTitleBG(void)
{
	DrawSpriteLeftTop(title_bg_white.texture, title_bg_white.pos.x, title_bg_white.pos.y, title_bg_white.size.x, title_bg_white.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
	DrawSpriteColor(title_bg_black.texture, title_bg_black.pos.x, title_bg_black.pos.y, title_bg_black.size.x, title_bg_black.size.y,
		0.0f, 0.0f, 1.0f, 1.0f, title_bg_black.color);
	if(title_bg_game.drawflag == true)
		DrawSpriteLeftTop(title_bg_game.texture, title_bg_game.pos.x, title_bg_game.pos.y, title_bg_game.size.x, title_bg_game.size.y,
			0.0f, 0.0f, 1.0f, 1.0f);
}

TITLE_BG* GetTitleBG()
{
	return &title_bg_game;
	return &title_bg_white;
	return &title_bg_black;
}