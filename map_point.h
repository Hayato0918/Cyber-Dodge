//�}�b�v���� [map.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int randomcode;
}MAP;

typedef struct
{
	D3DXVECTOR2 startpos;
	D3DXVECTOR2 startsize;
	D3DXVECTOR2 bosspos;
	D3DXVECTOR2 bosssize;
}MAP_SB;

//-----�v���g�^�C�v�錾
HRESULT InitMapPoint(void);
void UninitMapPoint(void);
void UpdateMapPoint(void);
void DrawMapPoint(void);
MAP* GetMapPoint();
MAP_SB* GetMapSB();