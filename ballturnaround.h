//�X�L��_�G�l�~�[�ǐՏ���[ballturnaround.h]
#pragma once

#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool use;	//�X�L�����g�p���������Ǘ�����t���O

	int usegauge;	//�o�O�Q�[�W�̏㏸��
}BALLTURNAROUND;


//-----�v���g�^�C�v�錾
HRESULT InitBallTurnAround(void);
void _BallTurnAround(void);
