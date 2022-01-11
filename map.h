//マップ処理 [map.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----プロトタイプ宣言
HRESULT InitMap(void);
void UninitMap(void);
void UpdateMap(void);
void DrawMap(void);