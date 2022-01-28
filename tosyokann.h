//�d�]�}���ُ��� [tosyokann.h]

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
}TOSYOKANN;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
	int count;
	int minus;				//�I�����̃}�X�Ԃ̋���
}TOSYOKANNPOINT;

//-----�v���g�^�C�v�錾
void InitTosyokann(void);
void UninitTosyokann(void);
void UpdateTosyokann(void);
void DrawTosyokann(void);

TOSYOKANN* GetTosyo();
TOSYOKANNPOINT* GetTosyPoint();