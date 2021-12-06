//タイトル処理 [banner.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 bgpos;
	D3DXVECTOR2 bgsize;
	int bgtexture;

	D3DXVECTOR2 iconpos;
	D3DXVECTOR2 iconsize;
	int icontexture;

	D3DXVECTOR2 namepos;
	D3DXVECTOR2 namesize;
	int nametexture;

	int hptexture;
	int hp;	//hpゲージの長さから、HPの量を割り出すための変数
	int a, b, c;	//HPの100の位、10の位、1の位
	int goldtexture;
	int d, e, f, j;	//GOLDの1000の位、100の位、10の位、1の位
}BANNER;

typedef struct
{
	D3DXVECTOR2 hppos;
	D3DXVECTOR2 hpsize;
	float u,v,uw,vh;
}BANNER_HP;

typedef struct
{
	D3DXVECTOR2 goldpos;
	D3DXVECTOR2 goldsize;
	float u, v, uw, vh;
}BANNER_GOLD;

typedef struct
{
	D3DXVECTOR2 bugframepos;
	D3DXVECTOR2 bugframesize;
	int frametexture;
	D3DXVECTOR2 buggaugepos;
	D3DXVECTOR2 buggaugesize;
	int gaugetexture;
}BANNER_BUG;

//-----プロトタイプ宣言
HRESULT InitBanner(void);
void UninitBanner(void);
void UpdateBanner(void);
void DrawBanner(void);