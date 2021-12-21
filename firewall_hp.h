//�t�@�C�A�[�E�H�[��HP���� [enemy_hp.h]

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
}FIREWALLHP;

//-----�v���g�^�C�v�錾
HRESULT InitFireWallHp(void);
void UninitFireWallHp(void);
void UpdateFireWallHp(void);
void DrawFireWallHp(void);

FIREWALLHP* GetFireWallHp();