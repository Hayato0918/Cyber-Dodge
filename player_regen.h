//�X�L��_���W�F�l���� [player_regen.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool use;	//�X�L�����g�p���������Ǘ�����t���O
	float time;		//�X�L���̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;	//�X�L���̓K�p���Ԃ��Ǘ�����t���O
	int number;

	int usegauge;	//�o�O�Q�[�W�̏㏸��

	bool bugincrease;
	int bugdrawnum;
}PLAYERREGEN;

//-----�v���g�^�C�v�錾
HRESULT InitPlayerRegen(void);
void _PlayerRegen(void);