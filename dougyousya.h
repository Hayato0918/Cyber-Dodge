//���Ǝ҂̎��s���� [dougyousya.h]

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
}DOUGYOUSYA;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
}DOUGYOUSYAPOINT;

//-----�v���g�^�C�v�錾
void InitDougyousya(void);
void UninitDougyousya(void);
void UpdateDougyousya(void);
void DrawDougyousya(void);

DOUGYOUSYA* GetDougyousya();
DOUGYOUSYAPOINT* GetDougyousyaPoint();