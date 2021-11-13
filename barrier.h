//スキル_バリア処理 [barrier.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool drawflag;

	bool use;	//スキルを使用したかを管理するフラグ
	float time;		//スキルの適用時間を管理する変数
	bool timeflag;	//スキルの適用時間を管理するフラグ

	int usegauge;	//バグゲージの上昇量
}BARRIER;

//-----プロトタイプ宣言
HRESULT InitBarrier(void);
void _Barrier(void);
void DrawBarrier(void);
BARRIER* GetBarrier(void);