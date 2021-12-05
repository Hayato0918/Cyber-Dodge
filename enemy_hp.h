//エネミーHP処理 [enemy_hp.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	int gaugeonce;		//ゲージの拡大(x8)

	D3DXVECTOR2 framepos;
	D3DXVECTOR2 framesize;
	int frametexture;

	D3DXVECTOR2 pos;
	D3DXVECTOR2 gaugesize;
	int gaugeredtexture;
	int gaugegreentexture;

	float hpsize;	//HPの初期量を保持する変数
	bool colorcangeflag;	//HPの色を管理するフラグ
}ENEMYHP;

//-----プロトタイプ宣言
HRESULT InitEnemyHp(void);
void UninitEnemyHp(void);
void UpdateEnemyHp(void);
void DrawEnemyHp(void);

ENEMYHP* GetEnemyHp();