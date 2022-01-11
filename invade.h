//スキル_不法侵入処理 [invade.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	bool use;	//スキルを使用したかを管理するフラグ
	float time;		//スキルの適用時間を管理する変数
	bool timeflag;	//スキルの適用時間を管理するフラグ
	int usegauge;

	bool bugincrease;
	int bugdrawnum;
}INVADE;

//-----プロトタイプ宣言
HRESULT InitInvade(void);
void _Invade(void);

INVADE* GetInvade(void);