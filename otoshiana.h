//スキル_落とし穴処理 [otoshiana.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;	//座標
	D3DXVECTOR2 size;	//大きさ
	bool use;	//スキルを使用したかを管理するフラグ
	bool timeflag;	//スキルの適用時間を管理するフラグ

	float time;		//スキルの適用時間を管理する変数

	int xrand;		//x座標を乱数化に必要な変数
	int yrand;		//y座標の乱数化に必要な変数
	int usegauge;	//バグゲージの上昇量
	int texture;    //画像

	bool bugincrease;
	int bugdrawnum;
}OTOSIANA;

//-----プロトタイプ宣言
HRESULT InitOtosiana(void);
void _Otosiana(void);
void DrawOtosiana(void);
OTOSIANA* GetOtosiana();