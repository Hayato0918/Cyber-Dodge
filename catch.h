//キャッチ処理 [catch.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	int texture;
	D3DXCOLOR color;
	bool flag;	//キャッチ動作をしているかを管理するフラグ
	bool intervalflag;	//キャッチのインターバルを管理するフラグ
	float intervaltime;	//キャッチのインターバル秒を管理する変数
	float coltime;	//キャッチの当たり判定時間を管理する変数
	bool colflag;	//ボールをキャッチしているかを管理するフラグ
}CATCH;

//-----プロトタイプ宣言
HRESULT InitCatch(void);
void UninitCatch(void);
void UpdateCatch(void);
void DrawCatch(void);
void _Catch(void);