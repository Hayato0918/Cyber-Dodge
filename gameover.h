//�Q�[���I�[�o�[���� [gameover.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}GAMEOVER;

//-----�v���g�^�C�v�錾
HRESULT InitGameOver(void);
void UninitGameOver(void);
void UpdateGameOver(void);
void DrawGameOver(void);