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
}MAP;

typedef struct
{
	D3DXVECTOR2 startpos;
	D3DXVECTOR2 startsize;
	D3DXVECTOR2 bosspos;
	D3DXVECTOR2 bosssize;
}MAP_SB;

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 num;
	int texture;
	int LRcount, UDcount;

	D3DXVECTOR2 circlepos;
	D3DXVECTOR2 circlesize;
	int circletexture;
	bool circletextureflag;

	int gamecount;	//ゲームシーンに何回移動したかを管理する変数
	int encount;	//どの敵と戦うかを管理する変数

}MAP_PLAYER;

//-----プロトタイプ宣言
HRESULT InitMapPoint(void);
void UninitMapPoint(void);
void UpdateMapPoint(void);
void DrawMapPoint(void);

//-----プロトタイプ宣言
HRESULT InitMapPlayer(void);
void UninitMapPlayer(void);
void UpdateMapPlayer(void);
void DrawMapPlayer(void);
MAP_PLAYER* GetMapPlayer();