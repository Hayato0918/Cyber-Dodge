//�o�i�[�A�C�R������ [banner_icon.cpp]
#include "banner_icon.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BANNER_ICON banner_icon;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBannerIcon(void)
{
	banner_icon.pos = D3DXVECTOR2(10.0f, 0.0f);
	banner_icon.size = D3DXVECTOR2(60.0f, 60.0f);
	banner_icon.texture = LoadTexture("data/TEXTURE/map_point.png");

	return S_OK;
}

//-----�I������
void UninitBannerIcon(void)
{

}

//-----�X�V����
void UpdateBannerIcon(void)
{

}

//-----�`�揈��
void DrawBannerIcon(void)
{
	//�o�i�[�A�C�R��
	DrawSpriteLeftTop(banner_icon.texture, banner_icon.pos.x, banner_icon.pos.y, banner_icon.size.x, banner_icon.size.y, 0.0f, 0.0f, 0.166f, 1.0f);
}