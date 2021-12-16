//�v���C���[���� [player.cpp]
#include "player.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "scene.h"
#include "fade.h"

#include "enemy.h"
#include "escape.h"
#include "ball.h"
#include "catch.h"
#include "skill.h"
#include "invade.h"
#include "player_hp.h"
#include "skillrandom.h"

#include "reverse.h"
#include "map_point.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�
PLAYER player;

//-----����������
HRESULT InitPlayer(void)
{
	InitSkill();

	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->gamecount == 1)
	{
		player.pos = D3DXVECTOR2(240.0f, 320.0f);
		player.size = D3DXVECTOR2(200.0f, 240.0f);
		player.move = D3DXVECTOR2(4.0f, 4.0f);
		player.rotate = 3;
		player.drawflag = true;

		player.atk = 150;
		player.def = 0;

		player.u = 0.0f;
		player.v = 0.0f;
		player.uw = 0.5f;
		player.vh = 1.0f;

		player.stand_Ltexture = LoadTexture("data/TEXTURE/player/stand/orgnl_stand_L.png");
		player.stand_Rtexture = LoadTexture("data/TEXTURE/player/stand/orgnl_stand_R.png");
		player.standtextureflag = true;
		player.standLRflag = false;

		player.walk_Ltexture = LoadTexture("data/TEXTURE/player/walk/orgnl_walk_L.png");
		player.walk_Rtexture = LoadTexture("data/TEXTURE/player/walk/orgnl_walk_R.png");
		player.walktextureflag = false;
		player.walkLRflag = false;

		player.catch_Ltexture = LoadTexture("data/TEXTURE/player/catch/orgnl_catch_L.png");
		player.catch_Rtexture = LoadTexture("data/TEXTURE/player/catch/orgnl_catch_R.png");
		player.catchtextureflag = false;
		player.catchLRflag = false;
		player.catchtexturetime = 0.0f;

		player.pick_Ltexture = LoadTexture("data/TEXTURE/player/pick/orgnl_pick_L.png");
		player.pick_Rtexture = LoadTexture("data/TEXTURE/player/pick/orgnl_pick_R.png");
		player.picktextureflag = false;
		player.pickLRflag = false;
		player.picktexturetime = 0.0f;

		player.throw_Ltexture = LoadTexture("data/TEXTURE/player/throw/orgnl_throw_L.png");
		player.throw_Rtexture = LoadTexture("data/TEXTURE/player/throw/orgnl_throw_R.png");
		player.throwtextureflag = false;
		player.throwLRflag = false;
		player.throwtexturetime = 0.0f;

		player.skill_Ltexture = LoadTexture("data/TEXTURE/player/skill/orgnl_skill_L.png");
		player.skill_Rtexture = LoadTexture("data/TEXTURE/player/skill/orgnl_skill_R.png");
		player.skilltextureflag = false;
		player.skillLRflag = false;
		player.skilltexturetime = 0.0f;
		player.skilluseflag = false;

		player.damage_Ltexture = LoadTexture("data/TEXTURE/player/damage/orgnl_damage_L.png");
		player.damage_Rtexture = LoadTexture("data/TEXTURE/player/damage/orgnl_damage_R.png");
		player.damagetextureflag = false;
		player.damageLRflag = false;
		player.damagetexturetime = 0.0f;

		player.deathtexture = LoadTexture("data/TEXTURE/player/death/orgnl_death.png");

		player.drawdepth = false;
	}

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
	PLAYERHP* hp = GetPlayerHp();
	RANDOM* random = GetRandom();
	ENEMY* enemy = GetEnemy();

	REVERSE* reverse = GetReverse();

	//pad�̂Ƃ�
	if (PADUSE == 0)
	{
		if (IsButtonPressed(0, BUTTON_UP))
		{
			if (reverse->use == false)
				player.pos.y -= player.move.y;
			if (reverse->use == true)
				player.pos.y += player.move.y;
		}
		if (IsButtonPressed(0, BUTTON_DOWN))
		{
			if (reverse->use == false)
				player.pos.y += player.move.y;
			if (reverse->use == true)
				player.pos.y -= player.move.y;
		}
		if (IsButtonPressed(0, BUTTON_LEFT))
		{
			if (reverse->use == false)
				player.pos.x -= player.move.x;
			if (reverse->use == true)
				player.pos.x += player.move.x;

			player.rotate = 2;		//�������ɍX�V

			player.walktextureflag = true;		//�e�N�X�`���̐؂�ւ�
		}
		if (IsButtonPressed(0, BUTTON_RIGHT))
		{
			if (reverse->use == false)
				player.pos.x += player.move.x;
			if (reverse->use == true)
				player.pos.x -= player.move.x;

			player.rotate = 3;		//�E�����ɍX�V

			player.walktextureflag = true;		//�e�N�X�`���̐؂�ւ�
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
				player.pos.y -= player.move.y;
			if (reverse->use == true)
				player.pos.y += player.move.y;
		}
		if (GetKeyboardPress(DIK_S))	//��
		{
			if (reverse->use == false)
				player.pos.y += player.move.y;
			if (reverse->use == true)
				player.pos.y -= player.move.y;
		}
		if (GetKeyboardPress(DIK_A))	//��
		{
			if (reverse->use == false)
				player.pos.x -= player.move.x;
			if (reverse->use == true)
				player.pos.x += player.move.x;

			player.rotate = 2;		//�������ɍX�V

			player.walktextureflag = true;		//�e�N�X�`���̐؂�ւ�
		}
		if (GetKeyboardPress(DIK_D))	//�E
		{
			if (reverse->use == false)
				player.pos.x += player.move.x;
			if (reverse->use == true)
				player.pos.x -= player.move.x;

			player.rotate = 3;		//�E�����ɍX�V

			player.walktextureflag = true;		//�e�N�X�`���̐؂�ւ�
		}

		if (GetKeyboardRelease(DIK_A))	//���ړ�����߂���
			player.walktextureflag = false;
		if (GetKeyboardRelease(DIK_D))	//�E�ړ�����߂���
			player.walktextureflag = false;
	}

	//�v���C���[�ƃ{�[���̕`�揇�𐮂���v�Z
	if (player.pos.y + player.size.y - ball->size.y >= ball->pos.y)
		player.drawdepth = false;
	if (player.pos.y + player.size.y - ball->size.y < ball->pos.y)
		player.drawdepth = true;

	//-----�R�[�g�O�ɏo�Ȃ�����
	if (player.pos.y <= 230.f - player.size.y * 0.5f)	//��
		player.pos.y = 230.f - player.size.y * 0.5f;
	if (player.pos.y >= SCREEN_HEIGHT - player.size.y - 15 -120)	//��
		player.pos.y = SCREEN_HEIGHT - player.size.y - 15 -120;
	if (player.pos.x <= 0 + 15)		//��
		player.pos.x = 0 + 15;

	if (invade->timeflag == false)		//�s�@�N���X�L���̔���
	{
		if (player.pos.x >= SCREEN_WIDTH * 0.5f - player.size.x - 5)	//�E
			player.pos.x = SCREEN_WIDTH * 0.5f - player.size.x - 5;
	}
	if (invade->timeflag == true)
	{
		if (player.pos.x >= SCREEN_WIDTH - player.size.x - 5)	//�E
			player.pos.x = SCREEN_WIDTH - player.size.x - 5;
	}

	//-----�_���[�W����
	//if (barrier->drawflag == false)
	//{
	if (ball->playerhitflag == true)
	{
		if (player.rotate == 3)
		{
			if (player.pos.x < ball->pos.x + ball->size.x && player.pos.x + player.size.x * 0.8f > ball->pos.x)
			{
				if (player.pos.y + player.size.y * 0.2f < ball->pos.y + ball->size.y && player.pos.y + player.size.y * 0.8f > ball->pos.y)
				{
					player.damagetextureflag = true;
					hp->gaugesize.x = hp->gaugesize.x -(enemy->atk - player.def) * 3.2f;
					hp->pos.x = hp->pos.x + (enemy->atk - player.def) * 3.2f;
					ball->playerhitflag = false;
				}
			}
		}

		if (player.rotate == 2)
		{
			if (player.pos.x < ball->pos.x + ball->size.x && player.pos.x + player.size.x * 0.5f > ball->pos.x)
			{
				if (player.pos.y + player.size.y * 0.2f < ball->pos.y + ball->size.y && player.pos.y + player.size.y * 0.8f > ball->pos.y)
				{
					player.damagetextureflag = true;
					hp->gaugesize.x = hp->gaugesize.x - (enemy->atk - player.def);
					hp->pos.x = hp->pos.x + (enemy->atk - player.def);
					ball->playerhitflag = false;
				}
			}
		}
	}
	//}

	//-----���S����
	if (hp->gaugesize.x <= 0)
	{
		player.drawflag = false;
		SceneTransition(SCENE_MAP);
	}




	//-----�������
	_Escape();

	//-----�����鏈��
	P_Throw();

	//-----�L���b�`����
	P_Catch();

	//-----�X�L������
	_Skill();

	//-----�`��ݒ�
	//�~�܂��Ă�Ƃ�
	if (player.walktextureflag == false)
	{
		if (ball->playerhaveflag == false)	//�{�[���������ĂȂ�������
		{
			if (player.rotate == 3)		//�E�������Ă���
			{
				player.u = 0.0f;
				player.uw = 0.5f;
				player.standLRflag = false;
			}
			if (player.rotate == 2)		//���������Ă���
			{
				player.u = 0.5f;
				player.uw = 0.5f;
				player.standLRflag = true;
			}
		}

		if (ball->playerhaveflag == true)	//�{�[���������Ă�Ƃ�
		{
			if (player.rotate == 3)		//�E�������Ă���
			{
				player.u = 0.5f;
				player.uw = 0.5f;
				player.standLRflag = false;
			}
			if (player.rotate == 2)		//���������Ă���
			{
				player.u = 0.0f;
				player.uw = 0.5f;
				player.standLRflag = true;
			}
		}
	}

	//�����Ă���Ƃ�
	if (player.walktextureflag == true)
	{
		if (ball->playerhaveflag == false)	//�{�[�������ĂȂ�������
		{
			if (player.rotate == 3)		//�E�������Ă���
			{
				player.u = 0.f;
				player.uw = 0.5f;
				player.walkLRflag = false;
			}
			if (player.rotate == 2)		//���������Ă���
			{
				player.u = 0.5f;
				player.uw = 0.5f;
				player.walkLRflag = true;
			}
		}

		if (ball->playerhaveflag == true)	//�{�[���������Ă�Ƃ�
		{
			if (player.rotate == 3)		//�E�������Ă���
			{
				player.u = 0.5f;
				player.uw = 0.5f;
				player.walkLRflag = false;
			}
			if (player.rotate == 2)		//���������Ă���
			{
				player.u = 0.0f;
				player.uw = 0.5f;
				player.walkLRflag = true;
			}
		}
	}

	//�L���b�`�����Ƃ�
	if (ball->playerhaveflag == true)	//�v���C���[���{�[�����L���b�`������
	{
		if (ball->fallflag == false)
		{
			player.catchtexturetime = player.catchtexturetime + 1.0f;
			if (player.rotate == 3)		//�E�������Ă�����
			{
				player.catchtextureflag = true;
				player.catchLRflag = false;
				if (player.catchtexturetime < 5)	//
				{
					player.u = 0.7f;
					player.uw = 0.3f;
				}
				if (player.catchtexturetime >= 5 && player.catchtexturetime < 15)
				{
					player.u = 0.33f;
					player.uw = 0.375f;
				}
				if (player.catchtexturetime >= 15 && player.catchtexturetime < 20)
				{
					player.u = 0.0f;
					player.uw = 0.33f;
				}
				if (player.catchtexturetime >= 20)
					player.catchtextureflag = false;
			}
			if (player.rotate == 2)
			{
				player.catchtextureflag = true;
				player.catchLRflag = true;
				if (player.catchtexturetime < 5)
				{
					player.u = 0.0f;
					player.uw = 0.3f;
				}
				if (player.catchtexturetime >= 5 && player.catchtexturetime < 15)
				{
					player.u = 0.29f;
					player.uw = 0.375f;
				}
				if (player.catchtexturetime >= 15 && player.catchtexturetime < 20)
				{
					player.u = 0.67f;
					player.uw = 0.33f;
				}
				if (player.catchtexturetime >= 20)
					player.catchtextureflag = false;
			}
		}
	}
	if (ball->playerhaveflag == false)
	{
		player.catchtexturetime = 0.0f;
		player.catchtextureflag = false;
	}

	//�����Ă���{�[�����E�����Ƃ�
	if (ball->playerhaveflag == true)
	{
		if (ball->fallflag == true)
		{
			player.picktexturetime = player.picktexturetime + 1.0f;
			if (player.rotate == 3)		//�E�������Ă�����
			{
				player.picktextureflag = true;
				player.pickLRflag = false;
				if (player.picktexturetime < 30)	//
				{
					player.u = 0.0f;
					player.uw = 0.55f;
				}
				if (player.picktexturetime >= 30 && player.picktexturetime < 20)
				{
					player.u = 0.55f;
					player.uw = 0.45f;
				}
				if (player.picktexturetime >= 20)
				{
					player.picktextureflag = false;
					
				}
			}
			if (player.rotate == 2)
			{
				player.picktextureflag = true;
				player.pickLRflag = true;
				if (player.picktexturetime < 10)
				{
					player.u = 0.45f;
					player.uw = 0.55f;
				}
				if (player.picktexturetime >= 10 && player.picktexturetime < 15)
				{
					player.u = 0.0f;
					player.uw = 0.45f;
				}
				if (player.picktexturetime >= 15)
				{
					player.picktextureflag = false;
				}
			}
		}
	}
	if (ball->playerhaveflag == false)
	{
		player.picktexturetime = 0.0f;
		player.picktextureflag = false;
	}

	//�������Ƃ�
	if (ball->playerthrowflag == true)
	{
		player.throwtexturetime = player.throwtexturetime + 1.0f;
		if (player.rotate == 3)		//�E�������Ă�����
		{
			player.throwtextureflag = true;
			player.throwLRflag = false;
			if (player.throwtexturetime < 5)	//
			{
				player.u = 0.0f;
				player.uw = 0.2f;
			}
			if (player.throwtexturetime >= 5 && player.throwtexturetime < 10)
			{
				player.u = 0.2f;
				player.uw = 0.2f;
			}
			if (player.throwtexturetime >= 10 && player.throwtexturetime < 15)
			{
				player.u = 0.4f;
				player.uw = 0.26f;
			}
			if (player.throwtexturetime >= 15 && player.throwtexturetime < 20)
			{
				player.u = 0.66f;
				player.uw = 0.18f;
			}
			if (player.throwtexturetime >= 20 && player.throwtexturetime < 25)
			{
				player.u = 0.84f;
				player.uw = 0.16f;
			}
			if (player.throwtexturetime >= 25)
			{
				player.throwtextureflag = false;
				player.throwtexturetime = 0.0f;
				ball->playerthrowflag = false;
			}
		}
		if (player.rotate == 2)
		{
			player.throwtextureflag = true;
			player.throwLRflag = true;
			if (player.throwtexturetime < 5)	//
			{
				player.u = 0.8f;
				player.uw = 0.2f;
			}
			if (player.throwtexturetime >= 5 && player.throwtexturetime < 10)
			{
				player.u = 0.6f;
				player.uw = 0.2f;
			}
			if (player.throwtexturetime >= 10 && player.throwtexturetime < 15)
			{
				player.u = 0.34f;
				player.uw = 0.26f;
			}
			if (player.throwtexturetime >= 15 && player.throwtexturetime < 20)
			{
				player.u = 0.16f;
				player.uw = 0.18f;
			}
			if (player.throwtexturetime >= 20 && player.throwtexturetime < 25)
			{
				player.u = 0.0f;
				player.uw = 0.16f;
			}
			if (player.throwtexturetime >= 25)
			{
				player.throwtextureflag = false;
				player.throwtexturetime = 0.0f;
				ball->playerthrowflag = false;
			}
		}
	}

	//�X�L�����g�����Ƃ�
	if (player.skilluseflag == true)
	{
		player.skilltexturetime = player.skilltexturetime + 1.0f;
		if (player.rotate == 3)		//�E�������Ă�����
		{
			player.skilltextureflag = true;
			player.skillLRflag = false;
			if (player.skilltexturetime < 5)
			{
				player.u = 0.0f;
				player.uw = 0.23f;
			}
			if (player.skilltexturetime >= 5 && player.skilltexturetime < 10)
			{
				player.u = 0.23f;
				player.uw = 0.23f;
			}
			if (player.skilltexturetime >= 10 && player.skilltexturetime < 15)
			{
				player.u = 0.46f;
				player.uw = 0.27f;
			}
			if (player.skilltexturetime >= 15 && player.skilltexturetime < 20)
			{
				player.u = 0.73f;
				player.uw = 0.27f;
			}
			if (player.skilltexturetime >= 20)
			{
				player.skilltextureflag = false;
				player.skilluseflag = false;
				player.skilltexturetime = 0.0f;
			}
		}
		if (player.rotate == 2)
		{
			player.skilltextureflag = true;
			player.skillLRflag = true;
			if (player.skilltexturetime < 5)	//
			{
				player.u = 0.78f;
				player.uw = 0.22f;
				}
			if (player.skilltexturetime >= 5 && player.skilltexturetime < 10)
			{
				player.u = 0.54f;
				player.uw = 0.23f;
			}
			if (player.skilltexturetime >= 10 && player.skilltexturetime < 15)
			{
				player.u = 0.27f;
				player.uw = 0.27f;
			}
			if (player.skilltexturetime >= 15 && player.skilltexturetime < 20)
			{
				player.u = 0.0f;
				player.uw = 0.27f;
			}
			if (player.skilltexturetime >= 20)
			{
				player.skilltextureflag = false;
				player.skilluseflag = false;
				player.skilltexturetime = 0.0f;
			}
		}
	}



	//�_���[�W���󂯂��Ƃ�
	if (player.damagetextureflag == true)
	{
		player.damagetexturetime = player.damagetexturetime + 1.0f;
		if (player.rotate == 3)
		{
			player.u = 0.0f;
			player.uw = 1.0f;
			player.damageLRflag = false;
			if (player.damagetexturetime > 15)
			{
				player.damagetextureflag = false;
				player.damagetexturetime = 0.0f;
			}
		}
		if (player.rotate == 2)
		{
			player.u = 0.0f;
			player.uw = 1.0f;
			player.damageLRflag = true;
			if (player.damagetexturetime > 15)
			{
				player.damagetextureflag = false;
				player.damagetexturetime = 0.0f;
			}
		}
	}

	if (player.drawflag == false)
	{
		//player.size.y = 180.0f;
		player.u = 0.0f;
		player.uw = 1.0f;
	}













}

