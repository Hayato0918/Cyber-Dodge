//エネミー処理[enemy.h]

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

	bool drawflag;	//描画するかを管理するフラグ
}ENEMY;

//-----プロトタイプ宣言
HRESULT InitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);

ENEMY* GetEnemy(void);