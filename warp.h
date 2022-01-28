
//スキル_ワープ処理 [warp.h]
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 player_pos;
	D3DXVECTOR2 player_size;

	D3DXVECTOR2 enemy_pos;
	D3DXVECTOR2 enemy_size;

	bool warp_flag;		//ワープする時のフラグ
	int texture;	//ワープホールのテクスチャ
	bool use;	//スキルを使用したかを管理するフラグ
	float time;		//スキルの適用時間を管理する変数
	bool timeflag;	//スキルの適用時間を管理するフラグ

	bool bugincrease;
	int bugdrawnum;
}WARP;

//-----プロトタイプ宣言
HRESULT InitWarp(void);
void _Warp(void);
void DrawWarp(void);
WARP* GetWarp();