//タイトルチームロゴ処理 [title_teamname.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXCOLOR color;
	int texture;
	float a;	//a値
	float time;	//経過時間

	bool timeflag;

	int call;
	int callrandom;
}TITLE_TEAMNAME;

//-----プロトタイプ宣言
HRESULT InitTitleTeamName(void);
void UninitTitleTeamName(void);
void UpdateTitleTeamName(void);
void DrawTitleTeamName(void);

TITLE_TEAMNAME* GetTitleTeamName();