//-----�`�揈��
void DrawPlayer(void)
{
	BALL* ball = GetBall();

	if (player.drawflag == true)
	{
		if (player.damagetextureflag == false)	//�_���[�W���[�V������D��
		{
			if (player.catchtextureflag == false)	//�L���b�`���[�V������D��
			{
				if (player.picktextureflag == false)	//�s�b�N���[�V������D��
				{
					if (player.throwtextureflag == false)	//�������[�V������D��
					{
						if (player.skilltextureflag == false)	//�X�L�����[�V������D��
						{
							//�~�܂��Ă�Ƃ� && (�E�����Ă�Ƃ� || �������Ă�Ƃ�)
							if (player.walktextureflag == false && player.standLRflag == false)
								DrawSpriteLeftTop(player.stand_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
							if (player.walktextureflag == false && player.standLRflag == true)
								DrawSpriteLeftTop(player.stand_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);

							//�����Ă���Ƃ� && (�E�����Ă�Ƃ� || �������Ă�Ƃ�)
							if (player.walktextureflag == true && player.walkLRflag == false)
								DrawSpriteLeftTop(player.walk_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
							if (player.walktextureflag == true && player.walkLRflag == true)
								DrawSpriteLeftTop(player.walk_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
						}
					}
				}
			}
		}

		if (player.damagetextureflag == false)	//�_���[�W���[�V������D��
		{
			//�L���b�`�����Ƃ� && (�E�����Ă�Ƃ� || �������Ă�Ƃ�)
			if (player.catchtextureflag == true && player.catchLRflag == false)
				DrawSpriteLeftTop(player.catch_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
			if (player.catchtextureflag == true && player.catchLRflag == true)
				DrawSpriteLeftTop(player.catch_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);

			//�����Ă���{�[�����E�����Ƃ� && (�E�����Ă�Ƃ� || �������Ă�Ƃ�)
			if (player.picktextureflag == true && player.pickLRflag == false)
				DrawSpriteLeftTop(player.pick_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
			if (player.picktextureflag == true && player.pickLRflag == true)
				DrawSpriteLeftTop(player.pick_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);

			//�������Ƃ� && ((�E�����Ă�Ƃ� || �������Ă�Ƃ�))
			if (player.throwtextureflag == true && player.throwLRflag == false)
				DrawSpriteLeftTop(player.throw_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
			if (player.throwtextureflag == true && player.throwLRflag == true)
				DrawSpriteLeftTop(player.throw_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);

			//�X�L�����g�����Ƃ� && ((�E�����Ă�Ƃ� || �������Ă�Ƃ�))
			if (player.skilltextureflag == true && player.skillLRflag == false)
				DrawSpriteLeftTop(player.skill_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
			if (player.skilltextureflag == true && player.skillLRflag == true)
				DrawSpriteLeftTop(player.skill_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
		}

		//�_���[�W���󂯂��Ƃ� && (�E�����Ă�Ƃ� || �������Ă�Ƃ�)
		if (player.damagetextureflag == true && player.damageLRflag == false)
			DrawSpriteLeftTop(player.damage_Ltexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
		if (player.damagetextureflag == true && player.damageLRflag == true)
			DrawSpriteLeftTop(player.damage_Rtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);



	}

	if (player.drawflag == false)	//���S��
	{
		DrawSpriteLeftTop(player.deathtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
	}

	//-----�X�L���`��
	DrawSkill();
}

//-----�\���̃|�C���^�擾����
PLAYER* GetPlayer(void)
{
	return &player;
}