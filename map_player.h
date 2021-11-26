//�}�b�v�ړ����� [map_player.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 num;
	bool move;		//�����Ă��邩���Ǘ�����t���O
	bool moveflag;
	bool movespeedflag;	//�ړI�}�X�܂ł̈ړ������v�Z���Ǘ�����t���O
	int texture;
	int LRcount, UDcount;

	D3DXVECTOR2 circlepos;
	D3DXVECTOR2 circlesize;
	int circletexture;
	bool circletextureflag;

	float x, y;

}MAP_PLAYER;

//-----�v���g�^�C�v�錾
HRESULT InitMapPlayer(void);
void UninitMapPlayer(void);
void UpdateMapPlayer(void);
void DrawMapPlayer(void);

MAP_PLAYER* GetMapPlayer();