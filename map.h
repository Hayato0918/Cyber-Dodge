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
}MAP;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int scene;
}MAPSEN;

//-----�v���g�^�C�v�錾
HRESULT InitMap(void);
void UninitMap(void);
void UpdateMap(void);
void DrawMap(void);
MAP* GetMap(void);