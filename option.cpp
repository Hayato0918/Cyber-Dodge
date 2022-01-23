//�ݒ菈�� [option.cpp]
#include "option.h"
//
#include "option_bg.h"
#include "option_select.h"

#include "windowsize.h"
#include "soundvolume.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitOption(void)
{
	InitOptionBG();
	InitOptionSelect();
	InitWindowSize();
	InitSoundVolume();

	return S_OK;
}

//-----�I������
void UninitOption(void)
{
	UninitOptionBG();
	UninitOptionSelect();
	UninitWindowSize();
	UninitSoundVolume();
}

//-----�X�V����
void UpdateOption(void)
{
	UpdateOptionBG();
	UpdateOptionSelect();
	UpdateWindowSize();
	UpdateSoundVolume();
}

//-----�`�揈��
void DrawOption(void)
{
	DrawOptionBG();
	DrawOptionSelect();
	DrawWindowSize();
	DrawSoundVolume();
}