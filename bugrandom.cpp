//�o�O�����_�� [bugrandom.cpp]
#include "bugrandom.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include <stdlib.h>
#include <time.h>

//-----�}�N����`

//-----�v���g�^�C�v�錾
BUGRANDOM bugrandom;
//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBugRandom(void)
{
	bugrandom.num = 8;		//�X�L���̑���

	bugrandom.code = (rand() % bugrandom.num) + 1;

	return S_OK;
}

BUGRANDOM* GetBugRandom()
{
	return &bugrandom;
}