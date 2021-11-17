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
	int walk_1texture;
	int walk_2texture;
	bool textureflag;
	int rotate;		//向いてる方向を取得する変数

	bool drawflag;	//描画するかを管理するフラグ

	int hp;			//体力
	int atk;		//攻撃力
	int def;		//防御力
}PLAYER;

//-----プロトタイプ宣言
HRESULT InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

PLAYER* GetPlayer(void);