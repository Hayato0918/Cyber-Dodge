//�n�b�L���O�G�t�F�N�g���� [hackeffect.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v;
	int texture;
	float animetime;
	bool drawflag;
}HACKEFFECT;

//-----�v���g�^�C�v�錾
HRESULT InitHackEffect(void);
void UninitHackEffect(void);
void UpdateHackEffect(void);
void DrawHackEffect(void);
HACKEFFECT* GetHackEffect();