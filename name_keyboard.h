//���O����_�L�[�{�[�h���� [name_keyboard.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int wardnum;
}NAME_KEYBOARD;

//-----�v���g�^�C�v�錾
HRESULT InitNameKeyboard(void);
void UninitNameKeyboard(void);
void UpdateNameKeyboard(void);
void DrawNameKeyboard(void);

NAME_KEYBOARD* GetNameKeyboard(void);