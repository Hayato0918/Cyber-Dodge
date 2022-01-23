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

#include "map_player.h"

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
	MAP_PLAYER* map_player = GetMapPlayer();

	if(map_player->eventcode == 1)
	UpdateAvatar();
	if (map_player->eventcode == 2)
	UpdateDougyousya();
	if (map_player->eventcode == 3)
	_FloatingFeeling();
	if (map_player->eventcode == 4)
	UpdateHujyou();
	if (map_player->eventcode == 5)
	UpdateKasou();
	if (map_player->eventcode == 6)
	UpdateMined();
	if (map_player->eventcode == 7)
	UpdateServerRecovery();
	if (map_player->eventcode == 8)
	UpdateTosyokann();
	if (map_player->eventcode == 9)
	UpdateYomigaeru();
}

//-----�`�揈��
void DrawEvent(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	if (map_player->eventcode == 1)
	DrawAvatar();
	if (map_player->eventcode == 2)
	DrawDougyousya();
	if (map_player->eventcode == 3)
	Drawe_FloatingFeeling();
	if (map_player->eventcode == 4)
	DrawHujyou();
	if (map_player->eventcode == 5)
	DrawKasou();
	if (map_player->eventcode == 6)
	DrawMined();
	if (map_player->eventcode == 7)
	DrawServerRecovery();
	if (map_player->eventcode == 8)
	DrawTosyokann();
	if (map_player->eventcode == 9)
	DrawYomigaeru();
}