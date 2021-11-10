//�{�[������ [ball.cpp]
#include "ball.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "player.h"
#include "enemy.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BALL ball;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBall(void)
{
	ball.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, 360.0f);
	ball.size = D3DXVECTOR2(60.0f, 60.0f);
	ball.move = D3DXVECTOR2(15.0f, -3.5f);
	ball.gravity = 0.03f;
	ball.texture = LoadTexture("data/TEXTURE/ball.png");
	ball.throwflag = false;
	ball.fallpos = 0.0f;
	ball.playerhaveflag = false;
	ball.enemyhaveflahg = false;
	ball.playerhitflag = false;
	ball.enemyhitflag = false;

	return S_OK;
}

//-----�I������
void UninitBall(void)
{

}

//-----�X�V����
void UpdateBall(void)
{
	PLAYER* player = GetPlayer();

	if (ball.throwflag == false && ball.playerhaveflag == true)		//�{�[�������ł��Ȃ��Ƃ�&&�v���C���[�������Ă�Ƃ�
	{
		if (player->rotate == 2)
		{
			ball.pos = D3DXVECTOR2(player->pos.x - ball.size.x * 0.5, player->pos.y + player->size.y * 0.5 - ball.size.y * 0.5);
			ball.move.x = -15.0f;
		}
		if (player->rotate == 3 || player->rotate == 0 || player->rotate == 1)
		{
			ball.pos = D3DXVECTOR2(player->pos.x + ball.size.x * 0.5, player->pos.y + player->size.y * 0.5 - ball.size.y * 0.5);
			ball.move.x = 15.0f;
		}
	}
}

//-----�`�揈��
void DrawBall(void)
{
	DrawSpriteLeftTop(ball.texture, ball.pos.x, ball.pos.y, ball.size.x, ball.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//�v���C���[�������鏈��
void P_Throw(void)
{
	PLAYER* player = GetPlayer();

	//-----j�L�[�œ�����
	if (GetKeyboardTrigger(DIK_L) && ball.throwflag == false && ball.playerhaveflag == true)
	{
		ball.fallpos = player->pos.y + player->size.y;
		ball.playerhaveflag = false;
		ball.enemyhitflag = true;
		ball.throwflag = true;
	}

	//-----�O���v�Z
	if (ball.throwflag == true)
	{
		ball.pos += ball.move;
		ball.move.y += ball.gravity;

		//-----�����v�Z
		if (ball.move.y < 0)	//��Ɍ�����
		{
			ball.move.y += 0.02f;
			if (ball.move.y >= 0)
				ball.move.y = 0;
		}
		if (ball.move.y > 0)	//���Ɍ�����
		{
			ball.move.y -= 0.02f;
			if (ball.move.y <= 0)
				ball.move.y = 0;
		}
		if (ball.move.x < 0)	//���Ɍ�����
		{
			ball.move.x += 0.02f;
			if (ball.move.x >= 0)
				ball.move.x = 0;
		}
		if (ball.move.x > 0)	//�E�Ɍ�����
		{
			ball.move.x -= 0.02f;
			if (ball.move.x <= 0)
				ball.move.x = 0;
		}

		//-----����,�����v�Z
		if (ball.pos.y < 0.0f)							//��
			ball.move.y *= -1;
		if (ball.pos.y + ball.size.y > ball.fallpos)	//��(�������u�Ԃ̃v���C���[��y���W)
		{
			ball.move.y *= -1;
			ball.enemyhitflag = false;
		}
		if (ball.pos.x < 0.0f)							//��
		{
			if (ball.move.x < 0)
				ball.move.x += 5.0f;
			if (ball.move.x > 0)
				ball.move.x -= 5.0f;
			ball.move.x *= -1;
			ball.enemyhitflag = false;
		}
		if (ball.pos.x + ball.size.x > SCREEN_WIDTH)	//�E
		{
			if (ball.move.x > 0)
				ball.move.x -= 5.0f;
			if (ball.move.x < 0)
				ball.move.x += 5.0f;
			ball.move.x *= -1;
			ball.enemyhitflag = false;
		}
	}
}

//�G�l�~�[�������鏈��
void M_Throw(void)
{
	ENEMY* enemy = GetEnemy();

	//-----j�L�[�œ�����
	if (GetKeyboardTrigger(DIK_M) && ball.throwflag == false)
	{
		ball.fallpos = enemy->pos.y + enemy->size.y;
		ball.throwflag = true;
		ball.playerhitflag = true;
	}

	//-----�O���v�Z
	if (ball.throwflag == true)
	{
		ball.pos += ball.move;
		ball.move.y += ball.gravity;

		//-----�����v�Z
		if (ball.move.y < 0)	//��Ɍ�����
		{
			ball.move.y += 0.02f;
			if (ball.move.y >= 0)
				ball.move.y = 0;
		}
		if (ball.move.y > 0)	//���Ɍ�����
		{
			ball.move.y -= 0.02f;
			if (ball.move.y <= 0)
				ball.move.y = 0;
		}
		if (ball.move.x < 0)	//���Ɍ�����
		{
			ball.move.x += 0.02f;
			if (ball.move.x >= 0)
				ball.move.x = 0;
		}
		if (ball.move.x > 0)	//�E�Ɍ�����
		{
			ball.move.x -= 0.02f;
			if (ball.move.x <= 0)
				ball.move.x = 0;
		}

		//-----����,�����v�Z
		if (ball.pos.y < 0.0f)							//��
			ball.move.y *= -1;
		if (ball.pos.y + ball.size.y > ball.fallpos)	//��(�������u�Ԃ̃v���C���[��y���W)
		{
			ball.move.y *= -1;
			ball.playerhitflag = false;
		}
		if (ball.pos.x < 0.0f)							//��
		{
			if (ball.move.x < 0)
				ball.move.x += 5.0f;
			if (ball.move.x > 0)
				ball.move.x -= 5.0f;
			ball.move.x *= -1;
			ball.playerhitflag = false;
		}
		if (ball.pos.x + ball.size.x > SCREEN_WIDTH)	//�E
		{
			if (ball.move.x > 0)
				ball.move.x -= 5.0f;
			if (ball.move.x < 0)
				ball.move.x += 5.0f;
			ball.move.x *= -1;
			ball.playerhitflag = false;
		}
	}
}

BALL* GetBall()
{
	return &ball;
}