//エネミー死亡時のエフェクト追加[enemy_explosion_animation.h]
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
	bool drawflag;
	bool animeflag;
}ENEMY_EXPLOSION;

HRESULT InitEnemyExplosion(void);
void UninitEnemyExplosion(void);
void UpdateEnemyExplosion(void);
void DrawEnemyExplosion(void);
ENEMY_EXPLOSION* GetEnemyExplosion();