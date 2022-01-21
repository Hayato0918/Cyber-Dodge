//�o�i�[HP���� [banner_hp.cpp]
#include "banner_hp.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"

#include "player_hp.h"
#include "map_player.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BANNER_HP banner_hp[3];
BANNER_HPNUM banner_hpnum;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBannerHp(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();
	PLAYERHP* player_hp = GetPlayerHp();

	//player��HP�o�[�T�C�Y����A�����l������o��
	banner_hpnum.hp = player_hp->gaugesize.x * 0.3125f;
	if (map_player->UDcount == 0)	//�����l��200
		banner_hpnum.hp = 200;

	//�ꏊ�A�T�C�Y�Auv����
	for (int i = 0; i < 3; i++)
	{
		banner_hp[i].size = D3DXVECTOR2(30.0f, 50.0f);
		banner_hp[i].pos = D3DXVECTOR2(470.f + i * banner_hp[i].size.x, 5.0f);
		banner_hp[i].drawflag = true;
	}
	banner_hpnum.texture = LoadTexture("data/TEXTURE/number.png");

	return S_OK;
}

//-----�I������
void UninitBannerHp(void)
{

}

//-----�X�V����
void UpdateBannerHp(void)
{
	PLAYERHP* player_hp = GetPlayerHp();
	MAP_PLAYER* map_player = GetMapPlayer();

	//player��HP�o�[�T�C�Y����A�����l������o��
	if(map_player->UDcount > 1)
	banner_hpnum.hp = player_hp->gaugesize.x * 0.3125f;

	banner_hpnum.a = banner_hpnum.hp * 0.01f;
	banner_hpnum.b = (banner_hpnum.hp - banner_hpnum.a * 100) * 0.1f;
	banner_hpnum.c = banner_hpnum.hp - banner_hpnum.a * 100 - banner_hpnum.b * 10;

	//HP��100�̈�
	if (banner_hpnum.a < 5)
	{
		banner_hp[0].u = 0.2f * banner_hpnum.a;
		banner_hp[0].v = 0.f;
	}
	if (banner_hpnum.a >= 5)
	{
		banner_hp[0].u = 0.2f * banner_hpnum.a;
		banner_hp[0].v = 0.5f;
	}
	if (banner_hpnum.a <= 0)
		banner_hp[0].drawflag = false;
	if (banner_hpnum.a > 0)
		banner_hp[0].drawflag = true;
	//HP��10�̈�
	if (banner_hpnum.b < 5)
	{
		banner_hp[1].u = 0.2f * banner_hpnum.b;
		banner_hp[1].v = 0.f;
	}
	if (banner_hpnum.b >= 5)
	{
		banner_hp[1].u = 0.2f * banner_hpnum.b;
		banner_hp[1].v = 0.5f;
	}
	if (banner_hpnum.a <= 0 && banner_hpnum.b <= 0)
		banner_hp[1].drawflag = false;
	if (banner_hpnum.b > 0)
		banner_hp[1].drawflag = true;
	//HP��1�̈�
	if (banner_hpnum.c < 5)
	{
		banner_hp[2].u = 0.2f * banner_hpnum.c;
		banner_hp[2].v = 0.f;
	}
	if (banner_hpnum.c >= 5)
	{
		banner_hp[2].u = 0.2f * banner_hpnum.c;
		banner_hp[2].v = 0.5f;
	}
}

//-----�`�揈��
void DrawBannerHp(void)
{
	//�o�i�[HP
	for (int i = 0; i < 3; i++)
	{
		if(banner_hp[i].drawflag == true)
		DrawSpriteLeftTop(banner_hpnum.texture, banner_hp[i].pos.x, banner_hp[i].pos.y, banner_hp[i].size.x, banner_hp[i].size.y,
			banner_hp[i].u, banner_hp[i].v, 0.2f, 0.5f);
	}
}