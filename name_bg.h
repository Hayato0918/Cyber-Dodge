//���O����_�w�i���� [name_bg.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}NAME_BG;

//-----�v���g�^�C�v�錾
HRESULT InitNameBG(void);
void UninitNameBG(void);
void UpdateNameBG(void);
void DrawNameBG(void);