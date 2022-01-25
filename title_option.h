//�^�C�g���ݒ�{�^������ [title_option.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int sound;
}TITLE_OPTION;

//-----�v���g�^�C�v�錾
HRESULT InitTitleOption(void);
void UninitTitleOption(void);
void UpdateTitleOption(void);
void DrawTitleOption(void);

TITLE_OPTION* GetTitleOption();