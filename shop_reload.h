//���l�}�X�X�L���Ē��I���� [shop_reload.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool reloadflag;	//�X�L���̍Ē��I�����s���邩���Ǘ�����t���O
}SHOP_RELOAD;

void InitShopReload(void);
void UninitShopReload(void);
void UpdateShopReload(void);
void DrawShopReload(void);

SHOP_RELOAD* GetShopReload();