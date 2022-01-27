//�X�L��_�p���[�A�b�v���� [player_powerup.h]
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
}POWERUP;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u;
	int texture;
	float time;
}POWERUP_ANIME;

//-----�v���g�^�C�v�錾
HRESULT InitPowerUp(void);
void _PowerUp(void);
void DrawPowerup();