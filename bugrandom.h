//�o�O�����_�� [bugrandom.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	int code; //���蓖�Ă�ꂽ�������Ǘ�����ϐ�
	int num;		//�o�O�̑���
}BUGRANDOM;

//-----�錾
HRESULT InitBugRandom(void);

BUGRANDOM* GetBugRandom();