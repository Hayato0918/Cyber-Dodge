//�^�C�g��bg���� [title_bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	D3DXCOLOR color;
	float a;	//a�l
	bool drawflag;

	int sound;
	bool soundflag;
	bool soundonce;
}TITLE_BG;

//-----�v���g�^�C�v�錾
HRESULT InitTitleBG(void);
void UninitTitleBG(void);
void UpdateTitleBG(void);
void DrawTitleBG(void);

TITLE_BG* GetTitleBG();