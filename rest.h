//�x�e�}�X���� [rest.h]

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
}REST;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
	int count;
}RESTPOINT;


//-----�v���g�^�C�v�錾
void InitRest(void);
void UninitRest(void);
void UpdateRest(void);
void DrawRest(void);