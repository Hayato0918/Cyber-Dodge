//�X�L��_�ђ� [kantsuu.h]
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
}KANTSUU;

//-----�v���g�^�C�v�錾
HRESULT InitKantsuu(void);
void _Kantsuu(void);
KANTSUU* GetKantsuu(void);