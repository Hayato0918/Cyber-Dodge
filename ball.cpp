//�{�[������ [ball.cpp]
#include "ball.h"
//�V�X�e��.h
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
//�v���C���[.h
#include "player.h"
//�G�l�~�[.h
#include "firewall.h"
#include "slime.h"
//�X�L��.h
#include "autocatch.h"
#include "invincible.h"
#include "create.h"
//
#include "map_point.h"

//-----�}�N����`
#define auto_ctime_2 60		//1s��

//-----�v���g�^�C�v�錾
BALL ball;

//-----�O���[�o���ϐ�
PLAYER* player = GetPlayer();

//-----����������
HRESULT InitBall(void)
{
	ball.pos = D3DXVECTOR2(500.0f, 360.0f);
	ball.size = D3DXVECTOR2(60.0f, 60.0f);
	ball.move = D3DXVECTOR2(12.0f, -3.5f);
	ball.startmove = D3DXVECTOR2(ball.move.x, ball.move.y);
	ball.throwway = 1;
	ball.gravity = 0.05f;
	ball.texture = LoadTexture("data/TEXTURE/ball.png");
	ball.throwflag = false;
	ball.fallpos = 0.0f;
	ball.playerhavetime = 0.0f;
	ball.playerhaveflag = false;
	ball.playerhitflag = false;
	ball.playerthrowflag = false;
	ball.enemyhaveflag = false;
	ball.enemyhitflag = false;
	ball.fallflag = true;
	ball.rad = 0.0f;
	ball.plyer_oldposY = 0.0f;

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
	MAP_PLAYER* map_player = GetMapPlayer();
	FIREWALL* firewall = GetFireWall();
	SLIME* slime = GetSlime();

	//-----�{�[���̍��W�����߂�(Player)
	if (ball.throwflag == false && ball.playerhaveflag == true)		//�{�[�������ł��Ȃ��Ƃ�&&�v���C���[�������Ă�Ƃ�
	{
		if (player->rotate == 2)
		{
			ball.pos = D3DXVECTOR2(player->pos.x, player->pos.y + player->size.y * 0.3f - ball.size.y * 0.5f);
			ball.throwway = -1;
		}
		if (player->rotate == 3 || player->rotate == 0 || player->rotate == 1)
		{
			ball.pos = D3DXVECTOR2(player->pos.x + ball.size.x * 2.f, player->pos.y + player->size.y * 0.3f - ball.size.y * 0.5f);
			ball.throwway = 1;
		}
	}

	//-----�{�[���̍��W�����߂�(slime)
	if (map_player->encount == 1)
	{
		if (ball.throwflag == false && ball.enemyhaveflag == true)		//�{�[�������ł��Ȃ��Ƃ�&&�G�l�~�[�������Ă�Ƃ�
		{
			if (slime->rotate == 2)
			{
				ball.pos = D3DXVECTOR2(slime->pos.x - ball.size.x * 0.5f, slime->pos.y + slime->size.y * 0.5f - ball.size.y * 0.5f);
				ball.throwway = -1;
			}
			if (slime->rotate == 3)
			{
				ball.pos = D3DXVECTOR2(slime->pos.x + ball.size.x * 0.5f, slime->pos.y + slime->size.y * 0.5f - ball.size.y * 0.5f);
				ball.throwway = 1;
			}
		}
	}
	//-----�{�[���̍��W�����߂�(FireWall)
	if (map_player->encount == 2)
	{
		if (ball.throwflag == false && ball.enemyhaveflag == true)		//�{�[�������ł��Ȃ��Ƃ�&&�G�l�~�[�������Ă�Ƃ�
		{
			if (firewall->rotate == 2)
			{
				ball.pos = D3DXVECTOR2(firewall->pos.x - ball.size.x * 0.5f, firewall->pos.y + firewall->size.y * 0.5f - ball.size.y * 0.5f);
				ball.throwway = -1;
			}
			if (firewall->rotate == 3 || firewall->rotate == 0 || firewall->rotate == 1)
			{
				ball.pos = D3DXVECTOR2(firewall->pos.x + ball.size.x * 0.5f, firewall->pos.y + firewall->size.y * 0.5f - ball.size.y * 0.5f);
				ball.throwway = 1;
			}
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
			ball.fallflag = true;
		}
		if (ball.pos.x < 0.0f)							//��
		{
			if (ball.move.x < 0)
				ball.move.x += 5.0f;
			if (ball.move.x > 0)
				ball.move.x -= 5.0f;
			ball.enemyhitflag = false;
			ball.playerhitflag = false;
			ball.fallflag = true;
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
			ball.fallflag = true;
		}
	}

	//��΂Ƃ̓����蔻��
	CREATE* create = GetCreate(0);

	if (create->timeflag)
	{
		for (int i = 0; i < 3; i++) // ������3�͐���������΂̌���\���Bcreate�Ő���ύX�����ۂ͂������ύX���ĉ������B
		{
			CREATE* create = GetCreate(i);

			if (ball.pos.x + ball.size.x > create->pos.x - create->size.x / 2 && ball.pos.x < create->pos.x + create->size.x / 2 &&
				ball.pos.y + ball.size.y > create->pos.y - create->size.y / 2 && ball.pos.y < create->pos.y + create->size.y / 2)
			{
				float ax = 0.0f;
				float ay = 0.0f;
				if (ball.pos.x + ball.size.x < create->pos.x)
					//��΂̍���
				{
					ax = (create->pos.x - ball.pos.x + ball.size.x) / create->size.x / 2;
				}
				else if (ball.pos.x > create->pos.x)
					//��΂̉E��
				{
					ax = (ball.pos.x - create->pos.x) / create->size.x / 2;
				}

				if (ball.pos.y + ball.size.y < create->pos.y)
					//��΂̏㑤
				{
					ay = (create->pos.y - ball.pos.y + ball.size.y) / create->size.y / 2;
				}
				else if (ball.pos.y > create->pos.y)
					//��΂̉���
				{
					ay = (ball.pos.y - create->pos.y) / create->size.y / 2;
				}

				if (ax > ay)
				{
					ball.move.x *= -1;
				}
				else if (ax < ay)
				{
					ball.move.y *= -1;
				}
				else
				{
					ball.move.x *= -1;
				}
			}
		}
	}
}

