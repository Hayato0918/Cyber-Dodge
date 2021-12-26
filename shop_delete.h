//商人マススキル削除処理 [shop_delete.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}SHOP_DELETE;

HRESULT InitShopDelete(void);
void UninitShopDelete(void);
void UpdateShopDelete(void);
void DrawShopDelete(void);

SHOP_DELETE* GetShopDelete(void);