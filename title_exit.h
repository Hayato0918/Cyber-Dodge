//�^�C�g���I���{�^������ [title_exit.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}TITLE_EXIT;

//-----�v���g�^�C�v�錾
HRESULT InitTitleExit(void);
void UninitTitleExit(void);
void UpdateTitleExit(void);
void DrawTitleExit(void);

TITLE_EXIT* GetTitleExit();