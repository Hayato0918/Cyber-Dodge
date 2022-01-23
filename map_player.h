//�}�b�v���� [map.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 num;
	int texture;

	int nowpos;
	int UDcount;
	int LRcount;

	int mapnum;

	D3DXVECTOR2 circlepos;
	D3DXVECTOR2 circlesize;
	int circletexture;
	bool circletextureflag;
	int circlenowpos;

	bool nextflag;	//enter�A�ł�h�����߂̂��
	int gamecount;	//�Q�[���V�[���ɉ���ړ����������Ǘ�����ϐ�
	int encount;	//�ǂ̓G�Ɛ키�����Ǘ�����ϐ�
	int eventcode;	//�ǂ̃C�x���g�ɓ��邩���Ǘ�����ϐ�

	int floor;		//�����w�ɂ��邩
}MAP_PLAYER;

//-----�v���g�^�C�v�錾
HRESULT InitMapPlayer(void);
void UninitMapPlayer(void);
void UpdateMapPlayer(void);
void DrawMapPlayer(void);
MAP_PLAYER* GetMapPlayer();