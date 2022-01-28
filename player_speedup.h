//�X�L��_�X�s�[�h�A�b�v���� [player_speedup.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool use;	//�X�L�����g�p���������Ǘ�����t���O
	float time;		//�X�L���̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;	//�X�L���̓K�p���Ԃ��Ǘ�����t���O

	int usegauge;	//�o�O�Q�[�W�̏㏸��

	bool bugincrease;
	int bugdrawnum;
}SPEEDUP;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u;
	int texture;
	float time;
}SPEEDUP_ANIME;

//-----�v���g�^�C�v�錾
HRESULT InitSpeedUp(void);
void _SpeedUp(void);
void DrawSpeedup();

SPEEDUP_ANIME* GetSpeedup();