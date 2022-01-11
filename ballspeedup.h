//スキル_ボールスピードアップ処理 [ballspeedup.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	float move;	//上昇したスピードを保存しておく変数
	float beforemove;		//元のスピードを保存しておく変数
	bool use;	//スキルを使用したかを管理するフラグ
	bool timeflag;	//スキルを適用している時間を管理するフラグ
	bool useflag;	//スキルを1回だけ加算するためのフラグ

	int usegauge;	//バグゲージの上昇量
	bool bugincrease;
	int bugdrawnum;
}BALLSPEEDUP;

//-----プロトタイプ宣言
HRESULT InitBallSpeedUp(void);
void _BallSpeedUp(void);