/*------------------------------------------
[ �Ó] [ Bug_anten.h ] ]
-------------------------------------------*/
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;

	bool use;	//�X�L�����g�p���������Ǘ�����t���O
	bool drawflag;
	int texture;
}ANTEN;

//-----�v���g�^�C�v�錾
HRESULT InitAnten(void);
void _Anten(void);
void DrawAnten(void);