//�GAI���� [enemyAI.cpp]
#include "firewallAI.h"
//�V�X�e��.h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "firewall.h"
#include "catch.h"
#include "ball.h"
#include "player.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�
float throwtime;
float x, y;
int num;

//-----�G�s���p�^�[��
void FireWallAI()
{
	FIREWALL* firewall = GetFireWall();
	BALL* ball = GetBall();
	CATCH* Catch = GetCatch();
	PLAYER* player = GetPlayer();


	//-----�{�[���������Ă��Ȃ��Ƃ�
		//-----�{�[���̕�������
	if (ball->enemyhaveflag == false)
	{
		if (ball->pos.x > firewall->pos.x + 50.0f)
			firewall->rotate = 3;
		if (ball->pos.x < firewall->pos.x + 50.0f)
			firewall->rotate = 2;
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
	x = (ball->pos.x - firewall->pos.x - firewall->size.x * 0.5f - ball->size.x) * 0.01f;
	y = (ball->pos.y - firewall->pos.y - firewall->size.y * 0.5f + ball->size.y) * 0.01f;

		//-----�{�[�����G�w�̒n�ʂɂ���ꍇ�A�{�[���̏ꏊ�܂ōs��
	if (ball->enemyhaveflag == false && ball->pos.x > SCREEN_WIDTH * 0.5f && ball->enemyhitflag == false)
	{
		firewall->pos.x += x;
		firewall->pos.y += y;
	}

		//-----�����Ă���{�[���܂ł��ǂ蒅������A�L���b�`����
	if (ball->enemyhitflag == false)
	{
		if (firewall->pos.x + firewall->size.x > ball->pos.x && firewall->pos.x < ball->pos.x + ball->size.x)
		{
			if (firewall->pos.y < ball->pos.y + ball->size.y && firewall->pos.y + firewall->size.y > ball->pos.y)
			{
				M_Catch();
			}
		}
	}

	//-----�{�[���������Ă���Ƃ�
		//-----�v���C���[�̕���������
	if (ball->enemyhaveflag == true)
	{
		if (player->pos.x > firewall->pos.x)
			firewall->rotate = 3;
		if (player->pos.x < firewall->pos.x)
			firewall->rotate = 2;
	}

		//-----������܂ł̊ԁA�v���C���[��y���W��ڎw���Ĉړ�����
	if (ball->enemyhaveflag == true && throwtime < 60)
	{
		//-----y���v���C���[�ƃG�l�~�[��y���W�̍��ɕύX
		y = (player->pos.y - firewall->pos.y) * 0.01f;

		firewall->pos.y += y;
	}

		//-----�{�[����1�b�������瓊����
	if (ball->enemyhaveflag == true)
		throwtime = throwtime + 1.0f;
	if (throwtime > 60)
	{
		E_Throw();
		throwtime = 0.0f;
	}
}