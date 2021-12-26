//�o�i�[�������� [banner_gold.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
}BANNER_GOLD;

typedef struct
{
	int texture;
	int a, b, c, d;	//gold��1000�̈ʁA100�̈ʁA10�̈ʁA1�̈�
}BANNER_GOLDNUM;

//-----�v���g�^�C�v�錾
HRESULT InitBannerGold(void);
void UninitBannerGold(void);
void UpdateBannerGold(void);
void DrawBannerGold(void);