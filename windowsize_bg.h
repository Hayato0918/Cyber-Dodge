//�E�B���h�E�T�C�Y_�w�i���� [windowsize_bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}WINDOWSIZE_BG;


//-----�v���g�^�C�v�錾
HRESULT InitWindowSizeBG(void);
void UninitWindowSizeBG(void);
void UpdateWindowSizeBG(void);
void DrawWindowSizeBG(void);