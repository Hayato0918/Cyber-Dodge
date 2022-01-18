//�o�O�Q�[�W���� [bug.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	int gaugeonce;		//�Q�[�W�̊g��(x8)

	D3DXVECTOR2 framepos;
	D3DXVECTOR2 framesize;
	int frametexture;
	int breaktexture;
	bool breakflag;		//�o�O���������āA�Q�[�W����ꂽ��Ԃ��Ǘ�����t���O
	float breaktime;	//�o�O�Q�[�W����ꂽ��Ԃ��Ǘ�����ϐ�

	D3DXVECTOR2 gaugepos;
	D3DXVECTOR2 gaugesize;
	int drawnum;
	int gaugetexture;
	float decreasetime;
	bool decreaseflag;

	bool gaugeoverflag;	//�ՊE��ԂɂȂ��������Ǘ�����t���O
	float gaugeovertime;

	int numbertexture;
}BUG;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	bool drawflag;
}BUGGAUGE;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u;
	float v;
	float uw;
	float vh;
	bool drawflag;
}BUGNUMBER;

//-----�v���g�^�C�v�錾
HRESULT InitBugIncrease(void);
void UninitBugIncrease(void);
void UpdateBugIncrease(void);
void DrawBugIncrease(void);

BUG* GetBugIncrease();
BUGGAUGE* GetBugGauge();