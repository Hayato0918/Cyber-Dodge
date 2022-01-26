//�o�i�[�X�R�A���� [banner_score.cpp]
#include "banner_score.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "map_player.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BANNER_SCORE banner_score[4];
BANNER_SCORENUM banner_scorenum;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBannerScore(void)
{
	PLAYER* player = GetPlayer();
	MAP_PLAYER* map_player = GetMapPlayer();

	banner_scorenum.gold = player->gold;

	if (map_player->UDcount == 0)	//�����l��0
		banner_scorenum.gold = 1000;

	//�ꏊ�A�T�C�Y�Auv����
	for (int i = 0; i < 4; i++)
	{
		banner_score[i].size = D3DXVECTOR2(SCREEN_WIDTH * 0.01875f, SCREEN_HEIGHT * 0.055555f);
		banner_score[i].pos = D3DXVECTOR2(1420.f + i * banner_score[i].size.x, SCREEN_HEIGHT * 0.0055555f);
		banner_score[i].drawflag = true;
	}
	banner_scorenum.texture = LoadTexture("data/TEXTURE/number.png");

	return S_OK;
}

//-----�I������
void UninitBannerScore(void)
{

}

//-----�X�V����
void UpdateBannerScore(void)
{
	PLAYER* player = GetPlayer();
	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->UDcount > 0)
		banner_scorenum.gold = player->gold;

	banner_scorenum.a = banner_scorenum.gold * 0.001f;
	banner_scorenum.b = (banner_scorenum.gold - banner_scorenum.a * 1000) * 0.01f;
	banner_scorenum.c = (banner_scorenum.gold - banner_scorenum.a * 1000 - banner_scorenum.b * 100) * 0.1f;
	banner_scorenum.d = banner_scorenum.gold - banner_scorenum.a * 1000 - banner_scorenum.b * 100 - banner_scorenum.c * 10;

	//gold��1000�̈�
	if (banner_scorenum.a < 5)
	{
		banner_score[0].u = 0.2f * banner_scorenum.a;
		banner_score[0].v = 0.f;
	}
	if (banner_scorenum.a >= 5)
	{
		banner_score[0].u = 0.2f * banner_scorenum.a;
		banner_score[0].v = 0.5f;
	}
	if (banner_scorenum.a <= 0)
		banner_score[0].drawflag = false;
	if (banner_scorenum.a > 0)
		banner_score[0].drawflag = true;
	//gold��100�̈�
	if (banner_scorenum.b < 5)
	{
		banner_score[1].u = 0.2f * banner_scorenum.b;
		banner_score[1].v = 0.f;
	}
	if (banner_scorenum.b >= 5)
	{
		banner_score[1].u = 0.2f * banner_scorenum.b;
		banner_score[1].v = 0.5f;
	}
	if (banner_scorenum.b >= 0)
		banner_score[1].drawflag = true;
	if (banner_scorenum.a <= 0 && banner_scorenum.b <= 0)
		banner_score[1].drawflag = false;
	//gold��10�̈�
	if (banner_scorenum.c < 5)
	{
		banner_score[2].u = 0.2f * banner_scorenum.c;
		banner_score[2].v = 0.f;
	}
	if (banner_scorenum.c >= 5)
	{
		banner_score[2].u = 0.2f * banner_scorenum.c;
		banner_score[2].v = 0.5f;
	}
	if (banner_scorenum.c >= 0)
		banner_score[2].drawflag = true;
	if (banner_scorenum.a <= 0 && banner_scorenum.b <= 0 && banner_scorenum.c <= 0)
		banner_score[2].drawflag = false;
	//gold��1�̈�
	if (banner_scorenum.d < 5)
	{
		banner_score[3].u = 0.2f * banner_scorenum.d;
		banner_score[3].v = 0.f;
	}
	if (banner_scorenum.d >= 5)
	{
		banner_score[3].u = 0.2f * banner_scorenum.d;
		banner_score[3].v = 0.5f;
	}
}

//-----�`�揈��
void DrawBannerScore(void)
{
	//�o�i�[GOLD
	for (int i = 0; i < 4; i++)
	{
		if (banner_score[i].drawflag == true)
			DrawSpriteLeftTop(banner_scorenum.texture, banner_score[i].pos.x, banner_score[i].pos.y, banner_score[i].size.x, banner_score[i].size.y,
				banner_score[i].u, banner_score[i].v, 0.2f, 0.5f);
	}
}