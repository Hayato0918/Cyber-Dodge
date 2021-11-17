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
	int walk_1texture;
	int walk_2texture;
	bool textureflag;
	int rotate;		//�����Ă�������擾����ϐ�

	bool drawflag;	//�`�悷�邩���Ǘ�����t���O

	int hp;			//�̗�
	int atk;		//�U����
	int def;		//�h���
}PLAYER;

//-----�v���g�^�C�v�錾
HRESULT InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

PLAYER* GetPlayer(void);