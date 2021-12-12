//�X�L��_��ΐ��� [rockcreate.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool use;
	float time;
	bool timeflag;
	int usegauge;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}GANSEKI;

//-----�v���g�^�C�v�錾
HRESULT InitGanseki(void);
void _Ganseki(void);
void DrawGanseki(void);

GANSEKI* GetGanseki(void);