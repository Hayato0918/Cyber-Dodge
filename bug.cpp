//�o�O���� [bug.cpp]
#include "bug.h"
#include "texture.h"
#include "sprite.h"

#include "anten.h"
#include "bunshin.h"
#include "reverse.h"
#include "regen.h"

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