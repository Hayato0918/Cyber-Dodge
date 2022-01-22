//���j����[enemybreak.h]
#pragma once
#include "main.h"
#include "renderer.h"

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;

	bool drawflag;
}ENEMYBREAK;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int skillcode;
}GETSKILL;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}GETGOLD;

//-----�v���g�^�C�v�錾
HRESULT InitEnemyBreak(void);
void UninitEnemyBreak(void);
void UpdateEnemyBreak(void);
void DrawEnemyBreak(void);
ENEMYBREAK* GetEnemyBreak();