//回避処理 [escape.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	bool intervalflag;	//回避のインターバルを管理するフラグ
	float intervaltime;	//回避のインターバル秒を管理する変数
}ESCAPE;

//-----プロトタイプ宣言
HRESULT InitEscape(void);
void _Escape(void);