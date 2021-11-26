//�G�l�~�[HP���� [enemy_hp.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	int gaugeonce;		//�Q�[�W�̊g��(x5)

	D3DXVECTOR2 pos;
	D3DXVECTOR2 framesize;
	int frametexture;

	D3DXVECTOR2 gaugesize;
	int gaugetexture;
}ENEMYHP;

//-----�v���g�^�C�v�錾
HRESULT InitEnemyHp(void);
void UninitEnemyHp(void);
void UpdateEnemyHp(void);
void DrawEnemyHp(void);

ENEMYHP* GetEnemyHp();