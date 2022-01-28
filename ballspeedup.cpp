//�X�L��_�{�[���X�s�[�h�A�b�v���� [ballspeedup.cpp]	//�C���ς�
#include "ballspeedup.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "ball.h"
#include "catch.h"
#include "bugincrease.h"

#include "skillrandom.h"
#include "enemybreak.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BALLSPEEDUP ballspeedup;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBallSpeedUp(void)
{
	ballspeedup.move = 5.0f;
	ballspeedup.beforemove = 0.0f;
	ballspeedup.use = false;
	ballspeedup.usegauge = 20;
	ballspeedup.timeflag = false;
	ballspeedup.useflag = false;

	ballspeedup.bugincrease = false;
	ballspeedup.bugdrawnum = 0;

	return S_OK;
}

//-----�{�[���X�s�[�h�A�b�v����
void _BallSpeedUp(void)
{
	BALL* ball = GetBall();
	BUG* bug = GetBugIncrease();
	RANDOM* random = GetRandom();
	BUGGAUGE* buggauge = GetBugGauge();
	ENEMYBREAK* enemybreak = GetEnemyBreak();

	//------�{�[���̑�����1.5�{����
	for (int i = 0; i < SKILL_NUM; i++)
	{
		if (random[i].code == 1 && random[i].active == true && ballspeedup.use == false)
		{
			//------���������Ƃɖ߂��Ƃ��Ɏg��
			ballspeedup.beforemove = ball->move.x;

			//-----�o�O�Q�[�W�̏㏸
			for (int i = 0; i < 20; i++)
			{
				if (buggauge[i].drawflag == false && ballspeedup.bugincrease == false)
				{
					for (int j = i; ballspeedup.bugdrawnum < 4; j++)
					{
						buggauge[j].drawflag = true;
						bug->drawnum = bug->drawnum + 1;
						ballspeedup.bugdrawnum = ballspeedup.bugdrawnum + 1;
					}
					ballspeedup.bugincrease = true;
				}
			}

			//-----���ʂ̓K�p�������
			ballspeedup.timeflag = true;

			//-----�X�L�����g�p������
			ballspeedup.use = true;
		}
	}

	if (ballspeedup.timeflag == true)
	{
		//�{�[���̉�������
		if (ballspeedup.useflag == false)
		{
			ball->move.x = ball->move.x * 1.5f;
			ballspeedup.useflag = true;
		}

		//�G�l�~�[�q�b�g�t���O��false�ɂȂ�����K�p���I������
		if (ball->enemyhitflag == false)
		{
			ball->move.x = ballspeedup.beforemove;
			ballspeedup.timeflag = false;
		}
	}

	if (enemybreak->drawflag == true && ballspeedup.use == true)
	{
		ball->move.x = ballspeedup.beforemove;
		ballspeedup.timeflag = false;
	}
}