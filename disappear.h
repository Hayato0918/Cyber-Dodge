//�X�L��_���ŏ��� [disappear.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool use;	//�X�L�����g�p���������Ǘ�����t���O

	int usegauge;	//�o�O�Q�[�W�̏㏸��
}DISAPPEAR;

//-----�v���g�^�C�v�錾
HRESULT InitDisappear(void);
void _Disappear(void);