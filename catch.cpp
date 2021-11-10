//�L���b�`���� [catch.cpp]
#include "catch.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "ball.h"

//-----�}�N����`
#define catchtime 30		//�L���b�`������o������
#define catchinterval 60	//�L���b�`�̃C���^�[�o������

//-----�v���g�^�C�v�錾
CATCH Catch;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitCatch(void)
{
	Catch.pos = D3DXVECTOR2(0.0f, 0.0f);
	Catch.size = D3DXVECTOR2(60.0, 60.0);
	Catch.texture = LoadTexture("data/TEXTURE/catch.png");
	Catch.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
	Catch.flag = false;
	Catch.intervalflag = false;
	Catch.intervaltime = 0.0f;
	Catch.coltime = 0.0f;
	Catch.colflag = false;

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
	BALL* ball = GetBall();

	//-----�v���C���[�̌����ɉ����ăL���b�`�̕��������߂�
	if(player->rotate == 0)		//��
		Catch.pos = D3DXVECTOR2(player->pos.x + player->size.x * 0.5, player->pos.y - ball->size.y * 0.5);
	if (player->rotate == 1)		//��
		Catch.pos = D3DXVECTOR2(player->pos.x + player->size.x * 0.5, player->pos.y + player->size.y + ball->size.y * 0.5);
	if (player->rotate == 2)	//��
		Catch.pos = D3DXVECTOR2(player->pos.x - Catch.size.x * 0.5, player->pos.y + player->size.y * 0.5);
	if(player->rotate == 3)		//�E
		Catch.pos = D3DXVECTOR2(player->pos.x + player->size.x * 1.5, player->pos.y + player->size.y * 0.5);
}

//-----�`�揈��
void DrawCatch(void)
{
	if(Catch.flag == true)
	DrawSpriteColor(Catch.texture, Catch.pos.x, Catch.pos.y, Catch.size.x, Catch.size.y, 0.0f, 0.0f, 1.0f, 1.0f, Catch.color);
}

//---�L���b�`����
void _Catch(void)
{
	BALL* ball = GetBall();

	//-----J�L�[�ŃL���b�`
	if (GetKeyboardTrigger(DIK_J) && Catch.intervalflag == false && ball->playerhaveflag == false)	//
	{
		Catch.flag = true;
		Catch.intervalflag = true;
	}
	//-----�C���^�[�o��(1s)
	if (Catch.intervalflag == true)
		Catch.intervaltime = Catch.intervaltime + 1.0f;
	if (Catch.intervaltime > catchinterval)
	{
		Catch.intervalflag = false;
		Catch.intervaltime = 0.0f;
	}
	//-----�L���b�`�̔��莞��(0.5s)
	if (Catch.flag == true)
		Catch.coltime = Catch.coltime + 1.0f;
	if (Catch.coltime > catchtime)
	{
		Catch.flag = false;
		Catch.coltime = 0.0f;
	}
	//-----�L���b�`���[�V�������Ƀ{�[�����L���b�`������ɓ�������
	if (Catch.flag == true)
	{
		if (Catch.pos.x + Catch.size.x > ball->pos.x && Catch.pos.x < ball->pos.x + ball->size.x)
		{
			if (Catch.pos.y + Catch.size.y > ball->pos.y && Catch.pos.y < ball->pos.y + ball->size.y)
			{
				ball->throwflag = false;
				ball->playerhaveflag = true;
				ball->move = D3DXVECTOR2(15.0f, -3.5f);
			}
		}
	}
}