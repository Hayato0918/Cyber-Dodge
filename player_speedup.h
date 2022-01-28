//スキル_スピードアップ処理 [player_speedup.h]
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
}SPEEDUP;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u;
	int texture;
	float time;
}SPEEDUP_ANIME;

//-----プロトタイプ宣言
HRESULT InitSpeedUp(void);
void _SpeedUp(void);
void DrawSpeedup();

SPEEDUP_ANIME* GetSpeedup();