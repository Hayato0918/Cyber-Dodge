//�T�E���h�{�����[���I������ [soundvolume_select.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	float count;
	bool soundchangeflag;

	bool exitflag;
}SOUNDVOLUME_SELECT;

//-----�v���g�^�C�v�錾
HRESULT InitSoundVolumeSelect(void);
void UninitSoundVolumeSelect(void);
void UpdateSoundVolumeSelect(void);
void DrawSoundVolumeSelect(void);

SOUNDVOLUME_SELECT* GetSoundVolumeSelect(void);