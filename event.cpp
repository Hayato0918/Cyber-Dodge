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
	UpdateHujyou();
	if (map_player->eventcode == 4)
	UpdateKasou();
	if (map_player->eventcode == 5)
	UpdateMined();
	if (map_player->eventcode == 6)
	UpdateServerRecovery();
	if (map_player->eventcode == 7)
	UpdateTosyokann();
	if (map_player->eventcode == 8)
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
	DrawHujyou();
	if (map_player->eventcode == 4)
	DrawKasou();
	if (map_player->eventcode == 5)
	DrawMined();
	if (map_player->eventcode == 6)
	DrawServerRecovery();
	if (map_player->eventcode == 7)
	DrawTosyokann();
	if (map_player->eventcode == 8)
	DrawYomigaeru();
}