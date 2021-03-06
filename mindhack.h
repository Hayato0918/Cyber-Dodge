//スキル_マインドハック処理 [mindhack.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	bool use;	//スキルを使用したかを管理するフラグ
	float time;		//スキルの適用時間を管理する変数
	bool timeflag;	//スキルの適用時間を管理するフラグ

	bool bugincrease;
	int bugdrawnum;
}MINDHACK;

//-----プロトタイプ宣言
HRESULT InitMindhack(void);
void _Mindhack(void);