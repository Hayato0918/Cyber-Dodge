//�}�b�v�ړ����� [map_player.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 distance;
	D3DXVECTOR2 num;
	int texture;
	int LRcount, UDcount;
}MAP_PLAYER;

//-----�v���g�^�C�v�錾
HRESULT InitMapPlayer(void);
void UninitMapPlayer(void);
void UpdateMapPlayer(void);
void DrawMapPlayer(void);

MAP_PLAYER* GetMapPlayer();