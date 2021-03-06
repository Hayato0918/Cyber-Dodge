//マップ処理 [map.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 num;
	int texture;
	int sound;

	int nowpos;
	int UDcount;
	int LRcount;

	int mapnum;

	D3DXVECTOR2 circlepos;
	D3DXVECTOR2 circlesize;
	int circletexture;
	bool circletextureflag;
	int circlenowpos;

	bool nextflag;	//enter連打を防ぐためのやつ
	int gamecount;	//ゲームシーンに何回移動したかを管理する変数
	int encount;	//どの敵と戦うかを管理する変数
	bool enemypowerup;	//強敵マスに入ったかを管理する変数
	int eventcode;	//どのイベントに入るかを管理する変数

	int floor;		//今何層にいるか
}MAP_PLAYER;

//-----プロトタイプ宣言
HRESULT InitMapPlayer(void);
void UninitMapPlayer(void);
void UpdateMapPlayer(void);
void DrawMapPlayer(void);
MAP_PLAYER* GetMapPlayer();