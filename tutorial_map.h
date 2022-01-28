//チュートリアル_マップ処理 [tutorial_map.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool drawflag;
}TUTORIAL_MAP;

//-----プロトタイプ宣言
HRESULT InitTutorialMap(void);
void UninitTutorialMap(void);
void UpdateTutorialMap(void);
void DrawTutorialMap(void);

TUTORIAL_MAP* GetTutorialMap();