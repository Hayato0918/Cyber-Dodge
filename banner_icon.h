//�o�i�[�A�C�R������ [banner_icon.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}BANNER_ICON;

//-----�v���g�^�C�v�錾
HRESULT InitBannerIcon(void);
void UninitBannerIcon(void);
void UpdateBannerIcon(void);
void DrawBannerIcon(void);