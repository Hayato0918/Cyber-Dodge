//�G�l�~�[���� [enemy.cpp]
#include "enemy.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "scene.h"
#include "fade.h"

#include "player.h"
#include "ball.h"
#include "catch.h"
#include "enemy_hp.h"
#include "enemyAI.h"
#include "skillrandom.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�
ENEMY enemy;

//-----����������
HRESULT InitEnemy(void)
{
	enemy.pos = D3DXVECTOR2(800.0f, 320.0f);
	enemy.size = D3DXVECTOR2(256.0f, 256.0f);
	enemy.move = D3DXVECTOR2(2.0f, 2.0f);
	enemy.rotate = 2;

	enemy.atk = 150;
	enemy.def = 50;

	enemy.getskill = false;

	enemy.u = 0.0f;
	enemy.v = 0.0f;
	enemy.uw = 0.5f;
	enemy.vh = 1.0f;
	enemy.drawflag = true;

	enemy.stand_Ltexture = LoadTexture("data/TEXTURE/enemy/stand/orgnl_stand_L.png");
	enemy.stand_Rtexture = LoadTexture("data/TEXTURE/enemy/stand/orgnl_stand_R.png");
	enemy.standtextureflag = true;
	enemy.standLRflag = false;
	enemy.standtexturetime = 0.0f;

	enemy.walk_Ltexture = LoadTexture("data/TEXTURE/enemy/walk/orgnl_walk_L.png");
	enemy.walk_Rtexture = LoadTexture("data/TEXTURE/enemy/walk/orgnl_walk_R.png");
	enemy.walktextureflag = false;
	enemy.walkLRflag = false;
	enemy.walktexturetime = 0.0f;

	enemy.throw_Ltexture = LoadTexture("data/TEXTURE/enemy/throw/orgnl_throw_L.png");
	enemy.throw_Rtexture = LoadTexture("data/TEXTURE/enemy/throw/orgnl_throw_R.png");
	enemy.throwtextureflag = false;
	enemy.throwLRflag = false;
	enemy.throwtexturetime = 0.0f;

	enemy.damage_Ltexture = LoadTexture("data/TEXTURE/enemy/damage/orgnl_damage_L.png");
	enemy.damage_Rtexture = LoadTexture("data/TEXTURE/enemy/damage/orgnl_damage_R.png");
	enemy.damagetextureflag = false;
	enemy.damageLRflag = false;
	enemy.damagetexturetime = 0.0f;

	enemy.deathtexture = LoadTexture("data/TEXTURE/enemy/death/orgnl_death.png");

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
	PLAYER* player = GetPlayer();
	ENEMYHP* enemy_hp = GetEnemyHp();
	SKILL* skill = GetSkill();

	if (enemy.drawflag == true)
	{
		enemyAI();

		////-----�ړ�����(�R�[�g�̍��E�[��3s�ňړ�)
		//if (GetKeyboardPress(DIK_UPARROW))	//��
		//{
		//	enemy.pos.y -= enemy.move.y;
		//	enemy.rotate = 0;
		//}
		//if (GetKeyboardPress(DIK_DOWNARROW))	//��
		//{
		//	enemy.pos.y += enemy.move.y;
		//	enemy.rotate = 1;
		//}
		//if (GetKeyboardPress(DIK_LEFTARROW))	//��
		//{
		//	enemy.pos.x -= enemy.move.x;
		//	enemy.rotate = 2;
		//	enemy.walktextureflag = true;
		//}
		//if (GetKeyboardPress(DIK_RIGHTARROW))	//�E
		//{
		//	enemy.pos.x += enemy.move.x;
		//	enemy.rotate = 3;
		//	enemy.walktextureflag = true;
		//}
		//if (GetKeyboardRelease(DIK_LEFTARROW))
		//	enemy.walktextureflag = false;
		//if (GetKeyboardRelease(DIK_RIGHTARROW))
		//	enemy.walktextureflag = false;
	}

	//-----�R�[�g�O�ɏo�Ȃ�����
	if (enemy.pos.y <= 180 - enemy.size.y * 0.5f)			//��
		enemy.pos.y = 180 - enemy.size.y * 0.5f;
	if (enemy.pos.y >= SCREEN_HEIGHT - enemy.size.y - 15 -120)	//��
		enemy.pos.y = SCREEN_HEIGHT - enemy.size.y - 15 -120;
	if (enemy.pos.x <= SCREEN_WIDTH * 0.5f)								//��
		enemy.pos.x = SCREEN_WIDTH * 0.5f;
	if (enemy.pos.x >= SCREEN_WIDTH - enemy.size.x - 5)								//�E
		enemy.pos.x = SCREEN_WIDTH - enemy.size.x - 5;


	//-----�v���C���[���������{�[�����A�n��,�ǂɓ����炸�G�ɓ���������G�̕`�����߂�(�A�E�g����)
	if (ball->enemyhitflag == true)
	{
		if (enemy.pos.x < ball->pos.x + ball->size.x && enemy.pos.x + enemy.size.x > ball->pos.x)
		{
			if (enemy.pos.y < ball->pos.y + ball->size.y && enemy.pos.y + enemy.size.y > ball->pos.y)
			{
				enemy.damagetextureflag = true;
				enemy_hp->gaugesize.x = enemy_hp->gaugesize.x - (player->atk - enemy.def) * 3.2f;
				ball->enemyhitflag = false;
			}
		}
	}

	//HP��0�ɂȂ�����map�ֈړ�����
	if (enemy_hp->gaugesize.x <= 0)
	{
		enemy.drawflag = false;
		if (enemy.getskill == false)
		{
			skill->slot = skill->slot + 1;
			enemy.getskill = true;
		}
		SceneTransition(SCENE_MAP);
	}




	//-----�`��ݒ�
	//�~�܂��Ă�Ƃ�
	if (enemy.walktextureflag == false)
	{
		enemy.standtexturetime = enemy.standtexturetime + 1.0f;
		if (enemy.rotate == 3)		//�E�������Ă���
		{
			enemy.standLRflag = false;
			if (enemy.standtexturetime < 20)
			{
				enemy.u = 0.75f;
				enemy.uw = 0.25f;
			}
			if (enemy.standtexturetime >= 20 && enemy.standtexturetime <40)
			{
				enemy.u = 0.5f;
				enemy.uw = 0.25f;
			}
			if (enemy.standtexturetime >= 40 && enemy.standtexturetime < 60)
			{
				enemy.u = 0.25f;
				enemy.uw = 0.25f;
			}
			if (enemy.standtexturetime >= 60 && enemy.standtexturetime < 80)
			{
				enemy.u = 0.0f;
				enemy.uw = 0.25f;
			}
			if (enemy.standtexturetime >= 80)
				enemy.standtexturetime = 0.0f;
		}
		if (enemy.rotate == 2)		//���������Ă���
		{
			enemy.standLRflag = true;
			if (enemy.standtexturetime < 20)
			{
				enemy.u = 0.0f;
				enemy.uw = 0.25f;
			}
			if (enemy.standtexturetime >= 20 && enemy.standtexturetime < 40)
			{
				enemy.u = 0.25f;
				enemy.uw = 0.25f;
			}
			if (enemy.standtexturetime >= 40 && enemy.standtexturetime < 60)
			{
				enemy.u = 0.5f;
				enemy.uw = 0.25f;
			}
			if (enemy.standtexturetime >= 60 && enemy.standtexturetime < 80)
			{
				enemy.u = 0.75f;
				enemy.uw = 0.25f;
			}
			if (enemy.standtexturetime >= 80)
				enemy.standtexturetime = 0.0f;
		}
	}

	//�����Ă���Ƃ�
	if (enemy.walktextureflag == true)
	{
		enemy.walktexturetime = enemy.walktexturetime + 1.0f;
		if (enemy.rotate == 3)		//�E�������Ă���
		{
			enemy.walkLRflag = false;
			if (enemy.walktexturetime < 20)
			{
				enemy.u = 0.67f;
				enemy.uw = 0.33f;
			}
			if (enemy.walktexturetime >= 20 && enemy.walktexturetime < 40)
			{
				enemy.u = 0.34f;
				enemy.uw = 0.33f;
			}
			if (enemy.walktexturetime >= 40 && enemy.walktexturetime < 60)
			{
				enemy.u = 0.0f;
				enemy.uw = 0.33f;
			}
			if (enemy.walktexturetime >= 60)
				enemy.walktexturetime = 0.0f;
		}
		if (enemy.rotate == 2)		//���������Ă���
		{
			enemy.walkLRflag = true;
			if (enemy.walktexturetime < 20)
			{
				enemy.u = 0.0f;
				enemy.uw = 0.33f;
			}
			if (enemy.walktexturetime >= 20 && enemy.walktexturetime < 40)
			{
				enemy.u = 0.33f;
				enemy.uw = 0.33f;
			}
			if (enemy.walktexturetime >= 40 && enemy.walktexturetime < 60)
			{
				enemy.u = 0.66f;
				enemy.uw = 0.34f;
			}
			if (enemy.walktexturetime >= 60)
				enemy.walktexturetime = 0.0f;
		}
	}
	if (enemy.walktextureflag == false)
		enemy.walktexturetime = 0.0f;



	//���񂾂Ƃ�
	if (enemy.drawflag == false)
	{
		enemy.u = 0.0f;
		enemy.uw = 1.0f;
	}


	//E_Throw();








}

