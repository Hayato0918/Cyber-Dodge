/*------------------------------------------
[ ïÇóVä¥Çä¥Ç∂Çƒ [ event_FloatingFeeling.h ] ]
-------------------------------------------*/
#pragma once
#include "main.h"
#include "renderer.h"

//-----ç\ë¢ëÃ
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