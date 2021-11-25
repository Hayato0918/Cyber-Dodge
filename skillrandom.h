//スキルランダム [skillrandom.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2  pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 move;
	int      texture;
	int         code; //skill code used to designate skills.
	bool         use;
	bool      active;

}RANDOM;

//-----宣言
HRESULT InitRandom(void);
void UninitRandom(void);
void UpdateRandom(void);
void DrawRandom(void);

RANDOM* GetRandom();