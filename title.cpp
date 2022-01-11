//�^�C�g������ [title.cpp]
#include "title.h"
//
#include "title_bg.h"
#include "title_teamname.h"
#include "title_gamestart.h"
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
	UninitTitleExit();
	UninitTitleSelect();
}

//-----�X�V����
void UpdateTitle(void)
{
	UpdateTitleBG();
	UpdateTitleTeamName();
	UpdateTitleStart();
	UpdateTitleExit();
	UpdateTitleSelect();
}

//-----�`�揈��
void DrawTitle(void)
{
	DrawTitleBG();
	DrawTitleTeamName();
	DrawTitleStart();
	DrawTitleExit();
	DrawTitleSelect();
}