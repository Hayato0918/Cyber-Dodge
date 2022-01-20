//�}�b�v�ڐ����� [map_line.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;

	int randomcode;
}MAP_LINE;

//-----�v���g�^�C�v�錾
HRESULT InitMapLine(void);
void UninitMapLine(void);
void UpdateMapLine(void);
void DrawMapLine(void);

MAP_LINE* GetMapLine();