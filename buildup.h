//�X�L��_�r���h�A�b�v���� [buildup.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool use;	//�X�L�����g�p���������Ǘ�����t���O
	float time;		//�X�L���̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;	//�X�L���̓K�p���Ԃ��Ǘ�����t���O

	int usegauge;	//�o�O�Q�[�W�̏㏸��
}BUILDUP;

//-----�v���g�^�C�v�錾
HRESULT InitBuildUp(void);
void _BuildUp(void);