//�}�b�v�ړ����� [map_hack.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;			//���j���[�̘g
	D3DXVECTOR2 frame_pos;
	D3DXVECTOR2 frame_size;
	int frametexture;				//�I������ۂ̘g

	int UDcount;		//SetMap�ɓ���鐔��������ϐ�
	bool isUse;

}MAP_HACK;

//-----�v���g�^�C�v�錾
HRESULT InitMapHack(void);
void UninitMapHack(void);
void UpdateMapHack(void);
void DrawMapHack(void);

MAP_HACK* GetMapHack();