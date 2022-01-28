//スキル_時間停止処理 [timestop.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	bool use;	//スキルを使用したかを管理するフラグ
	float time;		//スキルの適用時間を管理する変数
	bool timeflag;	//スキルの適用時間を管理するフラグ
	D3DXVECTOR2 posnow;	//敵を行動不可にするための一時的な格納場所

	int usegauge;	//バグゲージの上昇量

	bool bugincrease;
	int bugdrawnum;

	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int u;
}TIMESTOP;

//-----プロトタイプ宣言
HRESULT InitTimestop(void);
void _Timestop(void);
void DrawTimestop(void);
TIMESTOP* GetTimestop();