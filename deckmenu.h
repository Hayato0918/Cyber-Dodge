//�f�b�L���j���[���� [deckmenu.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool use;
}DECKMENU;

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}DECKMENUCARD;


//-----�\����
typedef struct
{
	float u, v, uw, vh;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}NUMBER;

//-----�\����
typedef struct
{
	bool		use;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int LRcount;
	int UDcount;
}SELECTION;


//-----�v���g�^�C�v�錾
HRESULT InitDeckMenu(void);
void UninitDeckMenu(void);
void UpdateDeckMenu(void);
void DrawDeckMenu(void);

SELECTION* GetSelection(void);
