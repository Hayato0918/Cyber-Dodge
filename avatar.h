//�A�o�^�[�̎c�[���� [avatar.h]

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
}AVATAR;

typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float u, v, uw, vh;
	int texture;
	int count;
	int minus;				//�I�����̃}�X�Ԃ̋���
}AVATARPOINT;

//-----�v���g�^�C�v�錾
void InitAvatar(void);
void UninitAvatar(void);
void UpdateAvatar(void);
void DrawAvatar(void);