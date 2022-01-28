//�o�i�[�w�i���� [banner_bg.cpp]
#include "banner_bg.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BANNER_BG banner_bg;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBannerBG(void)
{
	banner_bg.pos = D3DXVECTOR2(0.0f, 0.0f);
	banner_bg.size = D3DXVECTOR2(1600.f, 60.f);
	return S_OK;
}

//-----�I������
void UninitBannerBG(void)
{

}

//-----�X�V����
void UpdateBannerBG(void)
{

}

//-----�`�揈��
void DrawBannerBG(void)
{
	//�o�i�[�w�i
	DrawSpriteLeftTop(banner_bg.texture, banner_bg.pos.x, banner_bg.pos.y, banner_bg.size.x, banner_bg.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

BANNER_BG* GetBannerBG()
{
	return &banner_bg;
}