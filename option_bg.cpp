//�ݒ�_�w�i���� [option_bg.cpp]
#include "option_bg.h"
//
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
OPTION_BG option_bg;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitOptionBG(void)
{
	option_bg.pos = D3DXVECTOR2(0.f, 0.f);
	option_bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	option_bg.texture = LoadTexture("data/TEXTURE/option/option_bg.png");


	return S_OK;
}

//-----�I������
void UninitOptionBG(void)
{

}

//-----�X�V����
void UpdateOptionBG(void)
{

}

//-----�`�揈��
void DrawOptionBG(void)
{
	DrawSpriteLeftTop(option_bg.texture, option_bg.pos.x, option_bg.pos.y, option_bg.size.x, option_bg.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
}