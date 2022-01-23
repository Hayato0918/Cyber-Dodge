//�}�b�v�t���A���� [map_floor.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;

	int floornum;
}MAP_FLOORBG;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	float u, v;
	bool drawflag;
}MAP_FLOOR;

//-----�v���g�^�C�v�錾
HRESULT InitMapFloor(void);
void UninitMapFloor(void);
void UpdateMapFloor(void);
void DrawMapFloor(void);