//休憩マスコマンド処理 [rest_command.h]
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
	float hp_max;
	float hp;
	int sound;
}REST_HPUP;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;

	int random;
	int sound;
}REST_STATUSUP;

//-----プロトタイプ宣言
HRESULT InitRestCommand(void);
void UninitRestCommand(void);
void UpdateRestCommand(void);
void DrawRestCommand(void);

REST_HPUP* GetRestCommandHP();
REST_STATUSUP* GetRestCommandStatus();