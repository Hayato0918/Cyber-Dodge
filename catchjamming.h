//�X�L��_�L���b�`�W�Q���� [cacthjamming.h]

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
}CATCHJAMMING;

//-----�v���g�^�C�v�錾
HRESULT InitCatchJamming(void);
void _CatchJamming(void);
CATCHJAMMING* GetCatchJamming();