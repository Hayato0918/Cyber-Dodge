//�X�L��_�v���C���[���������Ȃ鏈�� [PlayerSizeDown.h]

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
}SMALLPLAYER;

//-----�v���g�^�C�v�錾
HRESULT InitSmallPlayer(void);
void _SmallPlayer(void);