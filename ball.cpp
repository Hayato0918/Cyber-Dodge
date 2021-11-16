//�{�[������ [ball.cpp]
#include "ball.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "player.h"
#include "enemy.h"
#include "invincible.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BALL ball;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBall(void)
{
	ball.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, 360.0f);
	ball.size = D3DXVECTOR2(60.0f, 60.0f);
	ball.move = D3DXVECTOR2(5.0f, -2.5f);
	ball.startmove = D3DXVECTOR2(5.0f, -2.5f);
	ball.throwway = 1;
	ball.gravity = 0.03f;
	ball.texture = LoadTexture("data/TEXTURE/ball.png");
	ball.throwflag = false;
	ball.fallpos = 0.0f;
	ball.playerhavetime = 0.0f;
	ball.playerhaveflag = false;
	ball.playerhitflag = false;
	ball.enemyhaveflag = false;
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
	ENEMY* enemy = GetEnemy();

	//-----�{�[���̍��W�����߂�(Player)
	if (ball.throwflag == false && ball.playerhaveflag == true)		//�{�[�������ł��Ȃ��Ƃ�&&�v���C���[�������Ă�Ƃ�
	{
		if (player->rotate == 2)
		{
			ball.pos = D3DXVECTOR2(player->pos.x - ball.size.x * 0.5, player->pos.y + player->size.y * 0.5 - ball.size.y * 0.5);
			ball.throwway = -1;
		}
		if (player->rotate == 3 || player->rotate == 0 || player->rotate == 1)
		{
			ball.pos = D3DXVECTOR2(player->pos.x + ball.size.x * 0.5, player->pos.y + player->size.y * 0.5 - ball.size.y * 0.5);
			ball.throwway = 1;
		}
	}

	//-----�{�[���̍��W�����߂�(Enemy)
	if (ball.throwflag == false && ball.enemyhaveflag == true)		//�{�[�������ł��Ȃ��Ƃ�&&�G�l�~�[�������Ă�Ƃ�
	{
		if (enemy->rotate == 2)
		{
			ball.pos = D3DXVECTOR2(enemy->pos.x - ball.size.x * 0.5, enemy->pos.y + enemy->size.y * 0.5 - ball.size.y * 0.5);
			ball.throwway = -1;
		}
		if (enemy->rotate == 3 || enemy->rotate == 0 || enemy->rotate == 1)
		{
			ball.pos = D3DXVECTOR2(enemy->pos.x + ball.size.x * 0.5, enemy->pos.y + enemy->size.y * 0.5 - ball.size.y * 0.5);
			ball.throwway = 1;
		}
	}

	//-----�O���v�Z
	if (ball.throwflag == true)
	{
		ball.pos.x += ball.move.x * ball.throwway;
		ball.pos.y += ball.move.y;
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

		//-----����,�Q�[�����ۂ������v�Z
		if (ball.pos.y < 0.0f)							//��
			ball.move.y *= -1;
		if (ball.pos.y + ball.size.y > ball.fallpos)	//��(�������u�Ԃ̃v���C���[��y���W)
		{
			ball.move.y *= -1;
			ball.enemyhitflag = false;
			ball.playerhitflag = false;
		}
		if (ball.pos.x < 0.0f)							//��
		{
			if (ball.move.x < 0)
				ball.move.x += 5.0f;
			if (ball.move.x > 0)
				ball.move.x -= 5.0f;
			ball.enemyhitflag = false;
			ball.playerhitflag = false;
		}
		if (ball.pos.x + ball.size.x > SCREEN_WIDTH)	//�E
		{
			if (ball.move.x > 0)
				ball.move.x -= 5.0f;
			if (ball.move.x < 0)
				ball.move.x += 5.0f;
			ball.move.x *= -1;
			ball.enemyhitflag = false;
			ball.playerhitflag = false;
		}
	}
}

//-----�`�揈��
void DrawBall(void)
{
	DrawSpriteLeftTop(ball.texture, ball.pos.x, ball.pos.y, ball.size.x, ball.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----�G�l�~�[�������鏈��
void E_Throw(void)
{
	ENEMY* enemy = GetEnemy();
	INVINCIBLE* invincible = GetInvincible();
	if (ball.throwflag == false && ball.enemyhaveflag == true)
	{
		ball.fallpos = enemy->pos.y + enemy->size.y;
		ball.enemyhaveflag = false;
		if (invincible->use == true) //-----���G�X�L�����g���Ă邩�H�ǂ����̔���
			ball.playerhitflag = false;
		if (invincible->use == false)
			ball.playerhitflag = true;
		ball.throwflag = true;
	}
}

//�v���C���[�������鏈��
void P_Throw(void)
{
	PLAYER* player = GetPlayer();

	//-----l�L�[�Ńv���C���[��������
	if (GetKeyboardTrigger(DIK_L) && ball.throwflag == false && ball.playerhaveflag == true)
	{
		ball.playerhavetime = 0.0f;
		ball.fallpos = player->pos.y + player->size.y;
		ball.playerhaveflag = false;
		ball.enemyhitflag = true;
		ball.throwflag = true;
	}
}

void AddBallMove(float move, float rotato, float set_pos_y, float set_size_y)
//�n���ꂽ�p�x�ɓn���ꂽ���x�ŉ��Z����B�p�x�̓��W�A���B�����v���B
{
	ball.move.x = cosf(rotato) * move; // �ʂ̌��������X�s�[�h���v�Z
	ball.move.y = sinf(rotato) * -move;
	ball.fallpos = set_pos_y + set_size_y;
}

//-----�\���̃|�C���^�擾����
BALL* GetBall()
{
	return &ball;
}