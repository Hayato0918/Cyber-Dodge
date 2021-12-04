//スキル_スローエリア処理 [slowarea.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	int xrand;		//x座標を乱数化に必要な変数
	int yrand;		//y座標の乱数化に必要な変数
	D3DXVECTOR2 size;
	int texture;
	bool use;	//スキルを使用したかを管理するフラグ
	float time;		//スキルの適用時間を管理する変数
	bool timeflag;	//スキルの適用時間を管理するフラグ
	int usegauge;
}SLOWAREA;

//-----プロトタイプ宣言
HRESULT InitSlowArea(void);
void _SlowArea(void);
void DrawSlowArea(void);