//�v���C���[���� [player.cpp]
#include "player.h"
//�V�X�e��.h
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "scene.h"
#include "fade.h"
//�G�l�~�[.h
#include "firewall.h"
#include "deleter.h"
#include "slime.h"
//�v���C���[.h
#include "player_operate.h"
#include "player_animation.h"
#include "player_damage.h"
#include "player_hp.h"
//�{�[��.h
#include "ball.h"
#include "catch.h"
//�}�b�v.h
#include "map_player.h"
//�X�L��.h
#include "skill.h"
#include "skillrandom.h"
#include "invade.h"
#include "create.h"
#include "bg.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�
PLAYER player;

//-----����������
HRESULT InitPlayer(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	player.pos = D3DXVECTOR2(240.0f, 320.0f);
	player.size = D3DXVECTOR2(200.0f, 240.0f);
	player.move = D3DXVECTOR2(4.0f, 4.0f);
	player.rotate = 3;
	player.drawflag = true;

	player.u = 0.0f;
	player.v = 0.0f;
	player.uw = 0.5f;
	player.vh = 1.0f;

	if (map_player->gamecount == 1)
	{
		player.atk = 100;
		player.def = 0;
		player.gold = 1000;

		//������Ԃ̃e�N�X�`���ݒ�
		player.stand_Ltexture = LoadTexture("data/TEXTURE/player/stand/stand_R.png");
		player.stand_Rtexture = LoadTexture("data/TEXTURE/player/stand/stand_L.png");
		player.standtextureflag = true;
		player.standLRflag = false;
		//������Ԃ̃e�N�X�`���ݒ�
		player.walk_Ltexture = LoadTexture("data/TEXTURE/player/walk/walk_R.png");
		player.walk_Rtexture = LoadTexture("data/TEXTURE/player/walk/walk_L.png");
		player.walktextureflag = false;
		player.walkLRflag = false;
		//�L���b�`��Ԃ̃e�N�X�`���ݒ�
		player.catch_Ltexture = LoadTexture("data/TEXTURE/player/catch/catch_R.png");
		player.catch_Rtexture = LoadTexture("data/TEXTURE/player/catch/catch_L.png");
		player.catchtextureflag = false;
		player.catchLRflag = false;
		player.catchtexturetime = 0.0f;
		//�E����Ԃ̃e�N�X�`���ݒ�
		player.pick_Ltexture = LoadTexture("data/TEXTURE/player/pick/pick_R.png");
		player.pick_Rtexture = LoadTexture("data/TEXTURE/player/pick/pick_L.png");
		player.picktextureflag = false;
		player.pickLRflag = false;
		player.picktexturetime = 0.0f;
		//������Ԃ̃e�N�X�`���ݒ�
		player.throw_Ltexture = LoadTexture("data/TEXTURE/player/throw/throw_R.png");
		player.throw_Rtexture = LoadTexture("data/TEXTURE/player/throw/throw_L.png");
		player.throwtextureflag = false;
		player.throwLRflag = false;
		player.throwtexturetime = 0.0f;
		//�X�L���g�p���̃e�N�X�`���ݒ�
		player.skill_Ltexture = LoadTexture("data/TEXTURE/player/skill/skill_R.png");
		player.skill_Rtexture = LoadTexture("data/TEXTURE/player/skill/skill_L.png");
		player.skilltextureflag = false;
		player.skillLRflag = false;
		player.skilltexturetime = 0.0f;
		player.skilluseflag = false;
		//�_���[�W��Ԃ̃e�N�X�`���ݒ�
		player.damage_Ltexture = LoadTexture("data/TEXTURE/player/damage/damage_R.png");
		player.damage_Rtexture = LoadTexture("data/TEXTURE/player/damage/damage_L.png");
		player.damagetextureflag = false;
		player.damageLRflag = false;
		player.damagetexturetime = 0.0f;
		//���S���̃e�N�X�`���ݒ�
		player.deathtexture = LoadTexture("data/TEXTURE/player/death/death.png");

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
	MAP_PLAYER* map_player = GetMapPlayer();
	BG* bg = GetBG();

	//-----���쏈��
	player_operate();

	//-----�R�[�g�O�ɏo�Ȃ�����
	if (player.pos.y <= 230.f - player.size.y * 0.5f)	//��
		player.pos.y = 230.f - player.size.y * 0.5f;
	if (player.pos.y >= SCREEN_HEIGHT - player.size.y - 15 - 120)	//��
		player.pos.y = SCREEN_HEIGHT - player.size.y - 15 - 120;
	for (int i = 0; i < 100; i++)
	{
		if (player.pos.y <= 525 - 4.15f * i)
		{
			if (player.pos.x <= 1.55f * i + 10)		//��
				player.pos.x = 1.55f * i + 10;
		}
	}

	if (invade->timeflag == false)		//�s�@�N���X�L���̔���
	{
		if (player.pos.x >= bg->clPos.x - player.size.x - 5)	//�E
			player.pos.x = bg->clPos.x - player.size.x - 5;
	}
	if (invade->timeflag == true)
	{
		if (player.pos.x >= SCREEN_WIDTH - player.size.x - 5)	//�E
			player.pos.x = SCREEN_WIDTH - player.size.x - 5;
	}

	//-----�v���C���[�ƃ{�[���̕`�揇�𐮂���v�Z
	if (player.pos.y + player.size.y - ball->size.y >= ball->pos.y)
		player.drawdepth = false;
	if (player.pos.y + player.size.y - ball->size.y < ball->pos.y)
		player.drawdepth = true;

	//-----�_���[�W����
	if(map_player->encount == 1)
		Player_SlimeDamage();
	if (map_player->encount == 2)
		Player_DeleterDamage();
	if (map_player->encount == 3)
		Player_FireWallDamage();

	//-----���S����
	if (hp->gaugesize.x <= 0)
	{
		player.drawflag = false;
		SceneTransition(SCENE_GAMEOVER);
	}

	//-----�A�j���[�V��������
	player_animation();

	//��΂Ƃ̓����蔻��
	player.colPos = D3DXVECTOR2(player.pos.x + player.size.x / 2, player.pos.y + player.size.y / 2 + player.size.y / 4); //�����蔻��̍��W�̍X�V

	CREATE* create = GetCreate(0);

	if (create->timeflag)
	{
		for (int i = 0; i < 3; i++) // ������3�͐���������΂̌���\���Bcreate�Ő���ύX�����ۂ͂������ύX���ĉ������B
		{
			CREATE* create = GetCreate(i);

			if (player.colPos.x > create->pos.x - create->size.x / 2 && player.colPos.x < create->pos.x + create->size.x / 2 &&
				player.colPos.y > create->pos.y - create->size.y / 2 && player.colPos.y < create->pos.y + create->size.y / 2)
			{
				float ax = 0.0f;
				float ay = 0.0f;
				float bx = 0.0f;
				float by = 450.0f;
				if (player.colPos.x < create->pos.x)
					//��΂̍���
				{
					ax = (create->pos.x - player.colPos.x) / create->size.x / 2;
					bx = create->pos.x - create->size.x / 2 - player.size.x / 2;
				}
				else if (player.colPos.x > create->pos.x)
					//��΂̉E��
				{
					ax = (player.colPos.x - create->pos.x) / create->size.x / 2;
					bx = create->pos.x + create->size.x / 2 - player.size.x / 2;
				}

				if (player.colPos.y < create->pos.y)
					//��΂̏㑤
				{
					ay = (create->pos.y - player.colPos.y) / create->size.y / 2;
					by = create->pos.y - create->size.y / 2 - player.size.y / 2 - player.size.y / 4;
				}
				else if (player.colPos.y > create->pos.y)
					//��΂̉���
				{
					ay = (player.colPos.y - create->pos.y) / create->size.y / 2;
					by = create->pos.y + create->size.y / 2 - player.size.y / 2 - player.size.y / 4;
				}

				if (ax > ay)
				{
					player.pos.x = bx;
				}
				else if (ax < ay)
				{
					player.pos.y = by;
				}
				else
				{
					player.pos.x = create->pos.x - create->size.x / 2 - player.size.x / 2;
				}
			}
		}
	}
}

//-----�`�揈��
void DrawPlayer(void)
{
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
		DrawSpriteLeftTop(player.deathtexture, player.pos.x, player.pos.y, player.size.x, player.size.y, player.u, player.v, player.uw, player.vh);
}

//-----�\���̃|�C���^�擾����
PLAYER* GetPlayer(void)
{
	return &player;
}