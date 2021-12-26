//���l�}�X�w�i���� [shop_bg.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}SHOP_BG;

HRESULT InitShopBg(void);
void UninitShopBg(void);
void UpdateShopBg(void);
void DrawShopBg(void);