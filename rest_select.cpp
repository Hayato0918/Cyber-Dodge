//休憩マス選択処理 [rest_select.cpp]
#include "rest_select.h"
//システム.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
//
#include "rest_command.h"
#include "rest_exit.h"
#include "sound.h"
#include "soundvolume_select.h" 

REST_SELECT rest_select;

HRESULT InitRestSelect(void)
{
	REST_HPUP* rest_hpup = GetRestCommandHP();
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();
	rest_select.sound = LoadSound("data/SE/cursormove.wav");
	SetVolume(rest_select.sound, soundvolume_select[1].count * 0.1f + 0.5f);

	rest_select.pos = D3DXVECTOR2(rest_hpup->pos.x, rest_hpup->pos.y);
	rest_select.size = D3DXVECTOR2(rest_hpup->size.x, rest_hpup->size.y);
	rest_select.count = 0;
	rest_select.texture = LoadTexture("data/TEXTURE/rest_frame.png");

	return S_OK;
}

void UninitRestSelect(void)
{

}

void UpdateRestSelect(void)
{
	REST_HPUP* rest_hpup = GetRestCommandHP();
	REST_STATUSUP* rest_statusup = GetRestCommandStatus();
	REST_EXIT* rest_exit = GetRestExit();

	if (PADUSE == 0)
	{
		if (IsButtonTriggered(0, BUTTON_LEFT) && rest_select.count > 0)		//上移動
		{
			PlaySound(rest_select.sound, 0.5f);
			rest_select.count -= 1;
		}
		if (IsButtonTriggered(0, BUTTON_RIGHT) && rest_select.count < 2)		//下移動
		{
			PlaySound(rest_select.sound, 0.5f);
			rest_select.count += 1;
		}
	}
	if (PADUSE == 1)
	{
		if (GetKeyboardTrigger(DIK_A) && rest_select.count > 0)		//上移動
			rest_select.count -= 1;
		if (GetKeyboardTrigger(DIK_D) && rest_select.count < 2)		//下移動
			rest_select.count += 1;
	}


	if (rest_select.count == 0)
	{
		rest_select.pos = D3DXVECTOR2(rest_hpup->pos.x, rest_hpup->pos.y);
		rest_select.size = D3DXVECTOR2(rest_hpup->size.x, rest_hpup->size.y);
	}
	if (rest_select.count == 1)
	{
		rest_select.pos = D3DXVECTOR2(rest_statusup->pos.x, rest_statusup->pos.y);
		rest_select.size = D3DXVECTOR2(rest_statusup->size.x, rest_statusup->size.y);
	}
	if (rest_select.count == 2)
	{
		rest_select.pos = D3DXVECTOR2(rest_exit->pos.x, rest_exit->pos.y);
		rest_select.size = D3DXVECTOR2(rest_exit->size.x, rest_exit->size.y);
	}


}

void DrawRestSelect(void)
{
	DrawSpriteLeftTop(rest_select.texture, rest_select.pos.x, rest_select.pos.y, rest_select.size.x, rest_select.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

REST_SELECT* GetRestSelect()
{
	return &rest_select;
}