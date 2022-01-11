//�X�L��_�x�[�X�{�[������ [baseball.h]

#pragma once
#include "main.h"
#include "renderer.h"

typedef struct
{
	D3DXVECTOR2 pos;	//���W
	D3DXVECTOR2 size;	//�傫��
	bool use;			//�X�L�����g�p���������Ǘ�����t���O
	float time;			//�X�L���̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;		//�X�L���̓K�p���Ԃ��Ǘ�����t���O
	int texture;		//�e�N�X�`��
	int usegauge;

	bool bugincrease;
	int bugdrawnum;
}BASEBALL;

//-----�v���g�^�C�v�錾
HRESULT InitBaseball(void);
void DrawBaseball(void);
void _Baseball(void);