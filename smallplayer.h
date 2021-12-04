//スキル_プレイヤーが小さくなる処理 [PlayerSizeDown.h]

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
}SMALLPLAYER;

//-----プロトタイプ宣言
HRESULT InitSmallPlayer(void);
void _SmallPlayer(void);