/*---------------------------------------------
[ プレイヤーの無敵処理　[invincible.cpp]  ]
----------------------------------------------*/

#pragma once

#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	bool use;	//スキルを使用したかを管理するフラグ
	float time;		//スキルの適用時間を管理する変数
	bool timeflag;	//スキルの適用時間を管理するフラグ
	int texture;	   //スキル使用時プレイヤーが無敵状態になっている描画判定

	int usegauge;	//バグゲージの上昇量
}INVINCIBLE;

//-----プロトタイプ宣言
HRESULT InitInvincible(void);
void _Invincible(void);
void DrawInvincible(void);

INVINCIBLE* GetInvincible();