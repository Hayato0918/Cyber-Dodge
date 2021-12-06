//�^�C�g������ [banner.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 bgpos;
	D3DXVECTOR2 bgsize;
	int bgtexture;

	D3DXVECTOR2 iconpos;
	D3DXVECTOR2 iconsize;
	int icontexture;

	D3DXVECTOR2 namepos;
	D3DXVECTOR2 namesize;
	int nametexture;

	int hptexture;
	int hp;	//hp�Q�[�W�̒�������AHP�̗ʂ�����o�����߂̕ϐ�
	int a, b, c;	//HP��100�̈ʁA10�̈ʁA1�̈�
	int goldtexture;
	int d, e, f, j;	//GOLD��1000�̈ʁA100�̈ʁA10�̈ʁA1�̈�
}BANNER;

typedef struct
{
	D3DXVECTOR2 hppos;
	D3DXVECTOR2 hpsize;
	float u,v,uw,vh;
}BANNER_HP;

typedef struct
{
	D3DXVECTOR2 goldpos;
	D3DXVECTOR2 goldsize;
	float u, v, uw, vh;
}BANNER_GOLD;

typedef struct
{
	D3DXVECTOR2 bugframepos;
	D3DXVECTOR2 bugframesize;
	int frametexture;
	D3DXVECTOR2 buggaugepos;
	D3DXVECTOR2 buggaugesize;
	int gaugetexture;
}BANNER_BUG;

//-----�v���g�^�C�v�錾
HRESULT InitBanner(void);
void UninitBanner(void);
void UpdateBanner(void);
void DrawBanner(void);