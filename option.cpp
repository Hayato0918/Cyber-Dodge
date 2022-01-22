//�ݒ菈�� [option.cpp]
#include "option.h"
//
#include "option_bg.h"
#include "option_select.h"

#include "windowsize.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitOption(void)
{
	InitOptionBG();
	InitOptionSelect();
	InitWindowSize();

	return S_OK;
}

//-----�I������
void UninitOption(void)
{
	UninitOptionBG();
	UninitOptionSelect();
	UninitWindowSize();

}

//-----�X�V����
void UpdateOption(void)
{
	UpdateOptionBG();
	UpdateOptionSelect();
	UpdateWindowSize();

}

//-----�`�揈��
void DrawOption(void)
{
	DrawOptionBG();
	DrawOptionSelect();
	DrawWindowSize();

}