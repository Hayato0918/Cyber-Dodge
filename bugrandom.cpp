//バグランダム [bugrandom.cpp]
#include "bugrandom.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include <stdlib.h>
#include <time.h>

//-----マクロ定義

//-----プロトタイプ宣言
BUGRANDOM bugrandom;
//-----グローバル変数

//-----初期化処理
HRESULT InitBugRandom(void)
{
	bugrandom.num = 7;		//スキルの総数

	bugrandom.code = (rand() % bugrandom.num) + 1;

	bugrandom.code = 2;

	return S_OK;
}

BUGRANDOM* GetBugRandom()
{
	return &bugrandom;
}