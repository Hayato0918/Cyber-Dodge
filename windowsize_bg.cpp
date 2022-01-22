//�E�B���h�E�T�C�Y_�w�i���� [windowsize_bg.cpp]
#include "windowsize_bg.h"
//
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
WINDOWSIZE_BG widowsize_bg;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitWindowSizeBG(void)
{
	widowsize_bg.pos = D3DXVECTOR2(400.f, 300.f);
	widowsize_bg.size = D3DXVECTOR2(800.f, 500.f);
	widowsize_bg.texture = LoadTexture("data/TEXTURE/option/windowsize.png");


	return S_OK;
}

//-----�I������
void UninitWindowSizeBG(void)
{

}

//-----�X�V����
void UpdateWindowSizeBG(void)
{

}

//-----�`�揈��
void DrawWindowSizeBG(void)
{
	DrawSpriteLeftTop(widowsize_bg.texture, widowsize_bg.pos.x, widowsize_bg.pos.y, widowsize_bg.size.x, widowsize_bg.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
}