//�o�i�[�������� [banner_gold.cpp]
#include "banner_gold.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BANNER_GOLD banner_gold[4];
BANNER_GOLDNUM banner_goldnum;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBannerGold(void)
{
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