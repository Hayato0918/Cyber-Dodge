//�o�i�[�X�R�A���� [banner_score.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v;
	bool drawflag;
}BANNER_SCORE;

typedef struct
{
	int gold;
	int texture;
	int a, b, c, d;	//gold��1000�̈ʁA100�̈ʁA10�̈ʁA1�̈�
}BANNER_SCORENUM;

//-----�v���g�^�C�v�錾
HRESULT InitBannerScore(void);
void UninitBannerScore(void);
void UpdateBannerScore(void);
void DrawBannerScore(void);