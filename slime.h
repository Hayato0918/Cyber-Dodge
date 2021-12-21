//�G�l�~�[����[enemy.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 move;
	int texture;	//
	int rotate;		//�����Ă�������擾����ϐ�

	bool drawflag;	//�`�悷�邩���Ǘ�����t���O
	float u, v, uw, vh;
	float walktime;

	bool getskill;		//�X�L������肵�������Ǘ�����t���O

	int hp;			//�̗�
	int atk;		//�U����
	int def;		//�h���
}SLIME;

//-----�v���g�^�C�v�錾
HRESULT InitSlime(void);
void UninitSlime(void);
void UpdateSlime(void);
void DrawSlime(void);

SLIME* GetSlime(void);