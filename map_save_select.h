//�Z�[�u�I������ [map_save_select.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int count;
	bool drawflag;
	int sound;
}MAPSAVE_SELECT;


//-----�v���g�^�C�v�錾
HRESULT InitMapSaveSelect(void);
void UninitMapSaveSelect(void);
void UpdateMapSaveSelect(void);
void DrawMapSaveSelect(void);

MAPSAVE_SELECT* GetMapSaveSelect(void);