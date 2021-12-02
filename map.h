//マップ処理 [map.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int randomcode;
	int scenecode;
}MAP;

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 num;
	bool move;		//動いているかを管理するフラグ
	bool moveflag;
	bool movespeedflag;	//目的マスまでの移動距離計算を管理するフラグ
	int texture;
	int LRcount, UDcount;

	D3DXVECTOR2 circlepos;
	D3DXVECTOR2 circlesize;
	int circletexture;
	bool circletextureflag;

	float x, y;

}MAP_PLAYER;

//-----プロトタイプ宣言
HRESULT InitMap(void);
void UninitMap(void);
void UpdateMap(void);
void DrawMap(void);

//-----プロトタイプ宣言
HRESULT InitMapPlayer(void);
void UninitMapPlayer(void);
void UpdateMapPlayer(void);
void DrawMapPlayer(void);
MAP_PLAYER* GetMapPlayer();