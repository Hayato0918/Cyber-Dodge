//サウンドボリューム選択処理 [soundvolume_select.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	float count;
	bool soundchangeflag;

	bool exitflag;
}SOUNDVOLUME_SELECT;

//-----プロトタイプ宣言
HRESULT InitSoundVolumeSelect(void);
void UninitSoundVolumeSelect(void);
void UpdateSoundVolumeSelect(void);
void DrawSoundVolumeSelect(void);

SOUNDVOLUME_SELECT* GetSoundVolumeSelect(void);