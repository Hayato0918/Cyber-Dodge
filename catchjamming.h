//スキル_キャッチ妨害処理 [cacthjamming.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	bool use;	//スキルを使用したかを管理するフラグ
	float time;		//スキルの適用時間を管理する変数
	bool timeflag;	//スキルの適用時間を管理するフラグ

	int usegauge;	//バグゲージの上昇量
}CATCHJAMMING;

//-----プロトタイプ宣言
HRESULT InitCatchJamming(void);
void _CatchJamming(void);
CATCHJAMMING* GetCatchJamming();