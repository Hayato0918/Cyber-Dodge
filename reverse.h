//�v���C���[���씽�] [ reverse.h ]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool use;	//�o�O���g�p���������Ǘ�����t���O

}REVERSE;

//-----�v���g�^�C�v�錾
HRESULT InitReverse(void);
void _Reverse(void);

REVERSE* GetReverse(void);