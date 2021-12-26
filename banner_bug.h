//�o�i�[�o�O�Q�[�W���� [banner_bug.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}BANNER_BUGFRAME;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}BANNER_BUGGAUGE;

//-----�v���g�^�C�v�錾
HRESULT InitBannerBug(void);
void UninitBannerBug(void);
void UpdateBannerBug(void);
void DrawBannerBug(void);