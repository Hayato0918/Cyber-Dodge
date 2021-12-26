//スキル_消滅処理 [disappear.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	bool use;	//スキルを使用したかを管理するフラグ

	int usegauge;	//バグゲージの上昇量
}DISAPPEAR;

//-----プロトタイプ宣言
HRESULT InitDisappear(void);
void _Disappear(void);