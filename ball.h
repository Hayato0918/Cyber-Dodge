//ボール処理 [ball.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 move;
	float gravity;		//重力を設定してる変数
	int texture;
	bool throwflag;		//投げられたかを管理するフラグ
	float fallpos;		//落下時にプレイヤーの座標を参照する変数

	bool playerhaveflag;		//プレイヤーがボールを持っているかを判定するフラグ
	bool enemyhaveflahg;		//エネミーがボールを持っているかを判定するフラグ
	bool playerhitflag;		//プレイヤーのアウト判定を管理するフラグ
	bool enemyhitflag;		//エネミーのアウト判定を管理するフラグ
}BALL;

//-----プロトタイプ宣言
HRESULT InitBall(void);
void UninitBall(void);
void UpdateBall(void);
void DrawBall(void);
void P_Throw(void);
void M_Throw(void);

BALL* GetBall();