//�^�C�g������ [title.cpp]
#include "title.h"
//
#include "sound.h"
//
#include "title_bg.h"
#include "title_teamname.h"
#include "title_gamestart.h"
#include "title_continue.h"
#include "title_ranking.h"
#include "title_option.h"
#include "title_exit.h"
#include "title_select.h"

#include "map_player.h"

#include "textureload.h"

//-----�}�N����`

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ�

//-----����������
HRESULT InitTitle(void)
{
	MAP_PLAYER* map_player = GetMapPlayer();

	map_player->UDcount = 0;
	map_player->gamecount = 0;
	map_player->floor = 0;

	TextureLoad();
	InitTitleBG();
	InitTitleTeamName();
	InitTitleStart();
	InitTitleContinue();
	InitTitleRanking();
	InitTitleOption();
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
	UninitTitleContinue();
	UninitTitleRanking();
	UninitTitleOption();
	UninitTitleExit();
	UninitTitleSelect();
}

//-----�X�V����
void UpdateTitle(void)
{
	UpdateTitleBG();
	UpdateTitleTeamName();
	UpdateTitleStart();
	UpdateTitleContinue();
	UpdateTitleRanking();
	UpdateTitleOption();
	UpdateTitleExit();
	UpdateTitleSelect();
}

//-----�`�揈��
void DrawTitle(void)
{
	DrawTitleBG();
	DrawTitleTeamName();
	DrawTitleSelect();
	DrawTitleStart();
	DrawTitleContinue();
	DrawTitleRanking();
	DrawTitleOption();
	DrawTitleExit();
}