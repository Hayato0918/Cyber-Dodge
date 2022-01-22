//�C�x���g���� [event.cpp]
#include "event.h"
#include "texture.h"
#include "sprite.h"

#include "avatar.h"
#include "dougyousya.h"
#include "floatingfeeling.h"
#include "hujyou.h"
#include "kasoukenkyuukuukan.h"
#include "mined.h"
#include "server_recovery.h"
#include "tosyokann.h"
#include "yomigaeru.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitEvent(void)
{
	InitAvatar();
	InitDougyousya();
	Inite_FloatingFeeling();
	InitHujyou();
	InitKasou();
	InitMined();
	InitServerRecovery();
	InitTosyokann();
	InitYomigaeru();

	return S_OK;
}

//-----�I������
void UninitEvent(void)
{
	UninitYomigaeru();
	UninitTosyokann();
	UninitServerRecovery();
	UninitMined();
	UninitKasou();
	UninitHujyou();
	UninitDougyousya();
	UninitAvatar();
}

//-----�X�V����
void UpdateEvent(void)
{
	UpdateAvatar();
	UpdateDougyousya();
	_FloatingFeeling();
	UpdateHujyou();
	UpdateKasou();
	UpdateMined();
	UpdateServerRecovery();
	UpdateTosyokann();
	UpdateYomigaeru();
}

//-----�`�揈��
void DrawEvent(void)
{
	DrawAvatar();
	DrawDougyousya();
	DrawHujyou();
	DrawKasou();
	DrawMined();
	DrawServerRecovery();
	DrawTosyokann();
	DrawYomigaeru();
}