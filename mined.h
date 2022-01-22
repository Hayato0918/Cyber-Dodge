//�}�C���h�u���[������ [mined.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
}MINED;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
}MINEDPOINT;

//-----�v���g�^�C�v�錾
void InitMined(void);
void UninitMined(void);
void UpdateMined(void);
void DrawMined(void);