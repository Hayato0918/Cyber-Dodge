//�x�e�}�X�ꖇ�G���� [rest_picture.h]
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
}REST_PICTURE;

//-----�v���g�^�C�v�錾
HRESULT InitRestPicture(void);
void UninitRestPicture(void);
void UpdateRestPicture(void);
void DrawRestPicture(void);