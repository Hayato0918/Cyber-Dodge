//�w�i���� [bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}BG;

//-----�v���g�^�C�v�錾
HRESULT InitBG(void);
void UninitBG(void);
void UpdateBG(void);
void DrawBG(void);