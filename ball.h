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
	float playerhavetime;  //�v���C���[���{�[���������Ă鎞�Ԃ��v������ϐ�

	bool playerhaveflag;		//�v���C���[���{�[���������Ă��邩�𔻒肷��t���O
	bool playerhitflag;		//�v���C���[�̃A�E�g������Ǘ�����t���O
	bool enemyhaveflag;		//�G�l�~�[���{�[���������Ă��邩�𔻒肷��t���O
	bool enemyhitflag;		//�G�l�~�[�̃A�E�g������Ǘ�����t���O

	float rad;
	float plyer_oldposY;
}BALL;

//-----�v���g�^�C�v�錾
HRESULT InitBall(void);
void UninitBall(void);
void UpdateBall(void);
void DrawBall(void);
void E_Throw(void);
void P_Throw(void);
void _Throw(void);
void AddBallMove(float move, float rotato, float set_pos_y, float set_size_y);

BALL* GetBall();