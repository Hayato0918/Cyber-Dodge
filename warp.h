
//�X�L��_���[�v���� [warp.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 player_pos;
	D3DXVECTOR2 player_size;

	D3DXVECTOR2 enemy_pos;
	D3DXVECTOR2 enemy_size;

	bool warp_flag;		//���[�v���鎞�̃t���O
	int texture;	//���[�v�z�[���̃e�N�X�`��
	bool use;	//�X�L�����g�p���������Ǘ�����t���O
	float time;		//�X�L���̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;	//�X�L���̓K�p���Ԃ��Ǘ�����t���O

	bool bugincrease;
	int bugdrawnum;
}WARP;

//-----�v���g�^�C�v�錾
HRESULT InitWarp(void);
void _Warp(void);
void DrawWarp(void);
WARP* GetWarp();