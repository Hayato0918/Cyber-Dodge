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
	bool timeflag;	//�X�L����K�p���Ă��鎞�Ԃ��Ǘ�����t���O
	bool useflag;	//�X�L����1�񂾂����Z���邽�߂̃t���O

	int usegauge;	//�o�O�Q�[�W�̏㏸��
	bool bugincrease;
	int bugdrawnum;
}BALLSPEEDUP;

//-----�v���g�^�C�v�錾
HRESULT InitBallSpeedUp(void);
void _BallSpeedUp(void);