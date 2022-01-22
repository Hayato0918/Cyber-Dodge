//�x�e�}�X�R�}���h���� [rest_command.h]
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
	float hp_max;
	float hp;
}REST_HPUP;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;

	int random;
}REST_STATUSUP;

//-----�v���g�^�C�v�錾
HRESULT InitRestCommand(void);
void UninitRestCommand(void);
void UpdateRestCommand(void);
void DrawRestCommand(void);

REST_HPUP* GetRestCommandHP();
REST_STATUSUP* GetRestCommandStatus();