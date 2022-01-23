//�T�E���h�{�����[������ [soundvolume.cpp]
#include "soundvolume.h"
//
#include "soundvolume_bg.h"
#include "soundvolume_select.h"

#include "option_select.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitSoundVolume(void)
{
	InitSoundVolumeBG();
	InitSoundVolumeSelect();

	return S_OK;
}

//-----�I������
void UninitSoundVolume(void)
{
	UninitSoundVolumeBG();
	UninitSoundVolumeSelect();
}

//-----�X�V����
void UpdateSoundVolume(void)
{
	OPTION_SELECT* option_select = GetOptionSelect();

	if (option_select->count == 2)
	{
		UpdateSoundVolumeBG();
		UpdateSoundVolumeSelect();
	}

}

//-----�`�揈��
void DrawSoundVolume(void)
{
	OPTION_SELECT* option_select = GetOptionSelect();

	if (option_select->count == 2)
	{
		DrawSoundVolumeBG();
		DrawSoundVolumeSelect();
	}

}