//�o�O_���W�F�l���� [venom.h]

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
}VENOM;

//-----�錾
HRESULT InitVenom(void);
void _Venom(void);

VENOM* GetVenom();
