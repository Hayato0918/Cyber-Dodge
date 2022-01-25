//�o�i�[�������� [banner_gold.cpp]
#include "banner_gold.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"

#include "player.h"
#include "map_player.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BANNER_GOLD banner_gold[4];
BANNER_GOLDNUM banner_goldnum;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBannerGold(void)
{
	PLAYER* player = GetPlayer();
	MAP_PLAYER* map_player = GetMapPlayer();

	banner_goldnum.gold = player->gold;

	if (map_player->UDcount == 0)	//�����l��200
		banner_goldnum.gold = 0;

	//�ꏊ�A�T�C�Y�Auv����
	for (int i = 0; i < 4; i++)
	{
		banner_gold[i].size = D3DXVECTOR2(SCREEN_WIDTH * 0.01875f, SCREEN_HEIGHT * 0.055555f);
		banner_gold[i].pos = D3DXVECTOR2(SCREEN_WIDTH * 0.5375f + i * banner_gold[i].size.x, SCREEN_HEIGHT * 0.0055555f);
		banner_gold[i].drawflag = true;
	}
	banner_goldnum.texture = LoadTexture("data/TEXTURE/number.png");

	return S_OK;
}

//-----�I������
void UninitBannerGold(void)
{

}

//-----�X�V����
void UpdateBannerGold(void)
{
	PLAYER* player = GetPlayer();
	MAP_PLAYER* map_player = GetMapPlayer();

	if(map_player->UDcount > 0)
	banner_goldnum.gold = player->gold;

	banner_goldnum.a = banner_goldnum.gold * 0.001f;
	banner_goldnum.b = (banner_goldnum.gold - banner_goldnum.a * 1000) * 0.01f;
	banner_goldnum.c = (banner_goldnum.gold - banner_goldnum.a * 1000 - banner_goldnum.b * 100) * 0.1f;
	banner_goldnum.d = banner_goldnum.gold - banner_goldnum.a * 1000 - banner_goldnum.b * 100 - banner_goldnum.c * 10;

	//gold��1000�̈�
	if (banner_goldnum.a < 5)
	{
		banner_gold[0].u = 0.2f * banner_goldnum.a;
		banner_gold[0].v = 0.f;
	}
	if (banner_goldnum.a >= 5)
	{
		banner_gold[0].u = 0.2f * banner_goldnum.a;
		banner_gold[0].v = 0.5f;
	}
	if (banner_goldnum.a <= 0)
		banner_gold[0].drawflag = false;
	if (banner_goldnum.a > 0)
		banner_gold[0].drawflag = true;
	//gold��100�̈�
	if (banner_goldnum.b < 5)
	{
		banner_gold[1].u = 0.2f * banner_goldnum.b;
		banner_gold[1].v = 0.f;
	}
	if (banner_goldnum.b >= 5)
	{
		banner_gold[1].u = 0.2f * banner_goldnum.b;
		banner_gold[1].v = 0.5f;
	}
	if (banner_goldnum.b >= 0)
		banner_gold[1].drawflag = true;
	if (banner_goldnum.a <= 0 && banner_goldnum.b <= 0)
		banner_gold[1].drawflag = false;
	//gold��10�̈�
	if (banner_goldnum.c < 5)
	{
		banner_gold[2].u = 0.2f * banner_goldnum.c;
		banner_gold[2].v = 0.f;
	}
	if (banner_goldnum.c >= 5)
	{
		banner_gold[2].u = 0.2f * banner_goldnum.c;
		banner_gold[2].v = 0.5f;
	}
	if (banner_goldnum.c >= 0)
		banner_gold[2].drawflag = true;
	if (banner_goldnum.a <= 0 && banner_goldnum.b <= 0 && banner_goldnum.c <= 0)
		banner_gold[2].drawflag = false;
	//gold��1�̈�
	if (banner_goldnum.d < 5)
	{
		banner_gold[3].u = 0.2f * banner_goldnum.d;
		banner_gold[3].v = 0.f;
	}
	if (banner_goldnum.d >= 5)
	{
		banner_gold[3].u = 0.2f * banner_goldnum.d;
		banner_gold[3].v = 0.5f;
	}










}

//-----�`�揈��
void DrawBannerGold(void)
{
	//�o�i�[GOLD
	for (int i = 0; i < 4; i++)
	{
		if(banner_gold[i].drawflag == true)
		DrawSpriteLeftTop(banner_goldnum.texture, banner_gold[i].pos.x, banner_gold[i].pos.y, banner_gold[i].size.x, banner_gold[i].size.y,
			banner_gold[i].u, banner_gold[i].v, 0.2f, 0.5f);
	}
}