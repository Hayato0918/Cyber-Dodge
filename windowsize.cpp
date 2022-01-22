//�E�B���h�E�T�C�Y���� [windowsize.cpp]
#include "windowsize.h"
//
#include "windowsize_bg.h"
#include "windowsize_select.h"

#include "option_select.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitWindowSize(void)
{
	OPTION_SELECT* option_select = GetOptionSelect();

	if (option_select->count == 0)
	{
		InitWindowSizeBG();
		InitWindowSizeSelect();
	}

	return S_OK;
}

//-----�I������
void UninitWindowSize(void)
{
	OPTION_SELECT* option_select = GetOptionSelect();

	if (option_select->count == 0)
	{
		UninitWindowSizeBG();
		UninitWindowSizeSelect();
	}

}

//-----�X�V����
void UpdateWindowSize(void)
{
	OPTION_SELECT* option_select = GetOptionSelect();

	if (option_select->count == 0)
	{
		UpdateWindowSizeBG();
		UpdateWindowSizeSelect();
	}

}

//-----�`�揈��
void DrawWindowSize(void)
{
	OPTION_SELECT* option_select = GetOptionSelect();

	if (option_select->count == 0)
	{
		DrawWindowSizeBG();
		DrawWindowSizeSelect();
	}

}