//�L���b�`���� [catch.cpp]
#include "catch.h"
//�V�X�e��.h
#include "input.h"
#include "texture.h"
#include "sprite.h"
//�G�l�~�[.h
#include "firewall.h"
#include "slime.h"
//�v���C���[
#include "player.h"
//
#include "ball.h"
#include "map_point.h"
//�X�L��.h
#include "autocatch.h"
#include "notCatch.h"

//-----�}�N����`
#define catchtime 30		//�L���b�`������o������
#define catchinterval 60	//�L���b�`�̃C���^�[�o������

//-----�v���g�^�C�v�錾
CATCH Catch;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitCatch(void)
{
	Catch.playerpos = D3DXVECTOR2(0.0f, 0.0f);
	Catch.playersize = D3DXVECTOR2(100.0, 240.0);
	Catch.playerflag = false;
	Catch.playerintervalflag = false;
	Catch.playerintervaltime = 0.0f;
	Catch.playercolflag = false;
	Catch.playercoltime = 0.0f;

	Catch.enemypos = D3DXVECTOR2(0.0f, 0.0f);
	Catch.enemysize = D3DXVECTOR2(60.0, 60.0);
	Catch.enemyflag = 0;
	Catch.enemyintervalflag = 0;
	Catch.enemyintervaltime = 0.0f;
	Catch.enemycolflag = false;
	Catch.enemycoltime = 0.0f;

	Catch.size = D3DXVECTOR2(60.0, 60.0);
	Catch.texture = LoadTexture("data/TEXTURE/catch.png");
	Catch.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);

	return S_OK;
}

//-----�I������
void UninitCatch(void)
{

}

//-----�X�V����
void UpdateCatch(void)
{
	PLAYER* player = GetPlayer();
	FIREWALL* firewall = GetFireWall();
	SLIME* slime = GetSlime();
	BALL* ball = GetBall();
	MAP_PLAYER* map_player = GetMapPlayer();

	//-----�v���C���[�̌����ɉ����ăL���b�`�̕��������߂�
	if (Catch.playerflag == true)
	{
		if (player->rotate == 2)	//��
			Catch.playerpos = D3DXVECTOR2(player->pos.x, player->pos.y + player->size.y * 0.4f + 20.f);
		if (player->rotate == 3)		//�E
			Catch.playerpos = D3DXVECTOR2(player->pos.x + player->size.x, player->pos.y + player->size.y * 0.4f + 20.f);
	}

	//-----�G�l�~�[�̌����ɉ����ăL���b�`�̕��������߂�
	if (Catch.enemyflag == 1)
	{
		if (map_player->encount == 1)
		{
			if (slime->rotate == 2)	//��
				Catch.enemypos = D3DXVECTOR2(slime->pos.x, slime->pos.y + slime->size.y * 0.5f);
			if (slime->rotate == 3)		//�E
				Catch.enemypos = D3DXVECTOR2(slime->pos.x + slime->size.x, slime->pos.y + slime->size.y * 0.5f);
		}
		if (map_player->encount == 2)
		{
			if (firewall->rotate == 0)		//��
				Catch.enemypos = D3DXVECTOR2(firewall->pos.x + firewall->size.x * 0.5f, firewall->pos.y - ball->size.y * 0.5f);
			if (firewall->rotate == 1)		//��
				Catch.enemypos = D3DXVECTOR2(firewall->pos.x + firewall->size.x * 0.5f, firewall->pos.y + firewall->size.y + ball->size.y * 0.5f);
			if (firewall->rotate == 2)	//��
				Catch.enemypos = D3DXVECTOR2(firewall->pos.x, firewall->pos.y + firewall->size.y * 0.5f);
			if (firewall->rotate == 3)		//�E
				Catch.enemypos = D3DXVECTOR2(firewall->pos.x + firewall->size.x, firewall->pos.y + firewall->size.y * 0.5f);
		}
	}
}

//-----�`�揈��
void DrawCatch(void)
{
	if(Catch.playerflag == true)
		DrawSpriteColor(Catch.texture, Catch.playerpos.x, Catch.playerpos.y, Catch.playersize.x, Catch.playersize.y, 0.0f, 0.0f, 1.0f, 1.0f, Catch.color);
	if(Catch.enemyflag == 1)
		DrawSpriteColor(Catch.texture, Catch.enemypos.x, Catch.enemypos.y, Catch.enemysize.x, Catch.enemysize.y, 0.0f, 0.0f, 1.0f, 1.0f, Catch.color);
}

