//�t�@�C�A�[�E�H�[���`�揈��[slime_animation.cpp]
#include "slime_animation.h"
#include "slime.h"
#include "ball.h"


void slime_animation()
{
	SLIME* slime = GetSlime();
	BALL* ball = GetBall();

	//-----�`��ݒ�
	//-----�~�܂��Ă�Ƃ�
	if (slime->walktextureflag == false)
	{
		if (ball->enemyhaveflag == true)	//�{�[���������Ă���Ƃ�
		{
			if (slime->rotate == 3)		//�E�������Ă���
			{
				slime->standLRflag = false;
				slime->u = 0.5f;
				slime->uw = 0.5f;
			}
			if (slime->rotate == 2)		//���������Ă���
			{
				slime->standLRflag = true;
				slime->u = 0.0f;
				slime->uw = 0.5f;
			}
		}

		if (ball->enemyhaveflag == false)	//�{�[���������Ă��Ȃ��Ƃ�
		{
			if (slime->rotate == 3)		//�E�������Ă���
			{
				slime->u = 0.0f;
				slime->uw = 0.5f;
				slime->standLRflag = false;
			}
			if (slime->rotate == 2)		//���������Ă���
			{
				slime->u = 0.5f;
				slime->uw = 0.5f;
				slime->standLRflag = true;
			}
		}
	}


	//-----�����Ă���Ƃ�
	if (slime->walktextureflag == true)
	{
		slime->walktexturetime = slime->walktexturetime + 1.0f;
		if (slime->rotate == 3)		//�E�������Ă���
		{
			slime->walkLRflag = false;
			if (slime->walktexturetime < 20)
			{
				slime->u = 0.0f;
				slime->uw = 0.5f;
			}
			if (slime->walktexturetime >= 20 && slime->walktexturetime < 40)
			{
				slime->u = 0.5f;
				slime->uw = 0.5f;
			}
			if (slime->walktexturetime >= 40)
				slime->walktexturetime = 0.0f;
		}
		if (slime->rotate == 2)		//���������Ă���
		{
			slime->walkLRflag = true;
			if (slime->walktexturetime < 20)
			{
				slime->u = 0.0f;
				slime->uw = 0.5f;
			}
			if (slime->walktexturetime >= 20 && slime->walktexturetime < 40)
			{
				slime->u = 0.5f;
				slime->uw = 0.5f;
			}
			if (slime->walktexturetime >= 40)
				slime->walktexturetime = 0.0f;
		}
	}
	if (slime->walktextureflag == false)
		slime->walktexturetime = 0.0f;


	//�������Ƃ�
	if (ball->playerhitflag == true)
	{
		slime->throwtexturetime = slime->throwtexturetime + 1.0f;
		if (slime->rotate == 3)		//�E�������Ă�����
		{
			slime->throwtextureflag = true;
			slime->throwLRflag = false;
			if (slime->throwtexturetime < 5)	//
			{
				slime->u = 0.0f;
				slime->uw = 0.17f;
			}
			if (slime->throwtexturetime >= 5 && slime->throwtexturetime < 10)
			{
				slime->u = 0.17f;
				slime->uw = 0.17f;
			}
			if (slime->throwtexturetime >= 10 && slime->throwtexturetime < 15)
			{
				slime->u = 0.34f;
				slime->uw = 0.17f;
			}
			if (slime->throwtexturetime >= 15 && slime->throwtexturetime < 20)
			{
				slime->u = 0.51f;
				slime->uw = 0.17f;
			}
			if (slime->throwtexturetime >= 20 && slime->throwtexturetime < 25)
			{
				slime->u = 0.68f;
				slime->uw = 0.16f;
			}
			if (slime->throwtexturetime >= 25 && slime->throwtexturetime < 30)
			{
				slime->u = 0.84f;
				slime->uw = 0.16f;
			}
			if (slime->throwtexturetime >= 30)
			{
				slime->throwtextureflag = false;
				slime->throwtexturetime = 0.0f;
				ball->playerhitflag = false;
			}
		}
		if (slime->rotate == 2)		//���������Ă�����
		{
			slime->throwtextureflag = true;
			slime->throwLRflag = true;
			if (slime->throwtexturetime < 5)	//
			{
				slime->u = 0.84f;
				slime->uw = 0.16f;
			}
			if (slime->throwtexturetime >= 5 && slime->throwtexturetime < 10)
			{
				slime->u = 0.68f;
				slime->uw = 0.16f;
			}
			if (slime->throwtexturetime >= 10 && slime->throwtexturetime < 15)
			{
				slime->u = 0.51f;
				slime->uw = 0.17f;
			}
			if (slime->throwtexturetime >= 15 && slime->throwtexturetime < 20)
			{
				slime->u = 0.34f;
				slime->uw = 0.17f;
			}
			if (slime->throwtexturetime >= 20 && slime->throwtexturetime < 25)
			{
				slime->u = 0.17f;
				slime->uw = 0.17f;
			}
			if (slime->throwtexturetime >= 25 && slime->throwtexturetime < 30)
			{
				slime->u = 0.0f;
				slime->uw = 0.17f;
			}
			if (slime->throwtexturetime >= 30)
			{
				slime->throwtextureflag = false;
				slime->throwtexturetime = 0.0f;
				ball->playerhitflag = false;
			}
		}


	}

	//�_���[�W���󂯂���
	if (slime->damagetextureflag == true)
	{
		slime->damagetexturetime = slime->damagetexturetime + 1.0f;
		if (slime->rotate == 3)		//�E�������Ă�����
		{
			slime->damageLRflag = false;
			if (slime->damagetexturetime < 10)	//
			{
				slime->u = 0.0f;
				slime->uw = 0.7f;
			}
			if (slime->damagetexturetime >= 10)
			{
				slime->damagetextureflag = false;
				slime->damagetexturetime = 0.0f;
			}
		}

		if (slime->rotate == 2)		//���������Ă�����
		{
			slime->damageLRflag = true;
			if (slime->damagetexturetime < 10)	//
			{
				slime->u = 0.3f;
				slime->uw = 0.7f;
			}
			if (slime->damagetexturetime >= 10)
			{
				slime->damagetextureflag = false;
				slime->damagetexturetime = 0.0f;
			}
		}
	}
}