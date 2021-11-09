//�{�[������ [ball.h]

#pragma once
#include "main.h"
#include "renderer.h"

//-----�\����
typedef struct
{
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	D3DXVECTOR2 move;
	float gravity;		//�d�͂�ݒ肵�Ă�ϐ�
	int texture;
	bool throwflag;		//������ꂽ�����Ǘ�����t���O
	float fallpos;		//�������Ƀv���C���[�̍��W���Q�Ƃ���ϐ�
}BALL;

//-----�v���g�^�C�v�錾
HRESULT InitBall(void);
void UninitBall(void);
void UpdateBall(void);
void DrawBall(void);
void _Throw(void);

BALL* GetBall();