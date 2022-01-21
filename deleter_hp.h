//�f���[�^�[HP���� [deleter_hp.h]

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

	D3DXVECTOR2 pos;
	D3DXVECTOR2 gaugesize;
	int gaugeredtexture;
	int gaugegreentexture;

	float hpsize;	//HP�̏����ʂ�ێ�����ϐ�
	bool colorcangeflag;	//HP�̐F���Ǘ�����t���O
}DELETERHP;

//-----�v���g�^�C�v�錾
HRESULT InitDeleterHp(void);
void UninitDeleterHp(void);
void UpdateDeleterHp(void);
void DrawDeleterHp(void);

DELETERHP* GetDeleterHp();