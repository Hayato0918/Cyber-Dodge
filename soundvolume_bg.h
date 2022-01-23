//サウンドボリュームbg処理 [soundvolume_bg.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}BGM;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}SE;

//-----プロトタイプ宣言
HRESULT InitSoundVolumeBG(void);
void UninitSoundVolumeBG(void);
void UpdateSoundVolumeBG(void);
void DrawSoundVolumeBG(void);

BGM* GetBGM();
SE* GetSE();