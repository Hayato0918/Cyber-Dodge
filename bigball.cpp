//�X�L��_�{�[�����剻���� [BigBall.cpp]
#include "bigball.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "ball.h"
#include "bugincrease.h"

#include "skillrandom.h"

//-----�}�N����`
#define bigballtime 180		//3s��

//-----�v���g�^�C�v�錾
BIGBALL bigball;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBigBall(void)
{
	bigball.use = false;
	bigball.timeflag = false;
	bigball.time = 0.0f;
	bigball.usegauge = 20;

	return S_OK;
}

//-----�{�[�����剻����
void _BigBall(void)
{
	BALL* ball = GetBall();
	RANDOM* random = GetRandom();
	BUG* bug = GetBugIncrease();;

	//�����_���őI�΂ꂽ��A3s�ԃ{�[���̃T�C�Y���傫���Ȃ�
	for (int i = 0; i < 36; i++)
	{
		if (random[i].code == 5 && random[i].active == true && bigball.use == false)
		{
			bug->gaugesize.x = bug->gaugesize.x + bigball.usegauge * bug->gaugeonce;
			ball->size = D3DXVECTOR2(ball->size.x * 2, ball->size.y * 2);
			bigball.timeflag = true;
			bigball.use = true;
		}
	}
	//�X�L���g�p3s��ɂ��Ƃ̑傫���ɖ߂�
	if (bigball.timeflag == true)
		bigball.time = bigball.time + 1.0f;
	if (bigball.time > bigballtime)
	{
		bigball.timeflag = false;
		ball->size = D3DXVECTOR2(ball->size.x * 0.5f, ball->size.y * 0.5f);
		bigball.time = 0.0f;
	}
}