//�}�b�vbg���� [map_bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int sound;
}MAP_BG;

//-----�v���g�^�C�v�錾
HRESULT InitMapBG(void);
void UninitMapBG(void);
void UpdateMapBG(void);
void DrawMapBG(void);
MAP_BG* GetMapBG();