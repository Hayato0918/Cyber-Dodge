//�}�b�v���� [map.cpp]
#include "map.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"

#include "map_bg.h"
#include "map_line.h"
#include "map_point.h"
#include "map_player.h"
#include "map_hack.h"
#include "map_floor.h"
#include "map_save.h"

#include "banner.h"
#include "save.h"

#include "skillrandom.h"

//-----�萔��`

//-----�\���̐錾

//-----�v���g�^�C�v�錾

//-----�O���[�o���ϐ��̒�`


//-----�������֐�
HRESULT InitMap(void)
{
	InitMapBG();
	InitMapLine();
	InitMapPoint();
	InitMapPlayer();
	InitMapHack();
	InitMapFloor();
	InitMapSave();

	InitRandom();

	return S_OK;
}

//-----�I�������֐�
void UninitMap()
{
	UninitMapSave();
	UninitMapFloor();
	UninitMapPoint();
	UninitMapPlayer();
	UninitMapHack();
	UninitMapLine();
	UninitMapBG();
}

//-----�X�V����������֐�
void UpdateMap(void)
{
	UpdateMapBG();
	UpdateMapLine();
	UpdateMapPoint();
	UpdateMapPlayer();
	UpdateMapHack();
	UpdateMapFloor();
	UpdateMapSave();


	if (GetKeyboardTrigger(DIK_3))
		SceneTransition(SCENE_DECKMENU);
}

//-----�`�揈���֐�
void DrawMap(void)
{
	DrawMapBG();
	DrawMapLine();
	DrawMapPoint();
	DrawMapPlayer();
	DrawMapHack();
	DrawMapFloor();
	DrawMapSave();
}