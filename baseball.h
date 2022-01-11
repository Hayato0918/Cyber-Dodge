//スキル_ベースボール処理 [baseball.h]

#pragma once
#include "main.h"
#include "renderer.h"

typedef struct
{
	D3DXVECTOR2 pos;	//座標
	D3DXVECTOR2 size;	//大きさ
	bool use;			//スキルを使用したかを管理するフラグ
	float time;			//スキルの適用時間を管理する変数
	bool timeflag;		//スキルの適用時間を管理するフラグ
	int texture;		//テクスチャ
	int usegauge;

	bool bugincrease;
	int bugdrawnum;
}BASEBALL;

//-----プロトタイプ宣言
HRESULT InitBaseball(void);
void DrawBaseball(void);
void _Baseball(void);