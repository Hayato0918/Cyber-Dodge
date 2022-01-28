//���V���̏��� [hujyou.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
}HUJYOU;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
}HUJYOUPOINT;

//-----�v���g�^�C�v�錾
void InitHujyou(void);
void UninitHujyou(void);
void UpdateHujyou(void);
void DrawHujyou(void);

HUJYOU* GetHujyou();
HUJYOUPOINT* GetHujyouPoint();