//バグ処理 [bug.cpp]
#include "bug.h"
#include "texture.h"
#include "sprite.h"

#include "anten.h"
#include "bunshin.h"
#include "reverse.h"
#include "regen.h"
#include "notCatch.h"
#include "create.h"
#include "areaChange.h"

//-----マクロ定義

//-----プロトタイプ宣言

//-----グローバル変数

//-----初期化処理
HRESULT InitBug(void)
{
	InitAnten();
	InitEnemyClone();
	InitReverse();
	InitRegen();
	InitNotCatch();
	InitCreate();
	InitAreaChange();

	return S_OK;
}

void _Bug(void)
{
	_Anten();
	_EnemyClone();
	_Reverse();
	_Regen();
	_NotCatch();
	_Create();
	_AreaChange();
}

void DrawBug(void)
{
	DrawAnten();
	DrawEnemyClone();
	DrawCreate();
}