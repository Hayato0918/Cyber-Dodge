//�`���[�g���A��_�}�b�v���� [tutorial_map.h]

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
}TUTORIAL_MAP;

//-----�v���g�^�C�v�錾
HRESULT InitTutorialMap(void);
void UninitTutorialMap(void);
void UpdateTutorialMap(void);
void DrawTutorialMap(void);

TUTORIAL_MAP* GetTutorialMap();