//�w�i���� [bg.cpp]
#include "bg.h"
#include "texture.h"
#include "sprite.h"
#include "areaChange.h"

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

	bg.clPos = D3DXVECTOR2(bg.size.x / 2, bg.pos.y + bg.size.y / 2);
	bg.clSize = D3DXVECTOR2(10.0f, bg.size.y);
	//bg.clTexture = LoadTexture("data/TEXTURE/gym_centerline.png");

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
	DrawSpriteColor(bg.clTexture, bg.clPos.x, bg.clPos.y, bg.clSize.x, bg.clSize.y, 0.0f, 0.0f, 1.0f, 1.0f,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
}

BG* GetBG(void)
{
	return &bg;
}

void SetCenterLine(float x)
{
	bg.clPos.x = x;
}