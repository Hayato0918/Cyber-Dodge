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
	D3DXVECTOR2 startmove;	//初期化時のmoveを保存しておく変数
	int throwway;	//プレイヤーの向きに応じてボールのベクトルを変える
	float gravity;		//重力を設定してる変数
	int texture;
	bool throwflag;		//投げられたかを管理するフラグ
	float fallpos;		//落下時にプレイヤーの座標を参照する変数
	float playerhavetime;  //プレイヤーがボールを持ってる時間を計測する変数

	bool playerhaveflag;		//プレイヤーがボールを持っているかを判定するフラグ
	bool playerhitflag;		//プレイヤーのアウト判定を管理するフラグ
	bool enemyhaveflag;		//エネミーがボールを持っているかを判定するフラグ
	bool enemyhitflag;		//エネミーのアウト判定を管理するフラグ

	float rad;
	float plyer_oldposY;
}BALL;

//-----プロトタイプ宣言
HRESULT InitBall(void);
void UninitBall(void);
void UpdateBall(void);
void DrawBall(void);
void E_Throw(void);
void P_Throw(void);
void _Throw(void);
void AddBallMove(float move, float rotato, float set_pos_y, float set_size_y);

BALL* GetBall();