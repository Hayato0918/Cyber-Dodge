//スキル_エネミー追跡処理[ballturnaround.h]
#pragma once

#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	bool use;	//スキルを使用したかを管理するフラグ

	int usegauge;	//バグゲージの上昇量
}BALLTURNAROUND;


//-----プロトタイプ宣言
HRESULT InitBallTurnAround(void);
void _BallTurnAround(void);
