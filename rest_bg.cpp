//ãxåeÉ}ÉXîwåièàóù [rest_bg.cpp]
#include "rest_bg.h"
//ÉVÉXÉeÉÄ.h
#include "texture.h"
#include "sprite.h"
#include "sound.h"
#include "soundvolume_select.h" 

REST_BG rest_bg;

HRESULT InitRestBG(void)
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	rest_bg.sound = LoadSound("data/BGM/restBGM.wav");
	SetVolume(rest_bg.sound, soundvolume_select[0].count * 0.1f + 0.5f);
	PlaySound(rest_bg.sound, -1);

	rest_bg.pos = D3DXVECTOR2(0.0f, 0.0f);
	rest_bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

	return S_OK;
}

void UninitRestBG(void)
{
	StopSoundAll();
}

void UpdateRestBG(void)
{

}

void DrawRestBG(void)
{
	DrawSpriteLeftTop(rest_bg.texture, rest_bg.pos.x, rest_bg.pos.y, rest_bg.size.x, rest_bg.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

REST_BG* GetRestBG()
{
	return &rest_bg;
}