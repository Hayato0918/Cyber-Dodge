//�N���A���� [clear.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}CLEAR;

//-----�v���g�^�C�v�錾
HRESULT InitClear(void);
void UninitClear(void);
void UpdateClear(void);
void DrawClear(void);