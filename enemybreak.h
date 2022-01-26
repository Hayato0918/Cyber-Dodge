//撃破処理[enemybreak.h]
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
	float u, v;
	bool drawflag;
}GETGOLD;

typedef struct
{
	int texture;
	int gold;
	int a, b, c, d;
}GETGOLDNUM;

typedef struct
{
	int score;
}GETSCORE;

//-----プロトタイプ宣言
HRESULT InitEnemyBreak(void);
void UninitEnemyBreak(void);
void UpdateEnemyBreak(void);
void DrawEnemyBreak(void);
ENEMYBREAK* GetEnemyBreak();