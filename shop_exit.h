//���l�}�X�ޏo���� [shop_exit.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}SHOP_EXIT;

HRESULT InitShopExit(void);
void UninitShopExit(void);
void UpdateShopExit(void);
void DrawShopExit(void);

SHOP_EXIT* GetShopExit();