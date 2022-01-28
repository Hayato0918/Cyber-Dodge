//イベント_サーバー安定処理 [server_recovery.h]

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
}SERVER_RECOVERY;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
	int count;
}SERVER_POINT;


//-----プロトタイプ宣言
void InitServerRecovery(void);
void UninitServerRecovery(void);
void UpdateServerRecovery(void);
void DrawServerRecovery(void);

SERVER_RECOVERY* GetServer();
SERVER_POINT* GetSuverPoint();