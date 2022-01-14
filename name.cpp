//���O���ߏ��� [name.cpp]
#include "name.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"

#include "name_bg.h"
#include "name_keyboard.h"
#include "name_input.h"
#include "name_select.h"

//-----�萔��`

//-----�\���̐錾

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ��̒�`


//-----�������֐�
HRESULT InitName(void)
{
	InitNameBG();
	InitNameKeyboard();
	InitNameInput();
	InitNameSelect();

	return S_OK;
}

//-----�I�������֐�
void UninitName()
{
	UninitNameBG();
	UninitNameKeyboard();
	UninitNameInput();
	UninitNameSelect();
}

//-----�X�V����������֐�
void UpdateName(void)
{
	UpdateNameBG();
	UpdateNameKeyboard();
	UpdateNameInput();
	UpdateNameSelect();
}

//-----�`�揈���֐�
void DrawName(void)
{
	DrawNameBG();
	DrawNameKeyboard();
	DrawNameInput();
	DrawNameSelect();
}