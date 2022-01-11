//スキル_貫通 [kantsuu.h]
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

	bool bugincrease;
	int bugdrawnum;
}KANTSUU;

//-----プロトタイプ宣言
HRESULT InitKantsuu(void);
void _Kantsuu(void);
KANTSUU* GetKantsuu(void);