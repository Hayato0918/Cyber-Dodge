//�^�C�g������ [title.cpp]
#include "title.h"
//
#include "title_bg.h"
#include "title_teamname.h"
#include "title_gamestart.h"
#include "title_continue.h"
#include "title_option.h"
#include "title_exit.h"
#include "title_select.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitTitle(void)
{
	InitTitleBG();
	InitTitleTeamName();
	InitTitleStart();
	InitTitleContinue();
	InitTitleOption();
	InitTitleExit();
	InitTitleSelect();

	return S_OK;
}

//-----�I������
void UninitTitle(void)
{
	UninitTitleBG();
	UninitTitleTeamName();
	UninitTitleStart();
	UninitTitleContinue();
	UninitTitleOption();
	UninitTitleExit();
	UninitTitleSelect();
}

//-----�X�V����
void UpdateTitle(void)
{
	UpdateTitleBG();
	UpdateTitleTeamName();
	UpdateTitleStart();
	UpdateTitleContinue();
	UpdateTitleOption();
	UpdateTitleExit();
	UpdateTitleSelect();
}

//-----�`�揈��
void DrawTitle(void)
{
	DrawTitleBG();
	DrawTitleTeamName();
	DrawTitleStart();
	DrawTitleContinue();
	DrawTitleOption();
	DrawTitleExit();
	DrawTitleSelect();
}