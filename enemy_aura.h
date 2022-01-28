//�G�l�~�[���G�I�[������[enemy_aura.h]
#pragma once
#include "main.h"
#include "renderer.h"

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	float u;
	float animetime;
	bool  drawflag;
}ENEMY_AURA;

//-----�v���g�^�C�v�錾
HRESULT InitEnemyAura(void);
void UninitEnemyAura(void);
void UpdateEnemyAura(void);
void DrawEnemyAura(void);

ENEMY_AURA* GetEnemyAura();