//�}�b�v���� [map.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int randomcode;
}MAP;

typedef struct
{
	D3DXVECTOR2 startpos;
	D3DXVECTOR2 startsize;
	D3DXVECTOR2 bosspos;
	D3DXVECTOR2 bosssize;
}MAP_SB;

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 num;
	int texture;
	int LRcount, UDcount;

	D3DXVECTOR2 circlepos;
	D3DXVECTOR2 circlesize;
	int circletexture;
	bool circletextureflag;

	int gamecount;	//�Q�[���V�[���ɉ���ړ����������Ǘ�����ϐ�
	int encount;	//�ǂ̓G�Ɛ키�����Ǘ�����ϐ�

}MAP_PLAYER;

//-----�v���g�^�C�v�錾
HRESULT InitMapPoint(void);
void UninitMapPoint(void);
void UpdateMapPoint(void);
void DrawMapPoint(void);

//-----�v���g�^�C�v�錾
HRESULT InitMapPlayer(void);
void UninitMapPlayer(void);
void UpdateMapPlayer(void);
void DrawMapPlayer(void);
MAP_PLAYER* GetMapPlayer();