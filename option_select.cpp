//�ݒ�I������ [option_select.cpp]
#include "option_select.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include "scene.h"
#include "input.h"
//
#include "soundvolume_select.h"

OPTION_SELECT option_select;

HRESULT InitOptionSelect(void)
{
	option_select.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.093f, SCREEN_HEIGHT * 0.111f);		//1600:900��150:100
	option_select.size = D3DXVECTOR2(SCREEN_WIDTH * 0.056f, SCREEN_HEIGHT * 0.1f);		//1600:900��90:90
	option_select.count = 0;
	option_select.texture = LoadTexture("data/TEXTURE/option/option_select.png");

	return S_OK;
}

void UninitOptionSelect(void)
{

}

void UpdateOptionSelect(void)
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	if (PADUSE == 0)
	{
		if (soundvolume_select[0].soundchangeflag == false && soundvolume_select[1].soundchangeflag == false)
		{
			if (IsButtonTriggered(0, BUTTON_LEFT) && option_select.count > 0)		//���ړ�
			{
				option_select.pos.x -= SCREEN_WIDTH * 0.3f;	//1600:900��500
				option_select.count -= 1;
			}
			if (IsButtonTriggered(0, BUTTON_RIGHT) && option_select.count < 2)		//�E�ړ�
			{
				option_select.pos.x += SCREEN_WIDTH * 0.3f;	//1600:900��500
				option_select.count += 1;
			}
			if (IsButtonTriggered(0, BUTTON_A))
			{
				SceneTransition(SCENE_TITLE);
			}
		}
	}

	if (PADUSE == 1)
	{
		if (soundvolume_select[0].soundchangeflag == false && soundvolume_select[1].soundchangeflag == false)
		{
			if (GetKeyboardTrigger(DIK_A) && option_select.count > 0)		//���ړ�
			{
				option_select.pos.x -= SCREEN_WIDTH * 0.3f;	//1600:900��500
				option_select.count -= 1;
			}
			if (GetKeyboardTrigger(DIK_D) && option_select.count < 2)		//�E�ړ�
			{
				option_select.pos.x += SCREEN_WIDTH * 0.3f;	//1600:900��500
				option_select.count += 1;
			}
			if (GetKeyboardTrigger(DIK_M))
			{
				SceneTransition(SCENE_TITLE);
			}
		}
	}
}

void DrawOptionSelect(void)
{
	DrawSpriteLeftTop(option_select.texture, option_select.pos.x, option_select.pos.y, option_select.size.x, option_select.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

OPTION_SELECT* GetOptionSelect()
{
	return &option_select;
}