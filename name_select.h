//���O����_�I������ [name_select.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int LRcount;
	int UDcount;
	int sound;
}NAME_SELECT;


//-----�v���g�^�C�v�錾
HRESULT InitNameSelect(void);
void UninitNameSelect(void);
void UpdateNameSelect(void);
void DrawNameSelect(void);

NAME_SELECT* GetNameSelect();