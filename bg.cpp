//�w�i���� [bg.cpp]
#include "bg.h"
#include "texture.h"
#include "sprite.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
BG bg;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitBG(void)
{
	bg.pos = D3DXVECTOR2(0.0f, 0.0f);
	bg.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	bg.texture = LoadTexture("data/TEXTURE/gym.jpg");

	return S_OK;
}

//-----�I������
void UninitBG(void)
{

}

//-----�X�V����
void UpdateBG(void)
{

}

//-----�`�揈��
void DrawBG(void)
{
	DrawSpriteLeftTop(bg.texture, bg.pos.x, bg.pos.y, bg.size.x, bg.size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}