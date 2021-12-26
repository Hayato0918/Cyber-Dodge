//�o�i�[HP���� [banner_hp.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
}BANNER_HP;

typedef struct
{
	int texture;
	int hp;	//hp�Q�[�W�̒�������AHP�̗ʂ�����o�����߂̕ϐ�
	int a, b, c;	//HP��100�̈ʁA10�̈ʁA1�̈�
}BANNER_HPNUM;

//-----�v���g�^�C�v�錾
HRESULT InitBannerHp(void);
void UninitBannerHp(void);
void UpdateBannerHp(void);
void DrawBannerHp(void);