//-----�`�揈��
void DrawBall(void)
{
	if(ball.playerhaveflag == false)
	DrawSpriteLeftTop(ball.texture, ball.pos.x, ball.pos.y, ball.size.x, ball.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//-----�G�l�~�[�������鏈��
void E_Throw(void)
{
	INVINCIBLE* invincible = GetInvincible();

	if (ball.throwflag == false && ball.enemyhaveflag == true)
	{
		ball.fallpos = player->pos.y + player->size.y;
		ball.fallflag = false;
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
	AUTO* auto_c = GetAuto();

	if (PADUSE == 0)
	{
		//-----�v���C���[�̓�������
		if (IsButtonTriggered(0, BUTTON_R2) && ball.throwflag == false && ball.playerhaveflag == true)
		{
			ball.playerhavetime = 0.0f;
			ball.fallpos = player->pos.y + player->size.y;
			ball.fallflag = false;
			ball.playerhaveflag = false;
			ball.playerthrowflag = true;
			ball.enemyhitflag = true;
			ball.throwflag = true;

			//�v���C���[���X�L���F�I�[�g�L���b�`�g�p���ɓ������ꍇ�̋z���񂹖h�~
			if (auto_c->timeflag_2 == true)
				auto_c->auto_catch = false;
			auto_c->time_2 = auto_c->time_2 + 1.0f;
			if (auto_c->time_2 > auto_ctime_2)
			{
				auto_c->auto_catch = true;
				auto_c->timeflag_2 = false;
				auto_c->time_2 = 0.0f;
			}
		}
	}

	if (PADUSE == 1)
	{
		//-----�v���C���[�̓�������
		if (GetKeyboardTrigger(DIK_L) && ball.throwflag == false && ball.playerhaveflag == true)
		{
			ball.playerhavetime = 0.0f;
			ball.fallpos = player->pos.y + player->size.y;
			ball.fallflag = false;
			ball.playerhaveflag = false;
			ball.playerthrowflag = true;
			ball.enemyhitflag = true;
			ball.throwflag = true;
		}


		//�v���C���[���X�L���F�I�[�g�L���b�`�g�p���ɓ������ꍇ�̋z���񂹖h�~
		if (auto_c->timeflag_2 == true)
			auto_c->auto_catch = false;
		auto_c->time_2 = auto_c->time_2 + 1.0f;
		if (auto_c->time_2 > auto_ctime_2)
		{
			auto_c->auto_catch = true;
			auto_c->timeflag_2 = false;
			auto_c->time_2 = 0.0f;
		}
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