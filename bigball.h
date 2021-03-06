#pragma once
//スキル_ボールが巨大化処理 [PlayerSizeDown.h]

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
}BIGBALL;

//-----プロトタイプ宣言
HRESULT InitBigBall(void);
void _BigBall(void);