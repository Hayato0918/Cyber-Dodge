//�^�C�g�������L���O�{�^������ [title_ranking.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	int sound;
}TITLE_RANKING;

//-----�v���g�^�C�v�錾
HRESULT InitTitleRanking(void);
void UninitTitleRanking(void);
void UpdateTitleRanking(void);
void DrawTitleRanking(void);

TITLE_RANKING* GetTitleRanking(void);