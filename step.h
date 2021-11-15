//スキル_ステップ処理 [step.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	bool use;	//スキルを使用したかを管理するフラグ
}STEP;

//-----プロトタイプ宣言
HRESULT InitStep(void);
void _Step(void);