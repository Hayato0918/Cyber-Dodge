//�Q�[���I�[�o�[F���� [gameover_F.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	int floornum;
	int flooru;
	float floorv;
}GAMEOVER_F;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	float u, v;
	bool drawflag;
}GAMEOVER_FNUM;

//-----�v���g�^�C�v�錾
HRESULT InitGameOverF(void);
void UninitGameOverF(void);
void UpdateGameOverF(void);
void DrawGameOverF(void);