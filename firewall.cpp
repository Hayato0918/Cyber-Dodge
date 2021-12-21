//�t�@�C�A�[�E�H�[������ [firewall.cpp]
#include "firewall.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "scene.h"
#include "fade.h"

#include "player.h"
#include "ball.h"
#include "catch.h"
#include "firewall_animation.h"
#include "firewall_hp.h"
#include "firewallAI.h"
#include "skillrandom.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�
FIREWALL firewall;

//-----����������
HRESULT InitFireWall(void)
{
	firewall.pos = D3DXVECTOR2(800.0f, 320.0f);
	firewall.size = D3DXVECTOR2(256.0f, 256.0f);
	firewall.move = D3DXVECTOR2(2.0f, 2.0f);
	firewall.rotate = 2;

	firewall.atk = 150;
	firewall.def = 50;

	firewall.getskill = false;

	firewall.u = 0.0f;
	firewall.v = 0.0f;
	firewall.uw = 0.5f;
	firewall.vh = 1.0f;
	firewall.drawflag = true;

	firewall.stand_Ltexture = LoadTexture("data/TEXTURE/enemy/stand/orgnl_stand_L.png");
	firewall.stand_Rtexture = LoadTexture("data/TEXTURE/enemy/stand/orgnl_stand_R.png");
	firewall.standtextureflag = true;
	firewall.standLRflag = false;
	firewall.standtexturetime = 0.0f;

	firewall.walk_Ltexture = LoadTexture("data/TEXTURE/enemy/walk/orgnl_walk_L.png");
	firewall.walk_Rtexture = LoadTexture("data/TEXTURE/enemy/walk/orgnl_walk_R.png");
	firewall.walktextureflag = false;
	firewall.walkLRflag = false;
	firewall.walktexturetime = 0.0f;

	firewall.throw_Ltexture = LoadTexture("data/TEXTURE/enemy/throw/orgnl_throw_L.png");
	firewall.throw_Rtexture = LoadTexture("data/TEXTURE/enemy/throw/orgnl_throw_R.png");
	firewall.throwtextureflag = false;
	firewall.throwLRflag = false;
	firewall.throwtexturetime = 0.0f;

	firewall.damage_Ltexture = LoadTexture("data/TEXTURE/enemy/damage/orgnl_damage_L.png");
	firewall.damage_Rtexture = LoadTexture("data/TEXTURE/enemy/damage/orgnl_damage_R.png");
	firewall.damagetextureflag = false;
	firewall.damageLRflag = false;
	firewall.damagetexturetime = 0.0f;

	firewall.deathtexture = LoadTexture("data/TEXTURE/enemy/death/orgnl_death.png");

	return S_OK;
}

//-----�I������
void UninitFireWall(void)
{

}

//-----�X�V����
void UpdateFireWall(void)
{
	BALL* ball = GetBall();
	PLAYER* player = GetPlayer();
	FIREWALLHP* firewall_hp = GetFireWallHp();
	SKILL* skill = GetSkill();

	if (firewall.drawflag == true)
		FireWallAI();

	//-----�R�[�g�O�ɏo�Ȃ�����
	if (firewall.pos.y <= 180 - firewall.size.y * 0.5f)			//��
		firewall.pos.y = 180 - firewall.size.y * 0.5f;
	if (firewall.pos.y >= SCREEN_HEIGHT - firewall.size.y - 15 -120)	//��
		firewall.pos.y = SCREEN_HEIGHT - firewall.size.y - 15 -120;
	if (firewall.pos.x <= SCREEN_WIDTH * 0.5f)								//��
		firewall.pos.x = SCREEN_WIDTH * 0.5f;
	if (firewall.pos.x >= SCREEN_WIDTH - firewall.size.x - 5)								//�E
		firewall.pos.x = SCREEN_WIDTH - firewall.size.x - 5;


	//-----�v���C���[���������{�[�����A�n��,�ǂɓ����炸�G�ɓ���������G�Ƀ_���[�W��^����(�A�E�g����)
	if (ball->enemyhitflag == true)
	{
		if (firewall.pos.x < ball->pos.x + ball->size.x && firewall.pos.x + firewall.size.x > ball->pos.x)
		{
			if (firewall.pos.y < ball->pos.y + ball->size.y && firewall.pos.y + firewall.size.y > ball->pos.y)
			{
				firewall.damagetextureflag = true;
				firewall_hp->gaugesize.x = firewall_hp->gaugesize.x - (player->atk - firewall.def) * 3.2f;
				ball->enemyhitflag = false;
			}
		}
	}

	//HP��0�ɂȂ�����map�ֈړ�����
	if (firewall_hp->gaugesize.x <= 0)
	{
		firewall.drawflag = false;
		if (firewall.getskill == false)
		{
			skill->slot = skill->slot + 1;
			firewall.getskill = true;
		}
		SceneTransition(SCENE_MAP);
	}

	//-----�A�j���[�V��������
	firewall_animation();


}

//-----�`�揈��
void DrawFireWall(void)
{
	if (firewall.drawflag == true)
	{
		//�~�܂��Ă�Ƃ� && (�E�����Ă�Ƃ� || �������Ă�Ƃ�)
		if (firewall.walktextureflag == false && firewall.standLRflag == false)
			DrawSpriteLeftTop(firewall.stand_Ltexture, firewall.pos.x, firewall.pos.y, 
								firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);
		if (firewall.walktextureflag == false && firewall.standLRflag == true)
			DrawSpriteLeftTop(firewall.stand_Rtexture, firewall.pos.x, firewall.pos.y, 
								firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);

		//�����Ă�Ƃ� && (�E�����Ă�Ƃ� || �������Ă�Ƃ�)
		if (firewall.walktextureflag == true && firewall.walkLRflag == false)
			DrawSpriteLeftTop(firewall.walk_Ltexture, firewall.pos.x, firewall.pos.y, 
								firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);
		if (firewall.walktextureflag == true && firewall.walkLRflag == true)
			DrawSpriteLeftTop(firewall.walk_Rtexture, firewall.pos.x, firewall.pos.y, 
								firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);
	}

	//���񂾂Ƃ�
	if (firewall.drawflag == false)
		DrawSpriteLeftTop(firewall.deathtexture, firewall.pos.x, firewall.pos.y, 
								firewall.size.x, firewall.size.y, firewall.u, firewall.v, firewall.uw, firewall.vh);
}

//-----�\���̃|�C���^�擾����
FIREWALL* GetFireWall(void)
{
	return &firewall;
}