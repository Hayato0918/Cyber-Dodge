//�x�e�}�X�ޏo���� [rest_exit.h]
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
}REST_EXIT;

//-----�v���g�^�C�v�錾
HRESULT InitRestExit(void);
void UninitRestExit(void);
void UpdateRestExit(void);
void DrawRestExit(void);

REST_EXIT* GetRestExit();