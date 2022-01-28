//�C�x���g_�T�[�o�[���菈�� [server_recovery.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
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


//-----�v���g�^�C�v�錾
void InitServerRecovery(void);
void UninitServerRecovery(void);
void UpdateServerRecovery(void);
void DrawServerRecovery(void);

SERVER_RECOVERY* GetServer();
SERVER_POINT* GetSuverPoint();