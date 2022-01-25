//�f���[�^�[AI���� [deleterAI.cpp]
#include "slimeAI.h"
//�V�X�e��.h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "deleter.h"
#include "catch.h"
#include "ball.h"
#include "player.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�
float deleter_throwtime;
float deleter_x, deleter_y;

//-----�G�s���p�^�[��
void DeleterAI()
{
	DELETER* deleter = GetDeleter();
	BALL* ball = GetBall();
	CATCH* Catch = GetCatch();
	PLAYER* player = GetPlayer();


	//-----�{�[���������Ă��Ȃ��Ƃ�
		//-----�{�[���̕�������
	if (ball->enemyhaveflag == false)
	{
		deleter->walktextureflag = false;
		if (ball->pos.x > deleter->pos.x + SCREEN_WIDTH * 0.03125f)
			deleter->rotate = 3;
		if (ball->pos.x < deleter->pos.x + SCREEN_WIDTH * 0.03125f)
			deleter->rotate = 2;
	}

	//-----�{�[�����v���C���[�̐w�n�ɂ���ꍇ�A�㉺���E�ɓ���
	//if (ball->enemyhaveflag== false && ball->pos.x < SCREEN_WIDTH * 0.5)
	//{
	//	if (player->pos.x > SCREEN_WIDTH * 0.25)
	//		enemy->pos.x += 3;
	//	if (player->pos.x < SCREEN_WIDTH * 0.25)
	//		enemy->pos.x -= 3;
	//	if (player->pos.y + player->size.y > SCREEN_HEIGHT * 0.6)
	//		enemy->pos.y += 3;
	//	if (player->pos.y + player->size.y < SCREEN_HEIGHT * 0.6)
	//		enemy->pos.y -= 3;
	//}

	//-----�{�[���ƃG�l�~�[�̈ʒu���v�Z���A�G�l�~�[���{�[����ǂ��悤�ɂ���
	deleter_x = (ball->pos.x - deleter->pos.x - deleter->size.x * 0.5f - ball->size.x) * 0.01f;
	deleter_y = (ball->pos.y - deleter->pos.y - deleter->size.y * 0.5f + ball->size.y) * 0.01f;

	//-----�{�[�����G�w�̒n�ʂɂ���ꍇ�A�{�[���̏ꏊ�܂ōs��
	if (ball->enemyhaveflag == false && ball->pos.x > SCREEN_WIDTH * 0.5f && ball->enemyhitflag == false)
	{
		deleter->walktextureflag = true;
		deleter->pos.x += deleter_x;
		deleter->pos.y += deleter_y;
	}

	//-----�����Ă���{�[���܂ł��ǂ蒅������A�L���b�`����
	if (ball->enemyhitflag == false)
	{
		if (deleter->pos.x + deleter->size.x > ball->pos.x && deleter->pos.x < ball->pos.x + ball->size.x)
		{
			if (deleter->pos.y < ball->pos.y + ball->size.y && deleter->pos.y + deleter->size.y > ball->pos.y)
			{
				deleter->walktextureflag = false;
				M_Catch();
				if (ball->enemyhaveflag == true && deleter->catchtextureflag_2 == false)
				{
					deleter->catchtextureflag = true;
				}
			}
		}
	}

	//-----�{�[���������Ă���Ƃ�
		//-----�v���C���[�̕���������
	if (ball->enemyhaveflag == true)
	{
		deleter->walktextureflag = false;
		if (player->pos.x > deleter->pos.x)
			deleter->rotate = 3;
		if (player->pos.x < deleter->pos.x)
			deleter->rotate = 2;
	}

	//-----������܂ł̊ԁA�v���C���[��y���W��ڎw���Ĉړ�����
	if (ball->enemyhaveflag == true && deleter_throwtime < 60)
	{
		//-----y���v���C���[�ƃG�l�~�[��y���W�̍��ɕύX
		deleter_y = (player->pos.y - deleter->pos.y) * 0.01f;
		deleter->pos.y += deleter_y;
		deleter->walktextureflag = true;
	}

	//-----�{�[����1�b�������瓊����
	if (ball->enemyhaveflag == true)
		deleter_throwtime = deleter_throwtime + 1.0f;
	if (deleter_throwtime > 60)
	{
		deleter->walktextureflag = false;
		deleter->throwtextureflag = true;
		E_Throw();
		deleter_throwtime = 0.0f;
	}
}