/*------------------------------------------
[ 暗転 [ Bug_anten.h ] ]
-------------------------------------------*/
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;

	bool use;	//スキルを使用したかを管理するフラグ
	bool drawflag;
	int texture;
}ANTEN;

//-----プロトタイプ宣言
HRESULT InitAnten(void);
void _Anten(void);
void DrawAnten(void);