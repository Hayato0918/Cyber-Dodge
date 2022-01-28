//�w�i���� [bg.cpp]
#include "bg.h"
#include "texture.h"
#include "sprite.h"
#include "areaChange.h"
#include "sound.h"
#include "soundvolume_select.h"

#include "bugincrease.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BG bg;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBG(void)
{
	SOUNDVOLUME_SELECT* soundvolume_select = GetSoundVolumeSelect();

	bg.pos = D3DXVECTOR2(0.0f, 0.0f);
	bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

	bg.clPos = D3DXVECTOR2(bg.size.x / 2, bg.pos.y + bg.size.y / 2);
	bg.clSize = D3DXVECTOR2(SCREEN_WIDTH * 0.00625f, bg.size.y);
	//bg.clTexture = LoadTexture("data/TEXTURE/gym_centerline.png");

	bg.sound = LoadSound("data/BGM/battleBGM.wav");
	bg.soundflag = false;
	SetVolume(bg.sound, soundvolume_select[0].count * 0.1f + 0.5f);
	PlaySound(bg.sound, -1);



	return S_OK;
}

//-----�I������
void UninitBG(void)
{
	StopSoundAll();
}

//-----�X�V����
void UpdateBG(void)
{
	BUG* bug = GetBugIncrease();

	if (bug->breakflag == true)
	{
		bg.soundflag = true;
		StopSound(bg.sound);
	}

	if (bg.soundflag == true)
	{
		PlaySound(bg.sound, -1);
		bg.soundflag = false;
	}

}

//-----�`�揈��
void DrawBG(void)
{
	DrawSpriteLeftTop(bg.texture, bg.pos.x, bg.pos.y, bg.size.x, bg.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	DrawSpriteColor(bg.clTexture, bg.clPos.x, bg.clPos.y, bg.clSize.x, bg.clSize.y, 0.0f, 0.0f, 1.0f, 1.0f,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
}

BG* GetBG(void)
{
	return &bg;
}

void SetCenterLine(float x)
{
	bg.clPos.x = x;
}