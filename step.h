//�X�L��_�X�e�b�v���� [step.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool use;	//�X�L�����g�p���������Ǘ�����t���O
}STEP;

//-----�v���g�^�C�v�錾
HRESULT InitStep(void);
void _Step(void);