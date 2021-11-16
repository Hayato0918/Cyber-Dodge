//�G�l�~�[���� [enemy.cpp]
#include "enemy.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "ball.h"
#include "catch.h"
#include "enemyAI.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�
ENEMY enemy;

//-----����������
HRESULT InitEnemy(void)
{
	enemy.pos = D3DXVECTOR2(800.0f, 320.0f);
	enemy.size = D3DXVECTOR2(60.0f, 120.0f);
	enemy.move = D3DXVECTOR2(2.0f, 2.0f);
	enemy.Wtexture = LoadTexture("data/TEXTURE/player_w.png");
	enemy.Stexture = LoadTexture("data/TEXTURE/player_s.png");
	enemy.Atexture = LoadTexture("data/TEXTURE/player_a.png");
	enemy.Dtexture = LoadTexture("data/TEXTURE/player_d.png");
	enemy.rotate = 2;

	enemy.drawflag = true;

	return S_OK;
}

//-----�I������
void UninitEnemy(void)
{

}

//-----�X�V����
void UpdateEnemy(void)
{
	BALL* ball = GetBall();

	//-----�ړ�����(�R�[�g�̍��E�[��3s�ňړ�)
	if (GetKeyboardPress(DIK_UPARROW))	//��
	{
		enemy.pos.y -= enemy.move.y;
		enemy.rotate = 0;
	}
	if (GetKeyboardPress(DIK_DOWNARROW))	//��
	{
		enemy.pos.y += enemy.move.y;
		enemy.rotate = 1;
	}
	if (GetKeyboardPress(DIK_LEFTARROW))	//��
	{
		enemy.pos.x -= enemy.move.x;
		enemy.rotate = 2;
	}
	if (GetKeyboardPress(DIK_RIGHTARROW))	//�E
	{
		enemy.pos.x += enemy.move.x;
		enemy.rotate = 3;
	}

	//-----�R�[�g�O�ɏo�Ȃ�����
	if (enemy.pos.y <= 180 - enemy.size.y * 0.5)			//��
		enemy.pos.y = 180 - enemy.size.y * 0.5;
	if (enemy.pos.y >= SCREEN_HEIGHT - enemy.size.y - 15)	//��
		enemy.pos.y = SCREEN_HEIGHT - enemy.size.y - 15;
	if (enemy.pos.x <= SCREEN_WIDTH * 0.5)								//��
		enemy.pos.x = SCREEN_WIDTH * 0.5;
	if (enemy.pos.x >= SCREEN_WIDTH - enemy.size.x - 5)								//�E
		enemy.pos.x = SCREEN_WIDTH - enemy.size.x - 5;


	//-----�v���C���[���������{�[�����A�n��,�ǂɓ����炸�G�ɓ���������G�̕`�����߂�(�A�E�g����)
	//if (ball->enemyhitflag == true)
	//{
	//	if (enemy.pos.x < ball->pos.x + ball->size.x && enemy.pos.x + enemy.size.x > ball->pos.x)
	//	{
	//		if (enemy.pos.y < ball->pos.y + ball->size.y && enemy.pos.y + enemy.size.y > ball->pos.y)
	//			enemy.drawflag = false;	
	//	}
	//}

	enemyAI();
}

//-----�`�揈��
void DrawEnemy(void)
{
	if (enemy.drawflag == true)
	{
		if (enemy.rotate == 0)
			DrawSpriteLeftTop(enemy.Wtexture, enemy.pos.x, enemy.pos.y, enemy.size.x, enemy.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		if (enemy.rotate == 1)
			DrawSpriteLeftTop(enemy.Stexture, enemy.pos.x, enemy.pos.y, enemy.size.x, enemy.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		if (enemy.rotate == 2)
			DrawSpriteLeftTop(enemy.Atexture, enemy.pos.x, enemy.pos.y, enemy.size.x, enemy.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		if (enemy.rotate == 3)
			DrawSpriteLeftTop(enemy.Dtexture, enemy.pos.x, enemy.pos.y, enemy.size.x, enemy.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
	}
}

//-----�\���̃|�C���^�擾����
ENEMY* GetEnemy(void)
{
	return &enemy;
}