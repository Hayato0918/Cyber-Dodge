//�ݒ�_�w�i���� [option_bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}OPTION_BG;


//-----�v���g�^�C�v�錾
HRESULT InitOptionBG(void);
void UninitOptionBG(void);
void UpdateOptionBG(void);
void DrawOptionBG(void);