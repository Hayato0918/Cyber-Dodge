//�X�L��_�}�C���h�n�b�N���� [mindhack.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool use;	//�X�L�����g�p���������Ǘ�����t���O
	float time;		//�X�L���̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;	//�X�L���̓K�p���Ԃ��Ǘ�����t���O

	bool bugincrease;
	int bugdrawnum;
}MINDHACK;

//-----�v���g�^�C�v�錾
HRESULT InitMindhack(void);
void _Mindhack(void);