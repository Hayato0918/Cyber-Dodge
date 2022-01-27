//バグ_リジェネ処理 [venom.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
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

//-----宣言
HRESULT InitVenom(void);
void _Venom(void);

void DrawVenom();