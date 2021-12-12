//�X�L�������_�� [skillrandom.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool drawflag;		//�`����Ǘ�����t���O
	int code; //���蓖�Ă�ꂽ�������Ǘ�����ϐ�
	bool active;	//�X�L�����g�����ǂ������Ǘ�����t���O
	float usetime;
}RANDOM;

typedef struct
{
	int slot;		//�X�L���̏�����
	int usecount;	//���݂�1�ԑO�̃X�L��
	int num;		//�X�L���̑���
}SKILL;

//-----�錾
HRESULT InitRandom(void);
void UninitRandom(void);
void UpdateRandom(void);
void DrawRandom(void);

RANDOM* GetRandom();