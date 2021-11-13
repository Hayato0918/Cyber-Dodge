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
	D3DXVECTOR2 startmove;	//����������move��ۑ����Ă����ϐ�
	int throwway;	//�v���C���[�̌����ɉ����ă{�[���̃x�N�g����ς���
	float gravity;		//�d�͂�ݒ肵�Ă�ϐ�
	int texture;
	bool throwflag;		//������ꂽ�����Ǘ�����t���O
	float fallpos;		//�������Ƀv���C���[�̍��W���Q�Ƃ���ϐ�

	bool playerhaveflag;		//�v���C���[���{�[���������Ă��邩�𔻒肷��t���O
	bool enemyhaveflag;		//�G�l�~�[���{�[���������Ă��邩�𔻒肷��t���O
	bool playerhitflag;		//�v���C���[�̃A�E�g������Ǘ�����t���O
	bool enemyhitflag;		//�G�l�~�[�̃A�E�g������Ǘ�����t���O
}BALL;

//-----�v���g�^�C�v�錾
HRESULT InitBall(void);
void UninitBall(void);
void UpdateBall(void);
void DrawBall(void);
void _Throw(void);

BALL* GetBall();