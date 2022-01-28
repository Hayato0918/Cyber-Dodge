//�o�i�[�w�i���� [banner_bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}BANNER_BG;

//-----�v���g�^�C�v�錾
HRESULT InitBannerBG(void);
void UninitBannerBG(void);
void UpdateBannerBG(void);
void DrawBannerBG(void);

BANNER_BG* GetBannerBG();