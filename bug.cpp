//�o�O���� [bug.cpp]
#include "bug.h"
#include "texture.h"
#include "sprite.h"

#include "anten.h"
#include "bunshin.h"
#include "reverse.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBug(void)
{
	InitAnten();
	InitEnemyClone();
	InitReverse();

	return S_OK;
}

void _Bug(void)
{
	_Anten();
	_EnemyClone();
	_Reverse();
}

void DrawBug(void)
{
	DrawAnten();
	DrawEnemyClone();
}