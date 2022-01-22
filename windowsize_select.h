//�E�B���h�E�T�C�Y�I������ [windowsize_select.h]
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

	int x;
	int y;
}WINDOWSIZE_SELECT;

//-----�v���g�^�C�v�錾
HRESULT InitWindowSizeSelect(void);
void UninitWindowSizeSelect(void);
void UpdateWindowSizeSelect(void);
void DrawWindowSizeSelect(void);

WINDOWSIZE_SELECT* GetWindowSizeSelect();