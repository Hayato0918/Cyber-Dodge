//バナーHP処理 [banner_hp.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
}BANNER_HP;

typedef struct
{
	int texture;
	int hp;	//hpゲージの長さから、HPの量を割り出すための変数
	int a, b, c;	//HPの100の位、10の位、1の位
}BANNER_HPNUM;

//-----プロトタイプ宣言
HRESULT InitBannerHp(void);
void UninitBannerHp(void);
void UpdateBannerHp(void);
void DrawBannerHp(void);