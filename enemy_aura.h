//エネミー強敵オーラ処理[enemy_aura.h]
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

//-----プロトタイプ宣言
HRESULT InitEnemyAura(void);
void UninitEnemyAura(void);
void UpdateEnemyAura(void);
void DrawEnemyAura(void);

ENEMY_AURA* GetEnemyAura();