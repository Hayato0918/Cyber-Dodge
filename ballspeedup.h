//�X�L��_�{�[���X�s�[�h�A�b�v���� [ballspeedup.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	float move;	//�㏸�����X�s�[�h��ۑ����Ă����ϐ�
	float beforemove;		//���̃X�s�[�h��ۑ����Ă����ϐ�
	bool use;	//�X�L�����g�p���������Ǘ�����t���O
	bool timeflag;	//�X�L���̓K�p���Ԃ��Ǘ�����t���O

	int usegauge;	//�o�O�Q�[�W�̏㏸��
}BALLSPEEDUP;

//-----�v���g�^�C�v�錾
HRESULT InitBallSpeedUp(void);
void _BallSpeedUp(void);