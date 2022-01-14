//�^�C�g���X�^�[�g�{�^������ [title_gamestart.cpp]
#include "title_gamestart.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

#include "title_bg.h"
#include "title_select.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾
TITLE_START title_start;

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitTitleStart(void)
{
	title_start.pos = D3DXVECTOR2(SCREEN_WIDTH * 0.738f, SCREEN_HEIGHT * 0.667f);	//1600:900��1180,600
	title_start.size = D3DXVECTOR2(SCREEN_WIDTH * 0.238f, SCREEN_HEIGHT * 0.078f);	//1600:900��380,70
	title_start.texture = LoadTexture("data/TEXTURE/title/gamestart.png");

	return S_OK;
}

//-----�I������
void UninitTitleStart(void)
{

}

//-----�X�V����
void UpdateTitleStart(void)
{
	TITLE_BG* title_bg = GetTitleBG();
	TITLE_SELECT* title_select = GetTitleSelect();

	if (title_select->count == 0 && GetKeyboardTrigger(DIK_RETURN) && title_bg->drawflag == true)
		SceneTransition(SCENE_NAME);
}

//-----�`�揈��
void DrawTitleStart(void)
{
	TITLE_BG* title_bg = GetTitleBG();

	if(title_bg->drawflag == true)
	DrawSpriteLeftTop(title_start.texture, title_start.pos.x, title_start.pos.y, title_start.size.x, title_start.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);
}

TITLE_START* GetTitleStart()
{
	return &title_start;
}