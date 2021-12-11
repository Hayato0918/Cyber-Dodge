//セーブ処理 [save.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	int hp;
}SAVE;

//-----プロトタイプ宣言
void Save(void);
void Load(void);