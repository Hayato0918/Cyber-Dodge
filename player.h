//プレイヤー処理[player.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 move;
	int Wtexture;	//↑向いている方向に対応したテクスチャ
	int Stexture;	//↓
	int Atexture;	//←
	int Dtexture;	//→
	int rotate;		//向いてる方向を取得する変数
}PLAYER;

//-----プロトタイプ宣言
HRESULT InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

PLAYER* GetPlayer(void);