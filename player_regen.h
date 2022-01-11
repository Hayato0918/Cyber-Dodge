//スキル_リジェネ処理 [player_regen.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	bool use;	//スキルを使用したかを管理するフラグ
	float time;		//スキルの適用時間を管理する変数
	bool timeflag;	//スキルの適用時間を管理するフラグ
	int number;

	int usegauge;	//バグゲージの上昇量

	bool bugincrease;
	int bugdrawnum;
}PLAYERREGEN;

//-----プロトタイプ宣言
HRESULT InitPlayerRegen(void);
void _PlayerRegen(void);