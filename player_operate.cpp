//�v���C���[���쏈��[player_operate.cpp]
#include "player_operate.h"
//�V�X�e��.h
#include "input.h"
//
#include "player.h"
#include "reverse.h"
#include "ball.h"
#include "catch.h"

void player_operate()
{
	PLAYER* player = GetPlayer();
	REVERSE* reverse = GetReverse();

	//---------------�ړ�---------------
	//pad�̂Ƃ�
	if (PADUSE == 0)
	{
		if (IsButtonPressed(0, BUTTON_UP))
		{
			if (reverse->use == false)
				player->pos.y -= player->move.y;
			if (reverse->use == true)
				player->pos.y += player->move.y;
		}
		if (IsButtonPressed(0, BUTTON_DOWN))
		{
			if (reverse->use == false)
				player->pos.y += player->move.y;
			if (reverse->use == true)
				player->pos.y -= player->move.y;
		}
		if (IsButtonPressed(0, BUTTON_LEFT))
		{
			if (reverse->use == false)
				player->pos.x -= player->move.x;
			if (reverse->use == true)
				player->pos.x += player->move.x;

			player->rotate = 2;		//�������ɍX�V

			player->walktextureflag = true;		//�e�N�X�`���̐؂�ւ�
		}
		if (IsButtonPressed(0, BUTTON_RIGHT))
		{
			if (reverse->use == false)
				player->pos.x += player->move.x;
			if (reverse->use == true)
				player->pos.x -= player->move.x;

			player->rotate = 3;		//�E�����ɍX�V

			player->walktextureflag = true;		//�e�N�X�`���̐؂�ւ�
		}

		//if (IsButtonTriggered(0, BUTTON_RELEASE))	//���ړ�����߂���
		//	player.walktextureflag = false;
		//if (IsButtonTriggered(0, BUTTON_RELEASE))	//�E�ړ�����߂���
		//	player.walktextureflag = false;
	}

	//-----�ړ�����(�R�[�g�̍��E�[��3s�ňړ�)
	if (PADUSE == 1)
	{
		if (GetKeyboardPress(DIK_W))	//��
		{
			if (reverse->use == false)
				player->pos.y -= player->move.y;
			if (reverse->use == true)
				player->pos.y += player->move.y;
		}
		if (GetKeyboardPress(DIK_S))	//��
		{
			if (reverse->use == false)
				player->pos.y += player->move.y;
			if (reverse->use == true)
				player->pos.y -= player->move.y;
		}
		if (GetKeyboardPress(DIK_A))	//��
		{
			if (reverse->use == false)
				player->pos.x -= player->move.x;
			if (reverse->use == true)
				player->pos.x += player->move.x;

			player->rotate = 2;		//�������ɍX�V

			player->walktextureflag = true;		//�e�N�X�`���̐؂�ւ�
		}
		if (GetKeyboardPress(DIK_D))	//�E
		{
			if (reverse->use == false)
				player->pos.x += player->move.x;
			if (reverse->use == true)
				player->pos.x -= player->move.x;

			player->rotate = 3;		//�E�����ɍX�V

			player->walktextureflag = true;		//�e�N�X�`���̐؂�ւ�
		}

		/*if (GetKeyboardRelease(DIK_A))	//���ړ�����߂���
			player->walktextureflag = false;
		if (GetKeyboardRelease(DIK_D))	//�E�ړ�����߂���
			player->walktextureflag = false;*/
	}


	//---------------����---------------
	P_Throw();


	//---------------�L���b�`---------------
	P_Catch();


	//---------------�X�L��---------------
}