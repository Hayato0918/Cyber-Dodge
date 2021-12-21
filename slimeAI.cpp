//�X���C��AI���� [slimeAI.cpp]
#include "slimeAI.h"
//�V�X�e��.h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "slime.h"
#include "catch.h"
#include "ball.h"
#include "player.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�
float slime_throwtime;
float slime_x, slime_y;

//-----�G�s���p�^�[��
void SlimeAI()
{
	SLIME* slime = GetSlime();
	BALL* ball = GetBall();
	CATCH* Catch = GetCatch();
	PLAYER* player = GetPlayer();


	//-----�{�[���������Ă��Ȃ��Ƃ�
		//-----�{�[���̕�������
	if (ball->enemyhaveflag == false)
	{
		if (ball->pos.x > slime->pos.x + 50.0f)
			slime->rotate = 3;
		if (ball->pos.x < slime->pos.x + 50.0f)
			slime->rotate = 2;
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
	slime_x = (ball->pos.x - slime->pos.x - slime->size.x * 0.5f - ball->size.x) * 0.01f;
	slime_y = (ball->pos.y - slime->pos.y - slime->size.y * 0.5f + ball->size.y) * 0.01f;

	//-----�{�[�����G�w�̒n�ʂɂ���ꍇ�A�{�[���̏ꏊ�܂ōs��
	if (ball->enemyhaveflag == false && ball->pos.x > SCREEN_WIDTH * 0.5f && ball->enemyhitflag == false)
	{
		slime->pos.x += slime_x;
		slime->pos.y += slime_y;
	}

	//-----�����Ă���{�[���܂ł��ǂ蒅������A�L���b�`����
	if (ball->enemyhitflag == false)
	{
		if (slime->pos.x + slime->size.x > ball->pos.x && slime->pos.x < ball->pos.x + ball->size.x)
		{
			if (slime->pos.y < ball->pos.y + ball->size.y && slime->pos.y + slime->size.y > ball->pos.y)
			{
				M_Catch();
			}
		}
	}

	//-----�{�[���������Ă���Ƃ�
		//-----�v���C���[�̕���������
	if (ball->enemyhaveflag == true)
	{
		if (player->pos.x > slime->pos.x)
			slime->rotate = 3;
		if (player->pos.x < slime->pos.x)
			slime->rotate = 2;
	}

	//-----������܂ł̊ԁA�v���C���[��y���W��ڎw���Ĉړ�����
	if (ball->enemyhaveflag == true && slime_throwtime < 60)
	{
		//-----y���v���C���[�ƃG�l�~�[��y���W�̍��ɕύX
		slime_y = (player->pos.y - slime->pos.y) * 0.01f;

		slime->pos.y += slime_y;
	}

	//-----�{�[����1�b�������瓊����
	if (ball->enemyhaveflag == true)
		slime_throwtime = slime_throwtime + 1.0f;
	if (slime_throwtime > 60)
	{
		E_Throw();
		slime_throwtime = 0.0f;
	}
}