/*------------------------------------------
[ 画面割れ [ Bug_screencrack.h ] ]
-------------------------------------------*/
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 move;
	D3DXVECTOR2 size;

	D3DXVECTOR2 oldpos;
	D3DXVECTOR2 oldmove;

	bool use;	//画面割れを使用させるかを管理するフラグ
	bool drawflag;	//テクスチャの使用フラグ
	int texture;
	float time;		//画面割れの適用時間を管理する変数
	float time_yure;	//画面の揺れの適用時間を管理する変数
	bool timeflag;	//画面割れの適用時間を管理するフラグ
	bool bugflag;	//バグ状態移行を管理するフラグ
	float a;		//a値
	D3DXCOLOR color;
}CRACK;

//-----プロトタイプ宣言
HRESULT InitCrack(void);
void _Crack(void);
void DrawCrack(void);
CRACK* GetCrack();