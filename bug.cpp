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
#include "venom.h"
#include "screencrack.h"

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
	InitVenom();
	InitCrack();

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
	_Venom();
	_Crack();
}

void DrawBug(void)
{
	DrawAnten();
	DrawEnemyClone();
	DrawCreate();
	DrawVenom();
	DrawCrack();
}