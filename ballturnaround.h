//�X�L��_�G�l�~�[�ǐՏ���[ballturnaround.h]
#pragma once

#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	int use;	//�X�L�����g�p���������Ǘ�����t���O

	//��Ɨp�ϐ�
	float b_x;//�o���_
	float b_y;//�o���_
	float f_x;//�����_
	float f_y;//�����_
	float a;
	int n;
	bool n_flag;
	bool n_flag_2;

	int usegauge;	//�o�O�Q�[�W�̏㏸��
	bool bugincrease;
	int bugdrawnum;
}BALLTURNAROUND;

//-----�v���g�^�C�v�錾
HRESULT InitBallTurnAround(void);
void _BallTurnAround(void);
BALLTURNAROUND* GetBallTurnAround(void);
void SetBallTurnAround(void);
void SetBallTurnAround_2(void);
void SetBallTurnAround_3(void);