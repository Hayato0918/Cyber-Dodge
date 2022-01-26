//�����L���O_�X�R�A���� [ranking_score.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v;
	bool drawflag;
}RANKING_SCORE;

typedef struct
{
	int gold;
	int texture;
	int a, b, c, d;	//gold��1000�̈ʁA100�̈ʁA10�̈ʁA1�̈�
	bool saveflag;
}RANKING_SCORENUM;

//-----�v���g�^�C�v�錾
HRESULT InitRankingScore(void);
void UninitRankingScore(void);
void UpdateRankingScore(void);
void DrawRankingScore(void);

RANKING_SCORENUM* GetRankingScoreNum();