//-----�v���C���[�̃L���b�`����
void P_Catch(void)
{
	BALL* ball = GetBall();
	AUTO* auto_c = GetAuto();
	NOTCATCH* notcatch = GetNotCatch();

	if (notcatch->use && ball->fallflag == false)
	{
		return;
	}

	if (PADUSE == 0)
	{
		//-----�v���C���[�̃L���b�`����
		if (IsButtonTriggered(0, BUTTON_R) && Catch.playerintervalflag == false && ball->playerhaveflag == false)
		{
			Catch.playerflag = true;
			Catch.playerintervalflag = true;
		}
	}
	if (PADUSE == 1)
	{
		//-----�v���C���[�̃L���b�`����
		if (GetKeyboardTrigger(DIK_J) && Catch.playerintervalflag == false && ball->playerhaveflag == false)
		{
			Catch.playerflag = true;
			Catch.playerintervalflag = true;
		}
	}
	//-----�C���^�[�o��(1s)
	if (Catch.playerintervalflag == true)
		Catch.playerintervaltime = Catch.playerintervaltime + 1.0f;
	if (Catch.playerintervaltime > catchinterval)
	{
		Catch.playerintervalflag = false;
		Catch.playerintervaltime = 0.0f;
	}
	//-----�L���b�`�̔��莞��(0.5s)
	if (Catch.playerflag == true)
		Catch.playercoltime = Catch.playercoltime + 1.0f;
	if (Catch.playercoltime > catchtime)
	{
		Catch.playerflag = false;
		Catch.playercoltime = 0.0f;
	}
	//-----�L���b�`���[�V�������Ƀ{�[�����L���b�`������ɓ�������
	if (Catch.playerflag == true)
	{
		//�X�L���F�I�[�g�L���b�`���@�\���Ă��Ȃ��ꍇ
		if (auto_c->use == false)
		{
			if (Catch.playerpos.x + Catch.playersize.x > ball->pos.x && Catch.playerpos.x < ball->pos.x + ball->size.x)
			{
				if (Catch.playerpos.y + Catch.playersize.y > ball->pos.y && Catch.playerpos.y - 100.f < ball->pos.y + ball->size.y)
				{
					ball->playerhitflag = false;
					ball->playerthrowflag = false;
					ball->throwflag = false;
					ball->playerhaveflag = true;
					ball->move = D3DXVECTOR2(ball->startmove.x, ball->startmove.y);
				}
			}
		}

		//�X�L���F�I�[�g�L���b�`���@�\���Ă���ꍇ
		if (auto_c->use == true)
		{
			if (Catch.playerpos.x + Catch.playersize.x > ball->pos.x && Catch.playerpos.x < ball->pos.x + ball->size.x)
			{
				//�X�L���F�I�[�g�L���b�`�ő����������蔻������Z�A���W���ړ�
				if (Catch.playerpos.y + (Catch.playersize.y * 4) > ball->pos.y && (Catch.playerpos.y - Catch.playersize.y) < ball->pos.y + ball->size.y)
				{
					ball->playerhitflag = false;
					ball->playerthrowflag = false;
					ball->throwflag = false;
					ball->playerhaveflag = true;
					ball->move = D3DXVECTOR2(ball->startmove.x, ball->startmove.y);
				}
			}
		}
	}
}

//-----�G�l�~�[�̃L���b�`����
void M_Catch(void)
{
	BALL* ball = GetBall();
	NOTCATCH* notcatch = GetNotCatch();

	if (notcatch->use && ball->fallflag == false)
	{
		return;
	}


	//-----�L���b�`
	if (Catch.enemyintervalflag == 0 && ball->enemyhaveflag == 0)
	{
		Catch.enemyflag = 1;
		Catch.enemyintervalflag = 1;
	}
	//-----�C���^�[�o��(1s)
	if (Catch.enemyintervalflag == 1)
		Catch.enemyintervaltime = Catch.enemyintervaltime + 1.0f;
	if (Catch.enemyintervaltime > catchinterval)
	{
		Catch.enemyintervalflag = 0;
		Catch.enemyintervaltime = 0.0f;
	}
	//-----�L���b�`�̔��莞��(0.5s)
	if (Catch.enemyflag == 1)
		Catch.enemycoltime = Catch.enemycoltime + 1.0f;
	if (Catch.enemycoltime > catchtime)
	{
		Catch.enemyflag = 0;
		Catch.enemycoltime = 0.0f;
	}
	//-----�L���b�`���[�V�������Ƀ{�[�����L���b�`������ɓ�������
	if (Catch.enemyflag == 1)
	{
		if (Catch.enemypos.x + Catch.enemysize.x > ball->pos.x && Catch.enemypos.x < ball->pos.x + ball->size.x)
		{
			if (Catch.enemypos.y + Catch.enemysize.y > ball->pos.y && Catch.enemypos.y < ball->pos.y + ball->size.y)
			{
				Catch.enemyintervaltime = 0.0f;
				ball->throwflag = false;
				ball->enemyhaveflag = true;
				ball->move = D3DXVECTOR2(ball->startmove.x, ball->startmove.y);
			}
		}
	}
}

CATCH* GetCatch()
{
	return &Catch;
}