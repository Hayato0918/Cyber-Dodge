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
	int texture;	//
	int rotate;		//向いてる方向を取得する変数

	bool drawflag;	//描画するかを管理するフラグ
	float u, v, uw, vh;
	float walktime;

	bool getskill;		//スキルを入手したかを管理するフラグ

	int hp;			//体力
	int atk;		//攻撃力
	int def;		//防御力
}SLIME;

//-----プロトタイプ宣言
HRESULT InitSlime(void);
void UninitSlime(void);
void UpdateSlime(void);
void DrawSlime(void);

SLIME* GetSlime(void);