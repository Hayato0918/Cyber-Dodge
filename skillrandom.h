//�X�L�������_�� [skillrandom.h]

#pragma once
#include "main.h"
#include "renderer.h"

#define SKILL_NUM 36

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
	bool haveflag;	//�X�L�����������Ă��邩���Ǘ�����t���O
}RANDOM;

typedef struct
{
	int slot;		//�X�L���̏�����
	int usecount;	//���݂�1�ԑO�̃X�L��
	int num;		//�X�L���̑���:

	bool firstnum;	//�X�L���̏��������𓾂邩�ǂ������Ǘ�����t���O
	int sound;
}SKILL;

//-----�錾
HRESULT InitRandom(void);
void UninitRandom(void);
void UpdateRandom(void);
void DrawRandom(void);

RANDOM* GetRandom();
SKILL* GetSkill();