//-----�`�揈��
void DrawEnemy(void)
{
	if (enemy.drawflag == true)
	{
		//�~�܂��Ă�Ƃ� && (�E�����Ă�Ƃ� || �������Ă�Ƃ�)
		if (enemy.walktextureflag == false && enemy.standLRflag == false)
			DrawSpriteLeftTop(enemy.stand_Ltexture, enemy.pos.x, enemy.pos.y, enemy.size.x, enemy.size.y, enemy.u, enemy.v, enemy.uw, enemy.vh);
		if (enemy.walktextureflag == false && enemy.standLRflag == true)
			DrawSpriteLeftTop(enemy.stand_Rtexture, enemy.pos.x, enemy.pos.y, enemy.size.x, enemy.size.y, enemy.u, enemy.v, enemy.uw, enemy.vh);

		//�����Ă�Ƃ� && (�E�����Ă�Ƃ� || �������Ă�Ƃ�)
		if (enemy.walktextureflag == true && enemy.walkLRflag == false)
			DrawSpriteLeftTop(enemy.walk_Ltexture, enemy.pos.x, enemy.pos.y, enemy.size.x, enemy.size.y, enemy.u, enemy.v, enemy.uw, enemy.vh);
		if (enemy.walktextureflag == true && enemy.walkLRflag == true)
			DrawSpriteLeftTop(enemy.walk_Rtexture, enemy.pos.x, enemy.pos.y, enemy.size.x, enemy.size.y, enemy.u, enemy.v, enemy.uw, enemy.vh);



	}


	//���񂾂Ƃ�
	if (enemy.drawflag == false)
		DrawSpriteLeftTop(enemy.deathtexture, enemy.pos.x, enemy.pos.y, enemy.size.x, enemy.size.y, enemy.u, enemy.v, enemy.uw, enemy.vh);
}

//-----�\���̃|�C���^�擾����
ENEMY* GetEnemy(void)
{
	return &enemy;
}