//�X�L��_�X���[�G���A���� [slowarea.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	int xrand;		//x���W�𗐐����ɕK�v�ȕϐ�
	int yrand;		//y���W�̗������ɕK�v�ȕϐ�
	D3DXVECTOR2 size;
	int texture;
	bool use;	//�X�L�����g�p���������Ǘ�����t���O
	float time;		//�X�L���̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;	//�X�L���̓K�p���Ԃ��Ǘ�����t���O
	int usegauge;
}SLOWAREA;

//-----�v���g�^�C�v�錾
HRESULT InitSlowArea(void);
void _SlowArea(void);
void DrawSlowArea(void);