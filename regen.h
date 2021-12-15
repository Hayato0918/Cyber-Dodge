//バグ_リジェネ処理 [regen.h]

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
}REGEN;

//-----宣言
HRESULT InitRegen(void);
void _Regen(void);

REGEN* GetRegen();