//���O����_�w�i���� [name_bg.cpp]
#include "name_bg.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "Texture.h"
#include "sprite.h"
#include "sound.h"

//-----�萔��`

//-----�\���̐錾

//-----�v���g�^�C�v�錾
NAME_BG name_bg;

//-----�O���[�o���ϐ��̒�`


//-----�������֐�
HRESULT InitNameBG(void)
{
	name_bg.pos = D3DXVECTOR2(0.f, 0.f);
	name_bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	name_bg.texture = LoadTexture("data/TEXTURE/name/bg.png");

	return S_OK;
}

//-----�I�������֐�
void UninitNameBG(void)
{

}

//-----�X�V����������֐�
void UpdateNameBG(void)
{

}

//-----�`�揈���֐�
void DrawNameBG(void)
{
	DrawSpriteLeftTop(name_bg.texture, name_bg.pos.x, name_bg.pos.y, name_bg.size.x, name_bg.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}