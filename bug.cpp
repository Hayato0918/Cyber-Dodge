//バグ処理 [bug.cpp]
#include "bug.h"
#include "texture.h"
#include "sprite.h"

#include "anten.h"
#include "bunshin.h"
#include "reverse.h"
#include "regen.h"

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

	return S_OK;
}

void _Bug(void)
{
	_Anten();
	_EnemyClone();
	_Reverse();
	_Regen();
}

void DrawBug(void)
{
	DrawAnten();
	DrawEnemyClone();
}