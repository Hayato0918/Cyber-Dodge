#pragma once
//�X�L��_�{�[�������剻���� [PlayerSizeDown.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool use;	//�X�L�����g�p���������Ǘ�����t���O
	float time;		//�X�L���̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;	//�X�L���̓K�p���Ԃ��Ǘ�����t���O
}BIGBALL;

//-----�v���g�^�C�v�錾
HRESULT InitBigBall(void);
void _BigBall(void);