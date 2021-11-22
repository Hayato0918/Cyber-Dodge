//プレイヤー操作反転 [ reverse.h ]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	bool use;	//バグを使用したかを管理するフラグ

}REVERSE;

//-----プロトタイプ宣言
HRESULT InitReverse(void);
void _Reverse(void);

REVERSE* GetReverse(void);