/*---------------------------------------------
[ �v���C���[�̖��G�����@[invincible.cpp]  ]
----------------------------------------------*/

#pragma once

#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	bool use;	//�X�L�����g�p���������Ǘ�����t���O
	float time;		//�X�L���̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;	//�X�L���̓K�p���Ԃ��Ǘ�����t���O
	int texture;	   //�X�L���g�p���v���C���[�����G��ԂɂȂ��Ă���`�攻��

	int usegauge;	//�o�O�Q�[�W�̏㏸��
}INVINCIBLE;

//-----�v���g�^�C�v�錾
HRESULT InitInvincible(void);
void _Invincible(void);
void DrawInvincible(void);

INVINCIBLE* GetInvincible();