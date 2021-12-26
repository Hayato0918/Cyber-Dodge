//�o�i�[���O���� [banner_name.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}BANNER_NAME;

//-----�v���g�^�C�v�錾
HRESULT InitBannerName(void);
void UninitBannerName(void);
void UpdateBannerName(void);
void DrawBannerName(void);