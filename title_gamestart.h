//�^�C�g���X�^�[�g�{�^������ [title_gamestart.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}TITLE_START;

//-----�v���g�^�C�v�錾
HRESULT InitTitleStart(void);
void UninitTitleStart(void);
void UpdateTitleStart(void);
void DrawTitleStart(void);

TITLE_START* GetTitleStart();