//�v���C���[���� [player.cpp]
#include "player.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "escape.h"
#include "ball.h"
#include "catch.h"
#include "skill.h"
#include "invade.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�
PLAYER player;

//-----����������
HRESULT InitPlayer(void)
{
	player.pos = D3DXVECTOR2(240.0f, 320.0f);
	player.size = D3DXVECTOR2(90.0f, 180.0f);
	player.move = D3DXVECTOR2(4.0f, 4.0f);
	//player.Wtexture = LoadTexture("data/TEXTURE/player_w.png");
	//player.Stexture = LoadTexture("data/TEXTURE/player_s.png");
	//player.Atexture = LoadTexture("data/TEXTURE/player_a.png");
	//player.Dtexture = LoadTexture("data/TEXTURE/player_d.png");
	player.walk_1texture = LoadTexture("data/TEXTURE/player_walk_1.png");
	player.walk_2texture = LoadTexture("data/TEXTURE/player_walk_2.png");
	player.textureflag = true;
	player.rotate = 3;
	player.drawflag = true;

	InitSkill();

	return S_OK;
}

//-----�I������
void UninitPlayer(void)
{

}

//-----�X�V����
void UpdatePlayer(void)
{
	BALL* ball = GetBall();
	INVADE* invade = GetInvade();

	//-----�ړ�����(�R�[�g�̍��E�[��3s�ňړ�)
	if (GetKeyboardPress(DIK_W))	//��
	{
		player.pos.y -= player.move.y;
		player.rotate = 0;
	}
	if (GetKeyboardPress(DIK_S))	//��
	{
		player.pos.y += player.move.y;
		player.rotate = 1;
	}
	if (GetKeyboardPress(DIK_A))	//��
	{
		player.pos.x -= player.move.x;
		player.textureflag = true;
		player.rotate = 2;
	}
	if (GetKeyboardPress(DIK_D))	//�E
	{
		player.pos.x += player.move.x;
		player.textureflag = false;
		player.rotate = 3;
	}

	//-----�R�[�g�O�ɏo�Ȃ�����
	if (player.pos.y <= 180 - player.size.y * 0.5)			//��
		player.pos.y = 180 - player.size.y * 0.5;
	if (player.pos.y >= SCREEN_HEIGHT - player.size.y - 15 -120)	//��
		player.pos.y = SCREEN_HEIGHT - player.size.y - 15 -120;
	if (player.pos.x <= 0 + 15)								//��
		player.pos.x = 0 + 15;
	if (invade->timeflag == false)
	{
		if (player.pos.x >= SCREEN_WIDTH * 0.5 - player.size.x - 5)		//�E
			player.pos.x = SCREEN_WIDTH * 0.5 - player.size.x - 5;
	}
	if (invade->timeflag == true)
	{
		if (player.pos.x >= SCREEN_WIDTH - player.size.x - 5)		//�E
			player.pos.x = SCREEN_WIDTH - player.size.x - 5;
	}

	//-----�G�l�~�[���������{�[�����A�n��,�ǂɓ����炸�v���C���[�ɓ���������v���C���[�̕`�����߂�(�A�E�g����)
	//if (barrier->drawflag == false)
	//{
	//	if (ball->playerhitflag == true)
	//	{
	//		if (player.pos.x < ball->pos.x + ball->size.x && player.pos.x + player.size.x > ball->pos.x)
	//		{
	//			if (player.pos.y < ball->pos.y + ball->size.y && player.pos.y + player.size.y > ball->pos.y)
	//				player.drawflag = false;
	//		}
	//	}
	//}



	//-----�������
	_Escape();

	//-----�����鏈��
	P_Throw();

	//-----�L���b�`����
	P_Catch();

	//-----�X�L������
	_Skill();
}

//-----�`�揈��
void DrawPlayer(void)
{
	if (player.drawflag == true)
	{
		if(player.textureflag == true)
		DrawSpriteLeftTop(player.walk_1texture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		if(player.textureflag == false)
			DrawSpriteLeftTop(player.walk_2texture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		//if (player.rotate == 0)
		//	DrawSpriteLeftTop(player.Wtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		//if (player.rotate == 1)
		//	DrawSpriteLeftTop(player.Stexture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		//if (player.rotate == 2)
		//	DrawSpriteLeftTop(player.Atexture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		//if (player.rotate == 3)
			//DrawSpriteLeftTop(player.Dtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}

	//-----�X�L���`��
	DrawSkill();
}

//-----�\���̃|�C���^�擾����
PLAYER* GetPlayer(void)
{
	return &player;
}