//�^�C�g���R���e�j���[�{�^������ [title_continue.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}TITLE_CONTINUE;

//-----�v���g�^�C�v�錾
HRESULT InitTitleContinue(void);
void UninitTitleContinue(void);
void UpdateTitleContinue(void);
void DrawTitleContinue(void);

TITLE_CONTINUE* GetTitleContinue();