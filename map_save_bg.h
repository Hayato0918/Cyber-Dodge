//�Z�[�u�w�i���� [map_save_bg.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool drawflag;
}MAPSAVE_BG;

//-----�v���g�^�C�v�錾
HRESULT InitMapSaveBG(void);
void UninitMapSaveBG(void);
void UpdateMapSaveBG(void);
void DrawMapSaveBG(void);
MAPSAVE_BG* GetMapSaveBG();