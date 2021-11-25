//�X�L�������_�� [skillrandom.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
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

//-----�錾
HRESULT InitRandom(void);
void UninitRandom(void);
void UpdateRandom(void);
void DrawRandom(void);

RANDOM* GetRandom();