/*------------------------------------------
[ クリエイト [ create.h ] ]
-------------------------------------------*/
#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;	//座標
	D3DXVECTOR2 size;	//大きさ
	bool use;			//バグ発動を管理するフラグ
	float time;			//バグの適用時間を管理する変数
	bool timeflag;		//バグの適用時間を管理するフラグ
}CREATE;

typedef struct
{
	int texture;
}CREATETEXTURE;

HRESULT InitCreate(void);
void _Create(void);
void DrawCreate(void);
CREATE* GetCreate(int number);
CREATETEXTURE* GetCreateTexture();