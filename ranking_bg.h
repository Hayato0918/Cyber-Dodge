//�����L���O_�w�i���� [ranking_bg.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
}RANKING_BG;

//-----�v���g�^�C�v�錾
HRESULT InitRankingBG(void);
void UninitRankingBG(void);
void UpdateRankingBG(void);
void DrawRankingBG(void);