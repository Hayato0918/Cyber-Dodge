//�o�i�[���O���� [banner_name.cpp]
#include "banner_name.h"
//�V�X�e��.h
#include "texture.h"
#include "sprite.h"

#include "name_input.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BANNER_NAME banner_name[8];
//-----�O���[�o���ϐ�
int banner_nametexture;

//-----����������
HRESULT InitBannerName(void)
{
	NAME_INPUTWARD* name_inputward = GetNameInputWard();

	float bannerwardx = 0.f;
	for (int i = 0; i < 8; i++)
	{
		banner_name[i].pos = D3DXVECTOR2(90.0f + bannerwardx, 0.0f);
		banner_name[i].size = D3DXVECTOR2(35.0f, 60.0f);
		banner_name[i].u = name_inputward[i].u;
		bannerwardx = bannerwardx + 35.f;
	}

	banner_nametexture = LoadTexture("data/TEXTURE/name/ward.png");

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
	NAME_INPUTWARD* name_inputward = GetNameInputWard();

	//�o�i�[�l�[��
	for (int i = 0; i < 8; i++)
	{
		if(name_inputward[i].drawflag == true)
		DrawSpriteLeftTop(banner_nametexture, banner_name[i].pos.x, banner_name[i].pos.y, banner_name[i].size.x, banner_name[i].size.y,
			banner_name[i].u, 0.0f, 0.037037037f, 1.0f);
	}
}