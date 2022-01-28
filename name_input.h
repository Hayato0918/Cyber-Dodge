//���O����_���͏ꏊ���� [name_input.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int wardtexture;
}NAME_INPUTFRAME;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u;
	float v;
	float uw;
	float vh;
	int texture;
	bool drawflag;
}NAME_INPUTWARD;

//-----�v���g�^�C�v�錾
HRESULT InitNameInput(void);
void UninitNameInput(void);
void UpdateNameInput(void);
void DrawNameInput(void);

NAME_INPUTWARD* GetNameInputWard();
NAME_INPUTFRAME* GetNameInput();