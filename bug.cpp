//�o�O���� [bug.cpp]
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
#include "screencrack.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBug(void)
{
	InitAnten();
	InitEnemyClone();
	InitReverse();
	InitRegen();
	InitNotCatch();
	InitCreate();
	InitAreaChange();
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
	_Crack();
}

void DrawBug(void)
{
	DrawAnten();
	DrawEnemyClone();
	DrawCreate();
	DrawCrack();
}