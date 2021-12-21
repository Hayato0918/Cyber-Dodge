//�X�L��_�G�l�~�[�ǐՏ��� [ballturnaround.cpp]
#include "ballturnaround.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"
#include "input.h"
//�G�l�~�[.h
#include "firewall.h"
#include "ball.h"
#include "bugincrease.h"

#include "skillrandom.h"

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
	FIREWALL* firewall = GetFireWall();
	BALL* ball = GetBall();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();

	//-----�{�[�����G�֌������Ă���
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 2 && random[i].active == true && ballturnaround.use == false && ball->playerthrowflag == true)
		{
			if (ball->enemyhitflag == true)
			{
				float X = firewall->pos.x - ball->pos.x;
				float Y = firewall->pos.y - ball->pos.y;

				ball->rad = atan2(Y, X);

				ball->move.x += ball->pos.x * cos(ball->rad) * DeclBulletMove;
				ball->move.y += ball->pos.y * sin(ball->rad) * DeclBulletMove;

				ball->plyer_oldposY = SCREEN_HEIGHT;
			}
			if (ball->enemyhitflag == false)
				ballturnaround.use = true;

			//-----�o�O�Q�[�W�̏㏸
			bug->gaugesize.x = bug->gaugesize.x + ballturnaround.usegauge * bug->gaugeonce;
			ballturnaround.use = true;
		}
	}
}