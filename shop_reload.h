//商人マススキル再抽選処理 [shop_reload.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool reloadflag;	//スキルの再抽選を実行するかを管理するフラグ
	int gold;			//リロードにかかる値段
}SHOP_RELOAD;

HRESULT InitShopReload(void);
void UninitShopReload(void);
void UpdateShopReload(void);
void DrawShopReload(void);

SHOP_RELOAD* GetShopReload();