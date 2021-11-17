//�v���C���[HP���� [player_hp.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	int gaugeonce;		//�Q�[�W�̊g��(x5)

	D3DXVECTOR2 pos;
	D3DXVECTOR2 framesize;
	int frametexture;

	D3DXVECTOR2 gaugesize;
	int gaugetexture;
}PLAYERHP;

//-----�v���g�^�C�v�錾
HRESULT InitPlayerHp(void);
void UninitPlayerHp(void);
void UpdatePlayerHp(void);
void DrawPlayerHp(void);

PLAYERHP* GetPlayerHp();