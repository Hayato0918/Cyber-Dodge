//�X�L��_�r�����[�h���� [billiards.cpp]
#include "billiards.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "ball.h"

//-----�}�N����`
#define swingtime	180						//�L���[�X�e�B�b�N�̔��莞��
#define PI 3.1415926535897932				//�~����

//-----�O���[�o���ϐ�
BILLIARDS billiards;

HRESULT InitBilliards(void)
{
	billiards.pos = D3DXVECTOR2(0.0f, 0.0f);
	billiards.size = D3DXVECTOR2(120.0f, 5.0f);
	billiards.use = false;
	billiards.timeflag = false;
	billiards.time = 0.0f;

	billiards.texture = LoadTexture("data/TEXTURE/cuestick.png");

	return S_OK;
}

void _Billiards(void)
{
	//6�L�[�������ꂽ�珈�����J�n�B
		//�ʂ������Ă��Ȃ��ԃL���[�X�e�B�b�N����莞�ԕ\���A���̊ԋʂ����̑��x�őł��o���悤�ȏ������s���܂��B

	BALL* ball = GetBall();

	//�X�L�����g���邩�̔��f
	if (GetKeyboardTrigger(DIK_6) && billiards.use == false && ball->playerhaveflag == false)
	{
		billiards.timeflag = true;
		billiards.use = true;
	}

	PLAYER* player = GetPlayer();

	//�L���[�X�e�B�b�N��U���Ă���Œ��̏���
	if (billiards.timeflag == true)
	{
		if (player->rotate == 3) // �E����
		{
			billiards.pos = D3DXVECTOR2(player->pos.x, player->pos.y + player->size.y * 0.5);// �L���[�X�e�B�b�N�̕`��ʒu
		}
		if (player->rotate == 2) // ������
		{
			billiards.pos = D3DXVECTOR2(player->pos.x - billiards.size.x * 0.5, player->pos.y + player->size.y * 0.5);// �L���[�X�e�B�b�N�̕`��ʒu
		}

		//�����蔻�菈��
		if (billiards.pos.x + billiards.size.x > ball->pos.x && billiards.pos.x < ball->pos.x + ball->size.x)
		{
			if (billiards.pos.y + billiards.size.y > ball->pos.y && billiards.pos.y < ball->pos.y + ball->size.y)
			{
				if (player->rotate == 3) // �E����
				{
					AddBallMove(-5.0f, PI * 0.05, player->pos.y, player->size.y);
				}
				if (player->rotate == 2) // ������
				{
					AddBallMove(-5.0f, PI * 0.95, player->pos.y, player->size.y);
				}
			}
		}

		billiards.time = billiards.time + 1.0f;
	}

	//�L���[�X�e�B�b�N��U��؂������̔��f
	if (billiards.time > swingtime)
	{
		billiards.timeflag = false;
		billiards.time = 0.0f;
	}
}

void DrawBilliards(void)
{
	if (billiards.timeflag == true)
		DrawSpriteLeftTop(billiards.texture, billiards.pos.x, billiards.pos.y, billiards.size.x, billiards.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}