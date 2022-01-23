//サウンドボリューム処理 [soundvolume.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体

//-----プロトタイプ宣言
HRESULT InitSoundVolume(void);
void UninitSoundVolume(void);
void UpdateSoundVolume(void);
void DrawSoundVolume(void);