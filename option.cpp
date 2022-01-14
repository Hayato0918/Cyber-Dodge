//�ݒ菈�� [option.cpp]
#include "option.h"
//
#include "option_bg.h"
#include "option_select.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitOption(void)
{
	InitOptionBG();
	InitOptionSelect();

	return S_OK;
}

//-----�I������
void UninitOption(void)
{
	UninitOptionBG();
	UninitOptionSelect();

}

//-----�X�V����
void UpdateOption(void)
{
	UpdateOptionBG();
	UpdateOptionSelect();

}

//-----�`�揈��
void DrawOption(void)
{
	DrawOptionBG();
	DrawOptionSelect();

}