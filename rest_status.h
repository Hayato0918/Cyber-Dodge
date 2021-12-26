//�x�e�}�X�X�e�[�^�X�\������ [rest_status.h]
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
}REST_STATUS;

//-----�v���g�^�C�v�錾
HRESULT InitRestStatus(void);
void UninitRestStatus(void);
void UpdateRestStatus(void);
void DrawRestStatus(void);