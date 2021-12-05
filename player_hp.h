//プレイヤーHP処理 [player_hp.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	int gaugeonce;		//ゲージの拡大(x5)

	D3DXVECTOR2 framepos;
	D3DXVECTOR2 framesize;
	int frametexture;

	D3DXVECTOR2 pos;
	D3DXVECTOR2 gaugesize;
	int gaugeredtexture;
	int gaugegreentexture;

	float hpsize;	//HPの初期量を保持する変数
	bool colorcangeflag;	//HPの色を管理するフラグ
}PLAYERHP;

//-----プロトタイプ宣言
HRESULT InitPlayerHp(void);
void UninitPlayerHp(void);
void UpdatePlayerHp(void);
void DrawPlayerHp(void);

PLAYERHP* GetPlayerHp();