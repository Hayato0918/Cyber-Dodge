//�f���[�^�[���� [deleter.cpp]
#include "deleter.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "scene.h"
#include "fade.h"

#include "player.h"
#include "bg.h"
#include "ball.h"
#include "catch.h"
#include "deleter_animation.h"
#include "deleter_hp.h"
#include "deleterAI.h"
#include "skillrandom.h"
#include "create.h"
#include "map_player.h"
#include "enemybreak.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�
DELETER deleter;

//-----����������
HRESULT InitDeleter(void)
{
	deleter.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.355555f);
	deleter.size = D3DXVECTOR2(SCREEN_WIDTH * 0.16f, SCREEN_HEIGHT * 0.2844444f);
	deleter.move = D3DXVECTOR2(SCREEN_WIDTH * 0.00125f, SCREEN_HEIGHT * 0.002222f);
	deleter.colPos = D3DXVECTOR2(deleter.pos.x + deleter.size.x / 2, deleter.pos.y + deleter.size.y / 2 + deleter.size.y / 4);
	deleter.rotate = 2;

	deleter.atk = 150;
	deleter.def = 50;

	deleter.getskill = false;

	deleter.u = 0.0f;
	deleter.v = 0.0f;
	deleter.uw = 0.5f;
	deleter.vh = 1.0f;
	deleter.drawflag = true;

	deleter.stand_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/stand/stand_R.png");
	deleter.stand_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/stand/stand_L.png");
	deleter.standtextureflag = true;
	deleter.standLRflag = false;
	deleter.standtexturetime = 0.0f;

	deleter.walk_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/walk/walk_R.png");
	deleter.walk_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/walk/walk_L.png");
	deleter.walktextureflag = false;
	deleter.walkLRflag = false;
	deleter.walktexturetime = 0.0f;

	deleter.throw_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/throw/throw_R.png");
	deleter.throw_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/throw/throw_L.png");
	deleter.throwtextureflag = false;
	deleter.throwLRflag = false;
	deleter.throwtexturetime = 0.0f;

	deleter.damage_Ltexture = LoadTexture("data/TEXTURE/enemy/firewall/damage/damage_R.png");
	deleter.damage_Rtexture = LoadTexture("data/TEXTURE/enemy/firewall/damage/damage_L.png");
	deleter.damagetextureflag = false;
	deleter.damageLRflag = false;
	deleter.damagetexturetime = 0.0f;

	deleter.deathtexture = LoadTexture("data/TEXTURE/enemy/firewall/death/death.png");

	return S_OK;
}

//-----�I������
void UninitDeleter(void)
{

}

