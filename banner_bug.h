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
	float u, v;
	bool drawflag;
}BANNER_BUG;

typedef struct
{
	int texture;
	int bugnum;
	int a, b, c;
}BANNER_BUGNUM;

//-----�v���g�^�C�v�錾
HRESULT InitBannerBug(void);
void UninitBannerBug(void);
void UpdateBannerBug(void);
void DrawBannerBug(void);