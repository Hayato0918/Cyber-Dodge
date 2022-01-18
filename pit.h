/*------------------------------------------
[ �N���G�C�g [ pit.h ] ]
-------------------------------------------*/
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;	//���W
	D3DXVECTOR2 size;	//�傫��
	int texture;		//�e�N�X�`��
	bool use;			//�o�O�������Ǘ�����t���O
	float time;			//�o�O�̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;		//�o�O�̓K�p���Ԃ��Ǘ�����t���O
	bool drawflag;

}PIT;

HRESULT InitPit(void);
void _Pit(void);
void DrawPit(void);
PIT* GetPit(int number);
