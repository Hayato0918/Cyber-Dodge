//�}�b�v�ړ����� [map_hack.cpp]
#include "map_hack.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include "sound.h"

#include "hackeffect.h"
#include "map_save_bg.h"

#include "map.h"
#include "soundvolume_select.h"
#include "hackeffect.h"


//-----�}�N����`

//-----�v���g�^�C�v�錾
MAP_HACK map_hack;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitMapHack(void)
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	map_hack.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.203f, SCREEN_HEIGHT * 0.535f);		//1600:900��325:450
	map_hack.size = D3DXVECTOR2(SCREEN_WIDTH * 0.375f, SCREEN_HEIGHT * 0.9f);		//1600:900��600:850

	map_hack.frame_pos = D3DXVECTOR2(SCREEN_WIDTH * 0.219f, SCREEN_HEIGHT * 0.33f);	//1600:900��350,250
	map_hack.frame_size = D3DXVECTOR2(SCREEN_WIDTH * 0.28125f, SCREEN_HEIGHT * 0.111f);		//1600:900��450,100

	map_hack.UDcount = 0;
	map_hack.isUse = false;

	map_hack.sound = LoadSound("data/SE/hackmenu.wav");
	SetVolume(map_hack.sound, soundvolume_select[1].count * 0.1f + 0.5f);

	InitHackEffect();

	return S_OK;
}

//-----�I������
void UninitMapHack(void)
{
	UninitHackEffect();
}

//-----�X�V����
void UpdateMapHack(void)
{
	MAPSAVE_BG* map_save = GetMapSaveBG();


	if (map_save->drawflag == false)
	{
		if (PADUSE == 1)
		{
			//TAB�L�[�ŕ\����\���؂�ւ�
			if (GetKeyboardTrigger(DIK_TAB))
			{
				PlaySound(map_hack.sound, 0.5f);
				if (map_hack.isUse == true)
					map_hack.isUse = false;
				else
					map_hack.isUse = true;
			}

			//�ǂ̃V�[���ɕς��邩��I������
			if (map_hack.isUse == true)
			{
				if (GetKeyboardTrigger(DIK_W) && map_hack.UDcount > 0)
				{
					map_hack.UDcount -= 1;
					map_hack.frame_pos.y -= SCREEN_HEIGHT * 0.132f;		//1600:900��115
				}
				if (GetKeyboardTrigger(DIK_S) && map_hack.UDcount < 4)
				{
					map_hack.UDcount += 1;
					map_hack.frame_pos.y += SCREEN_HEIGHT * 0.132f;		//1600:900��115
				}
			}
		}

		if (PADUSE == 0)
		{
			//TAB�L�[�ŕ\����\���؂�ւ�
			if (IsButtonTriggered(0, BUTTON_L))
			{
				PlaySound(map_hack.sound, 0.5f);
				if (map_hack.isUse == true)
					map_hack.isUse = false;
				else
					map_hack.isUse = true;
			}

			//�ǂ̃V�[���ɕς��邩��I������
			if (map_hack.isUse == true)
			{
				if (IsButtonTriggered(0, BUTTON_UP) && map_hack.UDcount > 0)
				{
					map_hack.UDcount -= 1;
					map_hack.frame_pos.y -= SCREEN_HEIGHT * 0.128f;		//1600:900��115
				}
				if (IsButtonTriggered(0, BUTTON_DOWN) && map_hack.UDcount < 4)
				{
					map_hack.UDcount += 1;
					map_hack.frame_pos.y += SCREEN_HEIGHT * 0.128f;		//1600:900��115
				}
			}
		}
	}

	UpdateHackEffect();
}

//-----�`�揈��
void DrawMapHack(void)
{
	if (map_hack.isUse == true)
	{
		DrawSpriteColor(map_hack.texture, map_hack.pos.x, map_hack.pos.y, map_hack.size.x, map_hack.size.y, 0.0f, 0.0f, 1.0f, 1.0f,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.8f));
		DrawSpriteColor(map_hack.frametexture, map_hack.frame_pos.x, map_hack.frame_pos.y, map_hack.frame_size.x, map_hack.frame_size.y, 0.0f, 0.0f, 1.0f, 1.0f,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.8f));
	}

	DrawHackEffect();
}

MAP_HACK* GetMapHack()
{
	return &map_hack;
}
