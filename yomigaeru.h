//�h�鑝�����u���� [yomigaeru.h]

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
}YOMIGAERU;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
	int count;
	int minus;				//�I�����̃}�X�Ԃ̋���
}YOMIGAERUPOINT;

//-----�v���g�^�C�v�錾
void InitYomigaeru(void);
void UninitYomigaeru(void);
void UpdateYomigaeru(void);
void DrawYomigaeru(void);