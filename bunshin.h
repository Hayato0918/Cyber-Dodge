#pragma once
#include "main.h"
#include "renderer.h"

#define ENEMYCLONE_MAX (1) //num of clones

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

	bool drawflag;	//�`�悷�邩���Ǘ�����t���O
}ENEMYCLONE;

//-----�v���g�^�C�v�錾
HRESULT InitEnemyClone(void);
void UninitEnemyClone(void);
void UpdateEnemyClone(void);
void DrawEnemyClone(void);

ENEMYCLONE* GetEnemyClone(void);