//-----�X�V����
void UpdateDeleter(void)
{
	BALL* ball = GetBall();
	PLAYER* player = GetPlayer();
	DELETERHP* deleter_hp = GetDeleterHp();
	SKILL* skill = GetSkill();
	BG* bg = GetBG();
	MAP_PLAYER* map_player = GetMapPlayer();
	ENEMYBREAK* enemybreak = GetEnemyBreak();

	if (deleter.drawflag == true)
		DeleterAI();

	//-----�R�[�g�O�ɏo�Ȃ�����
	if (deleter.pos.y <= SCREEN_HEIGHT * 0.27f - deleter.size.y * 0.5f)			//��
		deleter.pos.y = SCREEN_HEIGHT * 0.27f - deleter.size.y * 0.5f;
	if (deleter.pos.y >= SCREEN_HEIGHT - deleter.size.y - SCREEN_HEIGHT * 0.188888f)	//��
		deleter.pos.y = SCREEN_HEIGHT - deleter.size.y - SCREEN_HEIGHT * 0.188888f;
	if (deleter.pos.x <= bg->clPos.x)								//��
		deleter.pos.x = bg->clPos.x;
	if (deleter.pos.x >= SCREEN_WIDTH - deleter.size.x - SCREEN_WIDTH * 0.003125f)								//�E
		deleter.pos.x = SCREEN_WIDTH - deleter.size.x - SCREEN_WIDTH * 0.003125f;


	//-----�v���C���[���������{�[�����A�n��,�ǂɓ����炸�G�ɓ���������G�Ƀ_���[�W��^����(�A�E�g����)
	if (ball->enemyhitflag == true)
	{
		if (deleter.pos.x < ball->pos.x + ball->size.x && deleter.pos.x + deleter.size.x > ball->pos.x)
		{
			if (deleter.pos.y < ball->pos.y + ball->size.y && deleter.pos.y + deleter.size.y > ball->pos.y)
			{
				deleter.damagetextureflag = true;
				deleter_hp->gaugesize.x = deleter_hp->gaugesize.x - (player->atk - deleter.def) * SCREEN_WIDTH * 0.002f;
				ball->enemyhitflag = false;
			}
		}
	}

	//HP��0�ɂȂ�����map�ֈړ�����
	if (deleter_hp->gaugesize.x <= 0)
	{
		deleter.drawflag = false;
		if (deleter.getskill == false)
		{
			skill->slot = skill->slot + 1;
			deleter.getskill = true;
		}
		map_player->nextflag = true;
		enemybreak->drawflag = true;
	}

	//-----�A�j���[�V��������
	deleter_animation();

	//��΂Ƃ̓����蔻��
	deleter.colPos = D3DXVECTOR2(deleter.pos.x + deleter.size.x / 2, deleter.pos.y + deleter.size.y / 2 + deleter.size.y / 4); //�����蔻��̍��W�̍X�V

	CREATE* create = GetCreate(0);

	if (create->timeflag)
	{
		for (int i = 0; i < 3; i++) // ������3�͐���������΂̌���\���Bcreate�Ő���ύX�����ۂ͂������ύX���ĉ������B
		{
			CREATE* create = GetCreate(i);

			if (deleter.colPos.x > create->pos.x - create->size.x / 2 && deleter.colPos.x < create->pos.x + create->size.x / 2 &&
				deleter.colPos.y > create->pos.y - create->size.y / 2 && deleter.colPos.y < create->pos.y + create->size.y / 2)
			{
				float ax = 0.0f;
				float ay = 0.0f;
				float bx = 0.0f;
				float by = SCREEN_HEIGHT * 0.5f;
				if (deleter.colPos.x < create->pos.x)
					//��΂̍���
				{
					ax = (create->pos.x - deleter.colPos.x) / create->size.x / 2;
					bx = create->pos.x - create->size.x / 2 - deleter.size.x / 2;
				}
				else if (deleter.colPos.x > create->pos.x)
					//��΂̉E��
				{
					ax = (deleter.colPos.x - create->pos.x) / create->size.x / 2;
					bx = create->pos.x + create->size.x / 2 - deleter.size.x / 2;
				}

				if (deleter.colPos.y < create->pos.y)
					//��΂̏㑤
				{
					ay = (create->pos.y - deleter.colPos.y) / create->size.y / 2;
					by = create->pos.y - create->size.y / 2 - deleter.size.y / 2 - deleter.size.y / 4;
				}
				else if (deleter.colPos.y > create->pos.y)
					//��΂̉���
				{
					ay = (deleter.colPos.y - create->pos.y) / create->size.y / 2;
					by = create->pos.y + create->size.y / 2 - deleter.size.y / 2 - deleter.size.y / 4;
				}

				if (ax > ay)
				{
					deleter.pos.x = bx;
				}
				else if (ax < ay)
				{
					deleter.pos.y = by;
				}
				else
				{
					deleter.pos.x = create->pos.x - create->size.x / 2 - deleter.size.x / 2;
				}
			}
		}
	}
}

//-----�`�揈��
void DrawDeleter(void)
{
	if (deleter.drawflag == true)
	{
		//�~�܂��Ă�Ƃ� && (�E�����Ă�Ƃ� || �������Ă�Ƃ�)
		if (deleter.walktextureflag == false && deleter.standLRflag == false)
			DrawSpriteLeftTop(deleter.stand_Ltexture, deleter.pos.x, deleter.pos.y,
				deleter.size.x, deleter.size.y, deleter.u, deleter.v, deleter.uw, deleter.vh);
		if (deleter.walktextureflag == false && deleter.standLRflag == true)
			DrawSpriteLeftTop(deleter.stand_Rtexture, deleter.pos.x, deleter.pos.y,
				deleter.size.x, deleter.size.y, deleter.u, deleter.v, deleter.uw, deleter.vh);

		//�����Ă�Ƃ� && (�E�����Ă�Ƃ� || �������Ă�Ƃ�)
		if (deleter.walktextureflag == true && deleter.walkLRflag == false)
			DrawSpriteLeftTop(deleter.walk_Ltexture, deleter.pos.x, deleter.pos.y,
				deleter.size.x, deleter.size.y, deleter.u, deleter.v, deleter.uw, deleter.vh);
		if (deleter.walktextureflag == true && deleter.walkLRflag == true)
			DrawSpriteLeftTop(deleter.walk_Rtexture, deleter.pos.x, deleter.pos.y,
				deleter.size.x, deleter.size.y, deleter.u, deleter.v, deleter.uw, deleter.vh);
	}

	//���񂾂Ƃ�
	if (deleter.drawflag == false)
		DrawSpriteLeftTop(deleter.deathtexture, deleter.pos.x, deleter.pos.y,
			deleter.size.x, deleter.size.y, deleter.u, deleter.v, deleter.uw, deleter.vh);
}

//-----�\���̃|�C���^�擾����
DELETER* GetDeleter(void)
{
	return &deleter;
}