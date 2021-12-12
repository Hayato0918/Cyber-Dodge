//スキル_岩石生成 [rockcreate.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	bool use;
	float time;
	bool timeflag;
	int usegauge;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}GANSEKI;

//-----プロトタイプ宣言
HRESULT InitGanseki(void);
void _Ganseki(void);
void DrawGanseki(void);

GANSEKI* GetGanseki(void);