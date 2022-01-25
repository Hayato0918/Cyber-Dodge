//�ݒ�I������ [option_select.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int count;
	int sound;
}OPTION_SELECT;

//-----�v���g�^�C�v�錾
HRESULT InitOptionSelect(void);
void UninitOptionSelect(void);
void UpdateOptionSelect(void);
void DrawOptionSelect(void);

OPTION_SELECT* GetOptionSelect();