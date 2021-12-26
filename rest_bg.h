//�x�e�}�X�w�i���� [rest_bg.h]
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
}REST_BG;

//-----�v���g�^�C�v�錾
HRESULT InitRestBG(void);
void UninitRestBG(void);
void UpdateRestBG(void);
void DrawRestBG(void);