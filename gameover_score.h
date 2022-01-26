//�Q�[���I�[�o�[�X�R�A���� [gameover_�X�R�A.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	int scorenum;
	int scoreu;
	float scorev;
	int a, b, c, d;
	int gold;
}GAMEOVER_SCORE;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	float u, v;
	bool drawflag;
}GAMEOVER_SCORENUM;

//-----�v���g�^�C�v�錾
HRESULT InitGameOverScore(void);
void UninitGameOverScore(void);
void UpdateGameOverScore(void);
void DrawGameOverScore(void);