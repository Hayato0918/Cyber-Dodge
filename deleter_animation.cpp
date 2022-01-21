//�f���[�^�[�`�揈��[deleter_animation.cpp]
#include "deleter_animation.h"
#include "deleter.h"


void deleter_animation()
{
	DELETER* deleter = GetDeleter();

	//-----�`��ݒ�
	//-----�~�܂��Ă�Ƃ�
	if (deleter->walktextureflag == false)
	{
		deleter->standtexturetime = deleter->standtexturetime + 1.0f;
		if (deleter->rotate == 3)		//�E�������Ă���
		{
			deleter->standLRflag = false;
			if (deleter->standtexturetime < 27)
			{
				deleter->u = 0.67f;
				deleter->uw = 0.33f;
			}
			if (deleter->standtexturetime >= 27 && deleter->standtexturetime < 54)
			{
				deleter->u = 0.34f;
				deleter->uw = 0.33f;
			}
			if (deleter->standtexturetime >= 54 && deleter->standtexturetime < 81)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.34f;
			}
			if (deleter->standtexturetime >= 81)
				deleter->standtexturetime = 0.0f;
		}
		if (deleter->rotate == 2)		//���������Ă���
		{
			deleter->standLRflag = true;
			if (deleter->standtexturetime < 27)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.32f;
			}
			if (deleter->standtexturetime >= 27 && deleter->standtexturetime < 54)
			{
				deleter->u = 0.32f;
				deleter->uw = 0.32f;
			}
			if (deleter->standtexturetime >= 54 && deleter->standtexturetime < 81)
			{
				deleter->u = 0.64f;
				deleter->uw = 0.32f;
			}
			if (deleter->standtexturetime >= 81)
				deleter->standtexturetime = 0.0f;
		}
	}

	//-----�����Ă���Ƃ�
	if (deleter->walktextureflag == true)
	{
		deleter->walktexturetime = deleter->walktexturetime + 1.0f;
		if (deleter->rotate == 3)		//�E�������Ă���
		{
			deleter->walkLRflag = false;
			if (deleter->walktexturetime < 20)
			{
				deleter->u = 0.67f;
				deleter->uw = 0.33f;
			}
			if (deleter->walktexturetime >= 20 && deleter->walktexturetime < 40)
			{
				deleter->u = 0.34f;
				deleter->uw = 0.33f;
			}
			if (deleter->walktexturetime >= 40 && deleter->walktexturetime < 60)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.33f;
			}
			if (deleter->walktexturetime >= 60)
				deleter->walktexturetime = 0.0f;
		}
		if (deleter->rotate == 2)		//���������Ă���
		{
			deleter->walkLRflag = true;
			if (deleter->walktexturetime < 20)
			{
				deleter->u = 0.0f;
				deleter->uw = 0.33f;
			}
			if (deleter->walktexturetime >= 20 && deleter->walktexturetime < 40)
			{
				deleter->u = 0.33f;
				deleter->uw = 0.33f;
			}
			if (deleter->walktexturetime >= 40 && deleter->walktexturetime < 60)
			{
				deleter->u = 0.66f;
				deleter->uw = 0.34f;
			}
			if (deleter->walktexturetime >= 60)
				deleter->walktexturetime = 0.0f;
		}
	}
	if (deleter->walktextureflag == false)
		deleter->walktexturetime = 0.0f;

	//-----�L���b�`�����Ƃ�
	//if()

	//-----���񂾂Ƃ�
	if (deleter->drawflag == false)
	{
		deleter->u = 0.0f;
		deleter->uw = 1.0f;
	}
}