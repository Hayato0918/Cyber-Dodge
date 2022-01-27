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
	bool drawflag;
	int texture;
	int count;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
}VENOM;

//-----�錾
HRESULT InitVenom(void);
void _Venom(void);

void DrawVenom();