//�X�L��_�X�s�[�h�A�b�v���� [ballspeedup.cpp]
#include "ballspeedup.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "ball.h"
#include "catch.h"
#include "bug.h"

#include "skillrandom.h"

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
	ballspeedup.usegauge = 100;

	return S_OK;
}

//-----���剻����
void _BallSpeedUp(void)
{
	BALL* ball = GetBall();
	BUG* bug = GetBug();
	RANDOM* random = GetRandom();

	//------�v���C���[���{�[���������Ă���ԁA0�L�[����������A�{�[���̑�����+5�����
	if (random->code == 1 && random->active == true && ballspeedup.use == false && ball->playerhaveflag == true)
	{
		//------���������Ƃɖ߂��Ƃ��Ɏg��
		ballspeedup.beforemove = ball->move.x;

		//�������Ă�����ɉ����ĉ�������x�N�g����ς���
		if (ball->move.x > 0)
			ball->move.x = ball->move.x + 5;
		if (ball->move.x < 0)
			ball->move.x = ball->move.x - 5;

		//-----�o�O�Q�[�W�̏㏸
		bug->gaugesize.x = bug->gaugesize.x + ballspeedup.usegauge * bug->gaugeonce;
		ballspeedup.use = true;
	}
}