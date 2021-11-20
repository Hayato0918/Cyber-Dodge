#pragma once
#include "main.h"
#include "renderer.h"

#define ENEMYCLONE_MAX (1) //num of clones

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
}ENEMYCLONE;

//-----プロトタイプ宣言
HRESULT InitEnemyClone(void);
void UninitEnemyClone(void);
void UpdateEnemyClone(void);
void DrawEnemyClone(void);

ENEMYCLONE* GetEnemyClone(void);