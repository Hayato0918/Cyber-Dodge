//スキルランダム [skillrandom.h]

#pragma once
#include "main.h"
#include "renderer.h"

#define MAX_SLOT 5

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	bool drawflag;		//描画を管理するフラグ
	int code; //割り当てられた乱数を管理する変数
	bool active;	//スキルを使うかどうかを管理するフラグ
	float usetime;
}RANDOM;

typedef struct
{
	int usecount;	//現在の1番前のスキル
	int num;		//スキルの総数
}SKILL;

//-----宣言
HRESULT InitRandom(void);
void UninitRandom(void);
void UpdateRandom(void);
void DrawRandom(void);

RANDOM* GetRandom();