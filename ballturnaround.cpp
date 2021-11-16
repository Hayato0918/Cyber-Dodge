//�X�L��_�G�l�~�[�ǐՏ��� [ballturnaround.cpp]
#include "ballturnaround.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"

#include "enemy.h"
#include "ball.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BALLTURNAROUND ballturnaround;

//-----�O���[�o���ϐ�
float DeclBulletMove = 0.01f;	//�ǐՎ��̑�������

//-----����������
HRESULT InitBallTurnAround(void)
{
	ballturnaround.use = false;
	ballturnaround.usegauge = 30;

	return S_OK;
}



//-----�ǐՏ���
void _BallTurnAround(void)
{
	ENEMY* enemy = GetEnemy();
	BALL* ball = GetBall();

	//-----C�L�[����������A�{�[�����G�֌������Ă���
	if (GetKeyboardTrigger(DIK_C) && ballturnaround.use == false)
	{
		if (ball->enemyhitflag == true)
		{
			float X = enemy->pos.x - ball->pos.x;
			float Y = enemy->pos.y - ball->pos.y;

			ball->rad = atan2(Y, X);

			ball->move.x += ball->pos.x * cos(ball->rad) * DeclBulletMove;
			ball->move.y += ball->pos.y * sin(ball->rad) * DeclBulletMove;

			ball->plyer_oldposY = SCREEN_HEIGHT;
		}
		if (ball->enemyhitflag == false)
			ballturnaround.use = true;
	}
}