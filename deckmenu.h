//デッキメニュー処理 [deckmenu.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool openflag;
	bool use;
}DECKMENU;

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int nottexture;
	int code;	//登録するテクスチャを管理する変数
	bool drawflag;	//描画するかを管理するフラグ
	float u;
}DECKMENUCARD;


//-----構造体
typedef struct
{
	float u, v, uw, vh;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}NUMBER;

//-----構造体
typedef struct
{
	bool		use;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int LRcount;
	int UDcount;
}SELECTION;


//-----プロトタイプ宣言
HRESULT InitDeckMenu(void);
void UninitDeckMenu(void);
void UpdateDeckMenu(void);
void DrawDeckMenu(void);

SELECTION* GetSelection(void);
DECKMENU* GetDeckmenu(void);
