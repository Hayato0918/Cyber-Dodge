//バナー処理 [banner.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体

//-----プロトタイプ宣言
HRESULT InitBanner(void);
void UninitBanner(void);
void UpdateBanner(void);
void DrawBanner(void);