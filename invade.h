//�X�L��_�s�@�N������ [invade.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool use;	//�X�L�����g�p���������Ǘ�����t���O
	float time;		//�X�L���̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;	//�X�L���̓K�p���Ԃ��Ǘ�����t���O
	int usegauge;

	bool bugincrease;
	int bugdrawnum;
}INVADE;

//-----�v���g�^�C�v�錾
HRESULT InitInvade(void);
void _Invade(void);

INVADE* GetInvade(void);