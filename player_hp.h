//�v���C���[HP���� [player_hp.h]

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
	D3DXVECTOR2 saidai_pos;		//�ő�HP�������Ă���ꍇ�̊i�[�ꏊ
	D3DXVECTOR2 gaugesize;
	int gaugeredtexture;
	int gaugegreentexture;

	float hpsize;	//HP�̏����ʂ�ێ�����ϐ�
	bool colorcangeflag;	//HP�̐F���Ǘ�����t���O
}PLAYERHP;

//-----�v���g�^�C�v�錾
HRESULT InitPlayerHp(void);
void UninitPlayerHp(void);
void UpdatePlayerHp(void);
void DrawPlayerHp(void);

PLAYERHP* GetPlayerHp();