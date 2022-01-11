//イベント処理 [event.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体

//-----プロトタイプ宣言
HRESULT InitEvent(void);
void UninitEvent(void);
void UpdateEvent(void);
void DrawEvent(void);