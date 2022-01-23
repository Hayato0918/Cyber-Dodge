//�T�E���h�{�����[��bg���� [soundvolume_bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}BGM;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}SE;

//-----�v���g�^�C�v�錾
HRESULT InitSoundVolumeBG(void);
void UninitSoundVolumeBG(void);
void UpdateSoundVolumeBG(void);
void DrawSoundVolumeBG(void);

BGM* GetBGM();
SE* GetSE();