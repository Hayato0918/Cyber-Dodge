/*------------------------------------------
[ 浮遊感を感じて [ event_FloatingFeeling.h ] ]
-------------------------------------------*/
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	bool use;
	int texture;
}E_FLOATINGFEELING;

HRESULT Inite_FloatingFeeling();
void _FloatingFeeling(void);
void Drawe_FloatingFeeling(void);