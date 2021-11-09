//�v���C���[����[player.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 move;
	int Wtexture;	//�������Ă�������ɑΉ������e�N�X�`��
	int Stexture;	//��
	int Atexture;	//��
	int Dtexture;	//��
	int rotate;		//�����Ă�������擾����ϐ�
}PLAYER;

//-----�v���g�^�C�v�錾
HRESULT InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

PLAYER* GetPlayer(void);