/*------------------------------------------
[ �Ó] [ notCatch.h ] ]
-------------------------------------------*/
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
}NOTCATCH;

//-----�v���g�^�C�v�錾
HRESULT InitNotCatch(void);
void _NotCatch(void);
NOTCATCH* GetNotCatch();