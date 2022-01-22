//�o�i�[�o�O�Q�[�W���� [banner_bug.cpp]
#include "banner_bug.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"

#include "bugincrease.h"
#include "map_player.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BANNER_BUG banner_bug[3];
BANNER_BUGNUM banner_bugnum;
//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBannerBug(void)
{
	BUG* bug = GetBugIncrease();
	MAP_PLAYER* map_player = GetMapPlayer();

	for (int i = 0; i < 3; i++)
	{
		banner_bug[i].size = D3DXVECTOR2(30.f, 50.f);
		banner_bug[i].pos = D3DXVECTOR2(1130.f + i * 30.f, 5.f);
		banner_bug[i].u = 0.f;
		banner_bug[i].v = 0.f;
		banner_bug[i].drawflag = true;
	}

	banner_bugnum.bugnum = bug->drawnum * 5;
	if (map_player->UDcount == 0)
		banner_bugnum.bugnum = 0;
	banner_bugnum.texture = LoadTexture("data/TEXTURE/number.png");

	return S_OK;
}

//-----�I������
void UninitBannerBug(void)
{

}

//-----�X�V����
void UpdateBannerBug(void)
{
	BUG* bug = GetBugIncrease();
	MAP_PLAYER* map_player = GetMapPlayer();
	
	if (map_player->UDcount > 1)
		banner_bugnum.bugnum = bug->drawnum * 5;


	banner_bugnum.a = banner_bugnum.bugnum * 0.01f;
	banner_bugnum.b = (banner_bugnum.bugnum - banner_bugnum.a * 100) * 0.1f;
	banner_bugnum.c = banner_bugnum.bugnum - banner_bugnum.a * 100 - banner_bugnum.b * 10;

	//HP��100�̈�
	if (banner_bugnum.a < 5)
	{
		banner_bug[0].u = 0.2f * banner_bugnum.a;
		banner_bug[0].v = 0.f;
	}
	if (banner_bugnum.a >= 5)
	{
		banner_bug[0].u = 0.2f * banner_bugnum.a;
		banner_bug[0].v = 0.5f;
	}
	if (banner_bugnum.a <= 0)
		banner_bug[0].drawflag = false;
	if (banner_bugnum.a > 0)
		banner_bug[0].drawflag = true;
	//HP��10�̈�
	if (banner_bugnum.b < 5)
	{
		banner_bug[1].u = 0.2f * banner_bugnum.b;
		banner_bug[1].v = 0.f;
	}
	if (banner_bugnum.b >= 5)
	{
		banner_bug[1].u = 0.2f * banner_bugnum.b;
		banner_bug[1].v = 0.5f;
	}
	if (banner_bugnum.a <= 0 && banner_bugnum.b <= 0)
		banner_bug[1].drawflag = false;
	if (banner_bugnum.b > 0)
		banner_bug[1].drawflag = true;
	//HP��1�̈�
	if (banner_bugnum.c < 5)
	{
		banner_bug[2].u = 0.2f * banner_bugnum.c;
		banner_bug[2].v = 0.f;
	}
	if (banner_bugnum.c >= 5)
	{
		banner_bug[2].u = 0.2f * banner_bugnum.c;
		banner_bug[2].v = 0.5f;
	}

}

//-----�`�揈��
void DrawBannerBug(void)
{
	//�o�i�[�o�O�Q�[�W
	for (int i = 0; i < 3; i++)
	{
		if(banner_bug[i].drawflag == true)
		DrawSpriteLeftTop(banner_bugnum.texture, banner_bug[i].pos.x, banner_bug[i].pos.y, banner_bug[i].size.x, banner_bug[i].size.y,
			banner_bug[i].u, banner_bug[i].v, 0.2f, 0.5f);
	}
}