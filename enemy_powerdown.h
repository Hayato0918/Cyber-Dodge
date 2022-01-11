//スキル_パワーダウン処理 [enemy_powerdown.h]
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

	bool bugincrease;
	int bugdrawnum;
}POWERDOWN;

//-----プロトタイプ宣言
HRESULT InitPowerDown(void);
void _PowerDown(void);