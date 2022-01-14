/*------------------------------------------
[ �G���A�ω� [ areaChange.h ] ]
-------------------------------------------*/
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;	//���W
	D3DXVECTOR2 move;	//�ړ�
	bool use;			//�o�O�������Ǘ�����t���O
	int time;			//�o�O�̓K�p���Ԃ��Ǘ�����ϐ�
	int counttime;		//�����J�E���g����ϐ�
	bool finishflag;	//�I������ۂ̏������Ǘ�����t���O
	bool timeflag;		//�o�O�̓K�p���Ԃ��Ǘ�����t���O
}AREACHANGE;

HRESULT InitAreaChange(void);
void _AreaChange(void);
AREACHANGE* GetAreaChange(void);