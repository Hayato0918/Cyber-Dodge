//スキル_エネミー追跡処理[ballturnaround.h]
#pragma once

#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	int use;	//スキルを使用したかを管理するフラグ

	//作業用変数
	float b_x;//出発点
	float b_y;//出発点
	float f_x;//到着点
	float f_y;//到着点
	float a;
	int n;
	bool n_flag;
	bool n_flag_2;

	int usegauge;	//バグゲージの上昇量
	bool bugincrease;
	int bugdrawnum;
}BALLTURNAROUND;

//-----プロトタイプ宣言
HRESULT InitBallTurnAround(void);
void _BallTurnAround(void);
BALLTURNAROUND* GetBallTurnAround(void);
void SetBallTurnAround(void);
void SetBallTurnAround_2(void);
void SetBallTurnAround_3(void);