//�^�C�g���X�^�[�g�{�^������ [title_continue.cpp]
#include "title_continue.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "title_bg.h"
#include "title_select.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
TITLE_CONTINUE title_continue;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitTitleContinue(void)
{
	title_continue.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.7563f, SCREEN_HEIGHT * 0.745f);	//1600:900��1210,670
	title_continue.size = D3DXVECTOR2(SCREEN_WIDTH * 0.238f, SCREEN_HEIGHT * 0.078f);	//1600:900��380,70
	title_continue.texture = LoadTexture("data/TEXTURE/title/continue.png");

	return S_OK;
}

//-----�I������
void UninitTitleContinue(void)
{

}

//-----�X�V����
void UpdateTitleContinue(void)
{
	TITLE_BG* title_bg = GetTitleBG();
	TITLE_SELECT* title_select = GetTitleSelect();
}

//-----�`�揈��
void DrawTitleContinue(void)
{
	TITLE_BG* title_bg = GetTitleBG();

	if (title_bg->drawflag == true)
		DrawSpriteLeftTop(title_continue.texture, title_continue.pos.x, title_continue.pos.y, title_continue.size.x, title_continue.size.y,
			0.0f, 0.0f, 1.0f, 1.0f);
}

TITLE_CONTINUE* GetTitleContinue()
{
	return &title_continue;
}