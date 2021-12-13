//バグランダム [bugrandom.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	int code; //割り当てられた乱数を管理する変数
	int num;		//バグの総数
}BUGRANDOM;

//-----宣言
HRESULT InitBugRandom(void);

BUGRANDOM* GetBugRandom();