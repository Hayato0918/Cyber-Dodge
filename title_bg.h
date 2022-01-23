//タイトルbg処理 [title_bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	D3DXCOLOR color;
	float a;	//a値
	bool drawflag;

	int sound;
	bool soundflag;
	bool soundonce;
}TITLE_BG;

//-----プロトタイプ宣言
HRESULT InitTitleBG(void);
void UninitTitleBG(void);
void UpdateTitleBG(void);
void DrawTitleBG(void);

TITLE_BG* GetTitleBG();