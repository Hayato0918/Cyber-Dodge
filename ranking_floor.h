//�����L���O_�t���A���� [ranking_floor.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	int floornum;
	int texture;
	bool saveflag;
}RANKING_FLOORNUM;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	float u, v;
	bool drawflag;
}RANKING_FLOOR;

//-----�v���g�^�C�v�錾
HRESULT InitRankingFloor(void);
void UninitRankingFloor(void);
void UpdateRankingFloor(void);
void DrawRankingFloor(void);

RANKING_FLOORNUM* GetRankingFloorNum();
RANKING_FLOOR* GetRankingFloor();