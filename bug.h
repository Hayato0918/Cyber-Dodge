//�o�O�Q�[�W���� [bug.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	int gaugeonce;		//�Q�[�W�̊g��(x5)

	D3DXVECTOR2 pos;
	D3DXVECTOR2 framesize;
	int frametexture;

	D3DXVECTOR2 gaugesize;
	int gaugetexture;
}BUG;

//-----�v���g�^�C�v�錾
HRESULT InitBug(void);
void UninitBug(void);
void UpdateBug(void);
void DrawBug(void);

BUG* GetBug();