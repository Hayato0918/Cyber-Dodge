//�X�L��_�n������ [landmines.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;	//���W
	D3DXVECTOR2 size;	//�傫��
	bool use;	//�X�L�����g�p���������Ǘ�����t���O
	bool timeflag;	//�X�L���̓K�p���Ԃ��Ǘ�����t���O

	float time;		//�X�L���̓K�p���Ԃ��Ǘ�����ϐ�

	int xrand;		//x���W�𗐐����ɕK�v�ȕϐ�
	int yrand;		//y���W�̗������ɕK�v�ȕϐ�
	int  possesion; //�n���̏�����
	int usegauge;	//�o�O�Q�[�W�̏㏸��
	int texture;    //�摜
}LANDMINES;

//-----�v���g�^�C�v�錾
HRESULT InitLandMines(void);
void _LandMines(void);
void DrawLandMines(void);
LANDMINES* GetLandMines();