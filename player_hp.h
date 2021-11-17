//プレイヤーHP処理 [player_hp.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	int gaugeonce;		//ゲージの拡大(x5)

	D3DXVECTOR2 pos;
	D3DXVECTOR2 framesize;
	int frametexture;

	D3DXVECTOR2 gaugesize;
	int gaugetexture;
}PLAYERHP;

//-----プロトタイプ宣言
HRESULT InitPlayerHp(void);
void UninitPlayerHp(void);
void UpdatePlayerHp(void);
void DrawPlayerHp(void);

PLAYERHP* GetPlayerHp();