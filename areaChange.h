/*------------------------------------------
[ エリア変化 [ areaChange.h ] ]
-------------------------------------------*/
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;	//座標
	D3DXVECTOR2 move;	//移動
	bool use;			//バグ発動を管理するフラグ
	int time;			//バグの適用時間を管理する変数
	int counttime;		//ただカウントする変数
	bool finishflag;	//終了する際の処理を管理するフラグ
	bool timeflag;		//バグの適用時間を管理するフラグ
}AREACHANGE;

HRESULT InitAreaChange(void);
void _AreaChange(void);
AREACHANGE* GetAreaChange(void);