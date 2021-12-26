//�x�e�}�X�I������ [rest_select.h]
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
	int count;
}REST_SELECT;


//-----�v���g�^�C�v�錾
HRESULT InitRestSelect(void);
void UninitRestSelect(void);
void UpdateRestSelect(void);
void DrawRestSelect(void);

REST_SELECT* GetRestSelect();