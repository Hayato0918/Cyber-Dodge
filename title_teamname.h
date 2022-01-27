//�^�C�g���`�[�����S���� [title_teamname.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXCOLOR color;
	int texture;
	float a;	//a�l
	float time;	//�o�ߎ���

	bool timeflag;

	int call;
	int callrandom;
}TITLE_TEAMNAME;

//-----�v���g�^�C�v�錾
HRESULT InitTitleTeamName(void);
void UninitTitleTeamName(void);
void UpdateTitleTeamName(void);
void DrawTitleTeamName(void);

TITLE_TEAMNAME* GetTitleTeamName();