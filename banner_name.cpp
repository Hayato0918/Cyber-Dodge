//�o�i�[���O���� [banner_name.cpp]
#include "banner_name.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BANNER_NAME banner_name;
//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBannerName(void)
{
	banner_name.pos = D3DXVECTOR2(90.0f, 0.0f);
	banner_name.size = D3DXVECTOR2(280.0f, 60.0f);
	banner_name.texture = LoadTexture("data/TEXTURE/playername.png");

	return S_OK;
}

//-----�I������
void UninitBannerName(void)
{

}

//-----�X�V����
void UpdateBannerName(void)
{

}

//-----�`�揈��
void DrawBannerName(void)
{
	//�o�i�[�l�[��
	DrawSpriteLeftTop(banner_name.texture, banner_name.pos.x, banner_name.pos.y, banner_name.size.x, banner_name.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}