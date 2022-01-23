//セーブ処理 [mpa_save.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----プロトタイプ宣言
HRESULT InitMapSave(void);
void UninitMapSave(void);
void UpdateMapSave(void);
void DrawMapSave(void);