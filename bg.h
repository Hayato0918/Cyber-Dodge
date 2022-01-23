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
	D3DXVECTOR2 clPos;
	D3DXVECTOR2 clSize;
	int clTexture;

	int sound;
	bool soundflag;
}BG;

//-----�v���g�^�C�v�錾
HRESULT InitBG(void);
void UninitBG(void);
void UpdateBG(void);
void DrawBG(void);
BG* GetBG(void);
void SetCenterLine(float x);