//キャッチ処理 [catch.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 playerpos;	//プレイヤー側のキャッチゾーンの位置
	D3DXVECTOR2 size;
	int texture;
	D3DXCOLOR color;
	bool playerflag;	//プレイヤーがキャッチ動作をしているかを管理するフラグ
	bool playerintervalflag;	//プレイヤーのキャッチのインターバルを管理するフラグ
	float playerintervaltime;	//プレイヤーのキャッチのインターバル秒を管理する変数
	float playercoltime;	//プレイヤーのキャッチの当たり判定時間を管理する変数
	bool playercolflag;	//プレイヤーがボールをキャッチしているかを管理するフラグ

	D3DXVECTOR2 enemypos;	//エネミー側のキャッチゾーンの位置
	bool enemyflag;		//エネミーがキャッチ動作をしているかを管理するフラグ
	bool enemyintervalflag;	//エネミーのキャッチのインターバルを管理するフラグ
	float enemyintervaltime;	//エネミーのキャッチのインターバル秒を管理する変数
	float enemycoltime;	//エネミーのキャッチの当たり判定時間を管理する変数
	bool enemycolflag;	//エネミーがボールをキャッチしているかを管理するフラグ
	bool enemyAIcatch;	//エネミーがキャッチ動作をしたときに使うフラグ
}CATCH;

//-----プロトタイプ宣言
HRESULT InitCatch(void);
void UninitCatch(void);
void UpdateCatch(void);
void DrawCatch(void);
void P_Catch(void);
void M_Catch(void);

CATCH* GetCatch(void);