//アバターの残骸処理 [avatar.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----構造体
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
}AVATAR;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
	int count;
	int minus;				//選択肢のマス間の距離
}AVATARPOINT;

//-----プロトタイプ宣言
void InitAvatar(void);
void UninitAvatar(void);
void UpdateAvatar(void);
void DrawAvatar(void);