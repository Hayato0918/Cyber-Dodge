#pragma once
//�X�L��_�����L���b�`���� [auto_catch.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool use;	//�X�L�����g�p���������Ǘ�����t���O
	float time;		//�X�L���̓K�p���Ԃ��Ǘ�����ϐ�
	float time_2;		//�X�L���g�p���ɓ������{�[�����z���񂹂Ȃ��ׂ̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;	//�X�L���̓K�p���Ԃ��Ǘ�����t���O
	bool timeflag_2;	//�X�L���g�p���ɓ������{�[�����z���񂹂Ȃ��ׂ̓K�p���Ԃ��Ǘ�����t���O
	bool auto_catchflag;	//�X�L���F�I�[�g�L���b�`���@�\���Ă��邩�̃t���O
	bool auto_catch;		//�X�L���F�I�[�g�L���b�`���@�\���A�L���b�`�ɐ����������̏��

	int usegauge;	//�o�O�Q�[�W�̏㏸��
}AUTO;

//-----�v���g�^�C�v�錾
HRESULT InitAuto_c(void);
void _Auto_c(void);

AUTO* GetAuto(void);