//�^�C�g���I������ [title_select.h]
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
}TITLE_SELECT;


//-----�v���g�^�C�v�錾
HRESULT InitTitleSelect(void);
void UninitTitleSelect(void);
void UpdateTitleSelect(void);
void DrawTitleSelect(void);

TITLE_SELECT* GetTitleSelect();