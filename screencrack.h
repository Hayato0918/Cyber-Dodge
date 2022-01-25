/*------------------------------------------
[ ��ʊ��� [ Bug_screencrack.h ] ]
-------------------------------------------*/
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 move;
	D3DXVECTOR2 size;

	D3DXVECTOR2 oldpos;
	D3DXVECTOR2 oldmove;

	bool use;	//��ʊ�����g�p�����邩���Ǘ�����t���O
	bool drawflag;	//�e�N�X�`���̎g�p�t���O
	int texture;
	float time;		//��ʊ���̓K�p���Ԃ��Ǘ�����ϐ�
	float time_yure;	//��ʂ̗h��̓K�p���Ԃ��Ǘ�����ϐ�
	bool timeflag;	//��ʊ���̓K�p���Ԃ��Ǘ�����t���O
	bool bugflag;	//�o�O��Ԉڍs���Ǘ�����t���O
	float a;		//a�l
	D3DXCOLOR color;
}CRACK;

//-----�v���g�^�C�v�錾
HRESULT InitCrack(void);
void _Crack(void);
void DrawCrack(void);
CRACK* GetCrack();