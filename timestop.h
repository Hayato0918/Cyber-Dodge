//�X�L��_���Ԓ�~���� [timestop.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	bool use;	//�X�L�����g�p���������Ǘ�����t���O
	float time;		//�X�L���̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;	//�X�L���̓K�p���Ԃ��Ǘ�����t���O
	D3DXVECTOR2 posnow;	//�G���s���s�ɂ��邽�߂̈ꎞ�I�Ȋi�[�ꏊ

	int usegauge;	//�o�O�Q�[�W�̏㏸��

	bool bugincrease;
	int bugdrawnum;

	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int u;
}TIMESTOP;

//-----�v���g�^�C�v�錾
HRESULT InitTimestop(void);
void _Timestop(void);
void DrawTimestop(void);
TIMESTOP* GetTimestop();