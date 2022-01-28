//�^�C�g���I���{�^������ [title_exit.cpp]
#include "title_exit.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "title_bg.h"
#include "title_select.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
TITLE_EXIT title_exit;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitTitleExit(void)
{
	title_exit.pos = D3DXVECTOR2(1370.f, 810.f);	//1600:900��1270,810
	title_exit.size = D3DXVECTOR2(190.f, 70.f);	//1600:900��380,70

	return S_OK;
}

//-----�I������
void UninitTitleExit(void)
{

}

//-----�X�V����
void UpdateTitleExit(void)
{
	TITLE_SELECT* title_select = GetTitleSelect();
	TITLE_BG* title_bg = GetTitleBG();

	if (PADUSE == 0)
	{
		if (title_select->count == 4 && IsButtonTriggered(0, BUTTON_Y) && title_bg->drawflag == true)
			exit(0);
	}

	if (PADUSE == 1)
	{
		if (title_select->count == 4 && GetKeyboardTrigger(DIK_RETURN) && title_bg->drawflag == true)
			exit(0);
	}
}

//-----�`�揈��
void DrawTitleExit(void)
{
	TITLE_BG* title_bg = GetTitleBG();

	if (title_bg->drawflag == true)
		DrawSpriteLeftTop(title_exit.texture, title_exit.pos.x, title_exit.pos.y, title_exit.size.x, title_exit.size.y,
			0.0f, 0.0f, 1.0f, 1.0f);
}

TITLE_EXIT* GetTitleExit()
{
	return &title_exit;
}