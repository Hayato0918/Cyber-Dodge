//�o�O_���W�F�l���� [regen.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	float      heal; //amount of healing
	float      time;
	bool   timeflag;
	bool        use;
}REGEN;

//-----�錾
HRESULT InitRegen(void);
void _Regen(void);

REGEN* GetRegen();