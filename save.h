//セーブ処理 [save.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	int hp = 100;
	int atk = 100;
	int def = 100;
	int gold = 100;
}SAVE;

//-----プロトタイプ宣言
void Save(void);
void Load(void);