//エネミー処理[enemy.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----プロトタイプ宣言
HRESULT InitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);